#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/neto/Documentos/Projeto/include/horario.h"


// Função para salvar os dados dos horários e funcionários em arquivos
void salvarDados(Horario* arvoreHorarios) {
    // Abrir o arquivo para salvar os horários
    FILE* arquivoHorarios = fopen("horarios.txt", "w");
    if (arquivoHorarios == NULL) {
        printf("Erro ao abrir o arquivo para salvar os horários!\n");
    } else {
        salvarHorarios(arvoreHorarios, arquivoHorarios); // Salvar horários na árvore AVL no arquivo
        fclose(arquivoHorarios);
        printf("Horários salvos com sucesso!\n");
    }
}

/// Função para salvar todos os horários em um arquivo
void salvarHorarios(Horario* root, FILE* arquivo) {
    if (root != NULL) {
        salvarHorarios(root->esquerda, arquivo);
        fprintf(arquivo, "Dia %d Hora %d Cliente %s Serviço %s\n", root->diaSemana, root->horario, root->nomeCliente, root->servico);
        salvarHorarios(root->direita, arquivo);
    }
}

// Função para carregar horários de um arquivo
Horario* carregarHorario(Horario* root) {
    FILE* arquivo = fopen("horarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de horários.\n");
        return root;
    }

    int dia, hora;
    char nomeCliente[100];
    char servico[100];

    // Print de depuração
    printf("Carregando horários do arquivo...\n");

    // Lê os horários do arquivo e adiciona na árvore
    while (fscanf(arquivo, "Dia %d Hora %d Cliente %s Serviço %s", &dia, &hora, nomeCliente, servico) == 4) {
        root = adicionarHorario(root, dia, hora, nomeCliente, servico);
    }

    fclose(arquivo);
    return root;
}

// Função para remover um horário específico
Horario* removerHorario(Horario* root, int dia, int hora) {
    if (root == NULL)
        return root;

    // Busca o nó a ser removido
    if (dia < root->diaSemana || (dia == root->diaSemana && hora < root->horario))
        root->esquerda = removerHorario(root->esquerda, dia, hora);
    else if (dia > root->diaSemana || (dia == root->diaSemana && hora > root->horario))
        root->direita = removerHorario(root->direita, dia, hora);
    else {
        // Encontrou o nó a ser removido
        if (root->esquerda == NULL || root->direita == NULL) {
            Horario* temp = root->esquerda ? root->esquerda : root->direita;
            free(root);
            return temp;
        } else {
            // Nó com dois filhos: obter o menor valor na subárvore direita
            Horario* temp = root->direita;
            while (temp->esquerda != NULL)
                temp = temp->esquerda;

            // Copiar o valor do sucessor
            root->diaSemana = temp->diaSemana;
            root->horario = temp->horario;
            strcpy(root->nomeCliente, temp->nomeCliente);
            strcpy(root->servico, temp->servico);

            // Remover o sucessor
            root->direita = removerHorario(root->direita, temp->diaSemana, temp->horario);
        }
    }

    // Balancear a árvore após a remoção
    root = balancearNo(root);

    // Atualizar o arquivo após a remoção
    FILE* arquivo = fopen("horarios.txt", "w");
    salvarHorarios(root, arquivo);
    fclose(arquivo);

    return root;
}

void editarHorario(Horario* root, int dia, int hora) {
    if (root == NULL) {
        printf("Horário não encontrado!\n");
        return;
    }

    // Buscar o horário a ser editado
    if (dia < root->diaSemana || (dia == root->diaSemana && hora < root->horario))
        editarHorario(root->esquerda, dia, hora);
    else if (dia > root->diaSemana || (dia == root->diaSemana && hora > root->horario))
        editarHorario(root->direita, dia, hora);
    else {
        // Encontrou o horário a ser editado
        printf("Horário encontrado! Editando...\n");
        printf("Nome atual: %s, Serviço atual: %s\n", root->nomeCliente, root->servico);
        
        // Solicita novos dados para o horário
        printf("Digite o novo nome do cliente: ");
        scanf(" %[^\n]s", root->nomeCliente);

        printf("Digite o novo serviço: ");
        scanf(" %[^\n]s", root->servico);

        printf("Horário atualizado com sucesso!\n");

        // Salvar alterações no arquivo
        FILE* arquivo = fopen("horarios.txt", "w");
        salvarHorarios(root, arquivo);
        fclose(arquivo);
    }
}

// Função para criar um novo nó AVL com informações do cliente e serviço
Horario* novoHorario(int dia, int hora, const char* nomeCliente, const char* servico) {
    Horario* horario = (Horario*)malloc(sizeof(Horario));
    horario->diaSemana = dia;
    horario->horario = hora;
    strcpy(horario->nomeCliente, nomeCliente);
    strcpy(horario->servico, servico);
    horario->esquerda = NULL;
    horario->direita = NULL;
    horario->altura = 1; // Novo nó é inicialmente uma folha
    return horario;
}

// Função para obter a altura de um nó
int altura(Horario* node) {
    return (node == NULL) ? 0 : node->altura;
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento(Horario* node) {
    return (node == NULL) ? 0 : altura(node->esquerda) - altura(node->direita);
}

// Função para atualizar a altura de um nó
void atualizarAltura(Horario* node) {
    if (node != NULL)
        node->altura = 1 + (altura(node->esquerda) > altura(node->direita) ? altura(node->esquerda) : altura(node->direita));
}

// Função para rotação simples à direita
Horario* rotacaoDireita(Horario* y) {
    Horario* x = y->esquerda;
    Horario* T2 = x->direita;

    // Rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualizar alturas
    atualizarAltura(y);
    atualizarAltura(x);

    return x; // Novo nó raiz
}

// Função para rotação simples à esquerda
Horario* rotacaoEsquerda(Horario* x) {
    Horario* y = x->direita;
    Horario* T2 = y->esquerda;

    // Rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualizar alturas
    atualizarAltura(x);
    atualizarAltura(y);

    return y; // Novo nó raiz
}

// Função para balancear um nó específico
Horario* balancearNo(Horario* node) {
    // Atualizar a altura do nó atual
    atualizarAltura(node);

    // Verificar o fator de balanceamento
    int balance = fatorBalanceamento(node);

    // Se o nó está desbalanceado, aplicar rotações:
    if (balance > 1 && fatorBalanceamento(node->esquerda) >= 0)
        return rotacaoDireita(node);
    if (balance < -1 && fatorBalanceamento(node->direita) <= 0)
        return rotacaoEsquerda(node);
    if (balance > 1 && fatorBalanceamento(node->esquerda) < 0) {
        node->esquerda = rotacaoEsquerda(node->esquerda);
        return rotacaoDireita(node);
    }
    if (balance < -1 && fatorBalanceamento(node->direita) > 0) {
        node->direita = rotacaoDireita(node->direita);
        return rotacaoEsquerda(node);
    }
    return node; // Nó já balanceado
}

// Função para adicionar um novo horário na árvore AVL com nome e serviço
Horario* adicionarHorario(Horario* node, int dia, int hora, const char* nomeCliente, const char* servico) {
    // 1. Inserir como em uma árvore binária de busca normal
    if (node == NULL)
        return novoHorario(dia, hora, nomeCliente, servico);

    if (dia < node->diaSemana || (dia == node->diaSemana && hora < node->horario))
        node->esquerda = adicionarHorario(node->esquerda, dia, hora, nomeCliente, servico);
    else if (dia > node->diaSemana || (dia == node->diaSemana && hora > node->horario))
        node->direita = adicionarHorario(node->direita, dia, hora, nomeCliente, servico);
    else // Se o horário já existir, não faz nada
        return node;

    // 2. Balancear a árvore AVL
    node = balancearNo(node);

    // 3. Salvar a árvore atualizada em um arquivo
   salvarHorarios(node, fopen("horarios.txt", "w"));

    return node;
}

// Função para permitir que o usuário marque um horário
void marcarHorario(Horario** root) {
    int dia, hora;
    char nomeCliente[50], servico[50];

    // Solicita as informações ao usuário
    printf("Digite o dia da semana (0 = Domingo, 1 = Segunda, ..., 6 = Sábado): ");
    scanf("%d", &dia);

    printf("Digite o horário desejado (formato 24h, por exemplo, 14 para 14:00): ");
    scanf("%d", &hora);

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", nomeCliente);  // Lê uma string com espaços

    printf("Digite o serviço desejado: ");
    scanf(" %[^\n]s", servico);  // Lê uma string com espaços

    // Adiciona o horário na árvore AVL
    *root = adicionarHorario(*root, dia, hora, nomeCliente, servico);
    printf("Horário marcado com sucesso para %s às %d:00 no dia %d.\n", nomeCliente, hora, dia);
}


// Função para exibir todos os horários já marcados
void mostrarHorarios(Horario* root) {
    if (root == NULL) {
        return;
    }

    // Percorre a subárvore da esquerda
    mostrarHorarios(root->esquerda);

    // Exibe os dados do nó atual
    printf("Dia %d, Horário: %d:00, Cliente: %s, Serviço: %s\n",
           root->diaSemana, root->horario, root->nomeCliente, root->servico);

    // Percorre a subárvore da direita
    mostrarHorarios(root->direita);
}

// Função para remover um horário com base na entrada do usuário
void removerHorarioUsuario(Horario** root) {
    int dia, hora;
    printf("Digite o dia da semana do horário a ser removido: ");
    scanf("%d", &dia);
    printf("Digite o horário a ser removido (formato 24h): ");
    scanf("%d", &hora);

    *root = removerHorario(*root, dia, hora);
    printf("Horário removido com sucesso!\n");
}

// Função para liberar a memória alocada para a árvore de horários
void liberarHorarios(Horario* root) {
    if (root == NULL) {
        return;
    }

    // Libera a subárvore à esquerda
    liberarHorarios(root->esquerda);

    // Libera a subárvore à direita
    liberarHorarios(root->direita);

    // Libera o nó atual
    free(root);
}
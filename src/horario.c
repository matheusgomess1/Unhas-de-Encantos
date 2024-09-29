#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/neto/Documentos/Projeto/include/horario.h"

// Função para salvar todos os horários em um arquivo
void salvarHorarios(Horario* root, FILE* arquivo) {
    if (root != NULL) {
        salvarHorarios(root->esquerda, arquivo);
        fprintf(arquivo, "Dia %d, Horario: %d:00, Cliente: %s, Serviço: %s\n", 
            root->diaSemana, root->horario, root->nomeCliente, root->servico); // Salva dia e horário no arquivo
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

    while (fscanf(arquivo, "%d %d %s %s", &dia, &hora, nomeCliente, servico) == 4) {
        root = adicionarHorario(root, dia, hora, nomeCliente, servico);
    }

    fclose(arquivo);
    return root;
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/neto/Documentos/Projeto/include/funcionario.h"

// Estrutura para armazenar a heap de funcionários
Funcionario heap[MAX_FUNCIONARIOS];
int totalFuncionarios = 0; // Contador para o número atual de funcionários na heap

// Função para inicializar a heap
void inicializarHeap() {
    totalFuncionarios = 0;
}

// Função para comparar dois funcionários (Min-Heap com base nos cargos)
int compararFuncionarios(Funcionario f1, Funcionario f2) {
    return strcmp(f1.cargo, f2.cargo); // Compara os cargos em ordem alfabética
}

// Função auxiliar para trocar dois elementos na heap
void trocarFuncionarios(int i, int j) {
    Funcionario temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Função para inserir um funcionário na heap
void inserirFuncionario(char nome[], char cargo[]) {
    if (totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Número máximo de funcionários atingido.\n");
        return;
    }

    // Criar um novo funcionário e inseri-lo na heap
    Funcionario novoFuncionario;
    strcpy(novoFuncionario.nome, nome);
    strcpy(novoFuncionario.cargo, cargo);

    heap[totalFuncionarios] = novoFuncionario;
    int i = totalFuncionarios;
    totalFuncionarios++;

    // Realiza o "up-heap" para manter a propriedade de Min-Heap
    while (i > 0 && compararFuncionarios(heap[i], heap[(i - 1) / 2]) < 0) {
        trocarFuncionarios(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// Função para remover o funcionário com o cargo de menor prioridade (raiz da heap)
Funcionario removerFuncionario() {
    if (totalFuncionarios == 0) {
        printf("Nenhum funcionário disponível para remoção.\n");
        Funcionario vazio;
        strcpy(vazio.nome, "");
        strcpy(vazio.cargo, "");
        return vazio;
    }

    Funcionario removido = heap[0];
    heap[0] = heap[totalFuncionarios - 1];
    totalFuncionarios--;

    // Realiza o "down-heap" para manter a propriedade de Min-Heap
    int i = 0;
    while (2 * i + 1 < totalFuncionarios) {
        int menorFilho = 2 * i + 1; // Filho esquerdo
        if (menorFilho + 1 < totalFuncionarios && compararFuncionarios(heap[menorFilho], heap[menorFilho + 1]) > 0) {
            menorFilho++; // Se o filho direito for menor, aponta para ele
        }

        if (compararFuncionarios(heap[i], heap[menorFilho]) > 0) {
            trocarFuncionarios(i, menorFilho);
            i = menorFilho;
        } else {
            break;
        }
    }

    return removido;
}

// Função para mostrar os funcionários (ordem não garantida)
void mostrarFuncionarios() {
    if (totalFuncionarios == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    printf("Funcionários disponíveis:\n");
    for (int i = 0; i < totalFuncionarios; i++) {
        printf("%d. %s - %s\n", i + 1, heap[i].nome, heap[i].cargo);
    }
}

// Função para salvar a heap de funcionários em um arquivo
void salvarFuncionarios() {
    FILE* arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os funcionários!\n");
        return;
    }

    for (int i = 0; i < totalFuncionarios; i++) {
        fprintf(arquivo, "%s %s\n", heap[i].nome, heap[i].cargo);
    }

    fclose(arquivo);
    printf("Funcionários salvos com sucesso!\n");
}

// Função para carregar os funcionários de um arquivo para a heap
void carregarFuncionarios() {
    FILE* arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum funcionário salvo encontrado.\n");
        return;
    }

    totalFuncionarios = 0;
    while (fscanf(arquivo, "%s %s", heap[totalFuncionarios].nome, heap[totalFuncionarios].cargo) != EOF) {
        totalFuncionarios++;
        if (totalFuncionarios >= MAX_FUNCIONARIOS)
            break;
    }

    fclose(arquivo);
    printf("Funcionários carregados com sucesso!\n");
}

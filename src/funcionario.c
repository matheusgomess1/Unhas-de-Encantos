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
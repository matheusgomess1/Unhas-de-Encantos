#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#define MAX_FUNCIONARIOS 10 // Definindo um limite para a quantidade de funcionários

typedef struct {
    char nome[50];
    char cargo[50];
} Funcionario;


void inicializarHeap();
void carregarFuncionarios();
void listarServicos();
void mostrarFuncionarios();
void inserirFuncionario(char nome[], char cargo[]);
Funcionario removerFuncionario();
void salvarFuncionarios();
int compararFuncionarios(Funcionario f1, Funcionario f2);
void trocarFuncionarios(int i, int j);

#endif

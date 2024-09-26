#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10 // Máximo de funcionários

// Definição de estruturas
typedef struct funcionario {
    char nome[50];
    char cargo[50];
} Funcionario;

typedef struct horario {
    int diaSemana;
    int horario;
    int altura;
    struct horario* esquerda;
    struct horario* direita;
} Horario;

// Protótipo da função adicionarHorario
Horario* adicionarHorario(Horario* node, int dia, int hora); 
void salvarHorarios(Horario* root, FILE* arquivo);
void salvarFuncionarios();
Horario* carregarHorarios(Horario* root);
void carregarFuncionarios();
int altura(Horario* N);
int max(int a, int b);
Horario* novoHorario(int dia, int hora);
Horario* rotacaoDireita(Horario* y);
Horario* rotacaoEsquerda(Horario* x);
int getBalance(Horario* N);
int verificarHorario(Horario* node, int dia, int hora);
void mostrarHorarios(Horario* root);
void listarServicos();
void marcarHorario(Horario** root);
void cadastrarFuncionario();
void profissionaisDisponiveis();
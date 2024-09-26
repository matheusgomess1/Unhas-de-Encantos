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
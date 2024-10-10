#ifndef SERVICO_H
#define SERVICO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INSUMOS 5
#define NUM_SERVICOS 5

// Definição da estrutura do serviço
typedef struct {
    int id;
    char nomeServico[30];
    char insumos[MAX_INSUMOS][30];  // Lista de insumos para cada serviço
    int numInsumos;                 // Número de insumos no serviço
} TabelaHash;

// Funções do TAD servico
void inicializarTabelaHash(TabelaHash tabela[]);
void listarServicos(TabelaHash tabela[]);
void listarInsumosPorServico(TabelaHash tabela[], int idServico);
void bemVindo();

#endif

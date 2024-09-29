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
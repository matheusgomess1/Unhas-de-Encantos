#ifndef HORARIO_H
#define HORARIO_H

// Definição do nó de um horário para a árvore AVL
typedef struct Horario {
    int diaSemana;
    int horario;
    char nomeCliente[100];
    char servico[100];
    struct Horario* esquerda;
    struct Horario* direita;
    int altura;
} Horario;

Horario* carregarHorario(Horario* root);
Horario* adicionarHorario(Horario* node, int dia, int hora, const char* nomeCliente, const char* servico);
void mostrarHorarios(Horario* root);
//void salvarHorariosAux(Horario* root, FILE* arquivo);
void salvarHorarios(Horario* root, FILE* nomeArquivo);// Alterar para aceitar FILE*

// Função para criar um novo horário
Horario* novoHorario(int dia, int hora, const char* nomeCliente, const char* servico);

// Função para adicionar um novo horário na árvore AVL
//Horario* adicionarHorario(Horario* node, int dia, int hora, const char* nomeCliente, const char* servico);

// Função para exibir todos os horários armazenados



// Função para marcar um novo horário na árvore
void marcarHorario(Horario** root);






#endif

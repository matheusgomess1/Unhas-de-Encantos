#ifndef HORARIO_H
#define HORARIO_H

// Estrutura para armazenar um horário e informações relacionadas
typedef struct horario {
    int diaSemana;             // Dia da semana (0 = Domingo, ..., 6 = Sábado)
    int horario;               // Horário (formato 24h, por exemplo, 14 para 14:00)
    char nomeCliente[100];     // Nome do cliente associado ao horário
    char servico[100];         // Tipo de serviço agendado
    struct horario* esquerda;  // Ponteiro para o nó esquerdo (subárvore esquerda)
    struct horario* direita;   // Ponteiro para o nó direito (subárvore direita)
    int altura;                // Altura do nó na árvore AVL
} Horario;

// Função para criar um novo horário
Horario* novoHorario(int dia, int hora, const char* nomeCliente, const char* servico);

// Função para carregar horários a partir de um arquivo
Horario* carregarHorario(Horario* root);

// Função para adicionar um horário à árvore AVL
Horario* adicionarHorario(Horario* node, int dia, int hora, const char* nomeCliente, const char* servico);

// Função para editar um horário existente
void editarHorario(Horario* root, int dia, int hora);

// Função para remover um horário específico da árvore AVL
Horario* removerHorario(Horario* root, int dia, int hora);

// Função auxiliar para o usuário remover um horário
void removerHorarioUsuario(Horario** root);

// Função para balancear a árvore após a inserção ou remoção de um nó
Horario* balancearNo(Horario* node);

// Função para exibir todos os horários já marcados
void mostrarHorarios(Horario* root);

// Função para salvar todos os horários em um arquivo
void salvarHorarios(Horario* root, FILE* arquivo);

// Função para marcar um novo horário (solicita informações ao usuário)
void marcarHorario(Horario** root);

// Funções de rotação (usadas para balanceamento AVL)
Horario* rotacaoDireita(Horario* y);
Horario* rotacaoEsquerda(Horario* x);

// Função para obter a altura de um nó AVL
int altura(Horario* node);

// Função para calcular o fator de balanceamento de um nó AVL
int fatorBalanceamento(Horario* node);

// Função para atualizar a altura de um nó AVL
void atualizarAltura(Horario* node);

// Função para liberar a memória alocada para a árvore de horários
void liberarHorarios(Horario* root);

// Função para salvar os dados dos horários e funcionários em arquivos
void salvarDados(Horario* arvoreHorarios);

#endif

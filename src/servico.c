#include "/home/neto/Documentos/Projeto/include/servico.h"

// Função para inicializar a tabela hash com insumos
void inicializarTabelaHash(TabelaHash tabela[]) {
    tabela[0] = (TabelaHash){1, "Manicure", {"Alicate", "Lixa", "Esmalte", "Base"}, 4};
    tabela[1] = (TabelaHash){2, "Pedicure", {"Lixa", "Creme Esfoliante", "Espátula", "Hidratante"}, 4};
    tabela[2] = (TabelaHash){3, "Spa das Mãos", {"Creme Hidratante", "Máscara para as Mãos", "Óleo Essencial"}, 3};
    tabela[3] = (TabelaHash){4, "Alongamento de Unhas", {"Tips", "Gel", "Lixa Elétrica"}, 3};
    tabela[4] = (TabelaHash){5, "Nail Art", {"Pincéis", "Pedrinhas", "Adesivos"}, 3};
}

// Função para listar os serviços e perguntar se o usuário quer ver os insumos
void listarServicos(TabelaHash tabela[]) {
    printf("\n===== LISTA DE SERVIÇOS =====\n");
    for (int i = 0; i < NUM_SERVICOS; i++) {
        printf("%d - %s\n", tabela[i].id, tabela[i].nomeServico);
    }
    printf("==============================\n");

    // Pergunta ao usuário se ele deseja ver os insumos de algum serviço
    char escolha;
    printf("Você deseja ver os insumos de algum serviço? (s/n): ");
    scanf(" %c", &escolha);  // Espaço antes de %c para ignorar qualquer caractere residual no buffer

    if (escolha == 's' || escolha == 'S') {
        int idServico;
        printf("Digite o ID do serviço para ver os insumos: ");
        if (scanf("%d", &idServico) == 1) {
            listarInsumosPorServico(tabela, idServico);
        } else {
            printf("ID inválido. Por favor, tente novamente.\n");
        }
    }
}
#include "/home/neto/Documentos/Projeto/include/servico.h"

// Função para inicializar a tabela hash com insumos
void inicializarTabelaHash(TabelaHash tabela[]) {
    tabela[0] = (TabelaHash){1, "Manicure", {"Alicate", "Lixa", "Esmalte", "Base"}, 4};
    tabela[1] = (TabelaHash){2, "Pedicure", {"Lixa", "Creme Esfoliante", "Espátula", "Hidratante"}, 4};
    tabela[2] = (TabelaHash){3, "Spa das Mãos", {"Creme Hidratante", "Máscara para as Mãos", "Óleo Essencial"}, 3};
    tabela[3] = (TabelaHash){4, "Alongamento de Unhas", {"Tips", "Gel", "Lixa Elétrica"}, 3};
    tabela[4] = (TabelaHash){5, "Nail Art", {"Pincéis", "Pedrinhas", "Adesivos"}, 3};
}

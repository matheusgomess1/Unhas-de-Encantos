#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/neto/Documentos/Projeto/include/funcionario.h"
#include "/home/neto/Documentos/Projeto/include/horario.h"
#include "/home/neto/Documentos/Projeto/include/servico.h"

// Função principal para executar o programa
int main() {
   
    bemVindo();

    // Definindo a tabela hash para armazenar os serviços e seus insumos
    TabelaHash tabela[NUM_SERVICOS];

    // Inicializando a tabela com os dados dos serviços
    inicializarTabelaHash(tabela);
    
    Horario* arvoreHorarios = NULL; // Ponteiro para a raiz da árvore AVL de horários
    char opcaoStr[10];  // String para ler a opção do usuário
    int opcao = 0;

    // Inicializa a heap de funcionários e carrega dados de arquivo, se houver
    carregarFuncionarios();

    arvoreHorarios = carregarHorario(arvoreHorarios);

    // Verificar se a árvore está carregada corretamente
    if (arvoreHorarios == NULL) {
        printf("Nenhum horário encontrado.\n");
    } else {
        printf("Árvore de horários carregada com sucesso!\n");
    }
    getchar();

    do {
        // Exibe o menu principal
        system("clear");
        printf("\n============= MENU =============\n");
        printf("1 - Marcar horário\n");
        printf("2 - Mostrar horários\n");
        printf("3 - Editar horário\n");
        printf("4 - Remover horário\n");
        printf("5 - Serviços\n");
        printf("6 - Profissionais disponíveis\n");
        printf("7 - Cadastrar novo funcionário\n");
        printf("8 - Remover funcionário\n");
        printf("9 - Sair\n");
        printf("================================\n");
        printf("Escolha uma opção: ");
        scanf("%s", opcaoStr);
        system("clear");

        // Tenta converter a string para um número inteiro
        if (sscanf(opcaoStr, "%d", &opcao) != 1) {
            printf("Opção inválida, tente novamente.\n");
            system("pause");           
            continue;  // Reinicia o loop para exibir o menu novamente
        }
        

        // Executa a função correspondente à opção escolhida
        switch (opcao) {
            case 1: {
                // Marcar horário com nome do cliente e serviço
                getchar();
                marcarHorario(&arvoreHorarios);
                salvarDados(arvoreHorarios);
                getchar();
                break;
            }
            case 2:{
                getchar();
            if (arvoreHorarios == NULL) {
                printf("Nenhum horário encontrado.\n");
                }
            else{
                 mostrarHorarios(arvoreHorarios);
                }
                getchar();
                break;
            }
            case 3: {
                // Editar um horário existente
                getchar();
                int dia, hora;
                printf("Digite o dia da semana do horário a ser editado (1-7): ");
                scanf("%d", &dia);
                printf("Digite a hora do horário a ser editado (formato 24h): ");
                scanf("%d", &hora);
                editarHorario(arvoreHorarios, dia, hora);
                salvarDados(arvoreHorarios);
                getchar();
                break;
            }
            case 4:{
                // Remover um horário específico
                getchar();
                removerHorarioUsuario(&arvoreHorarios);
                salvarDados(arvoreHorarios);
                getchar();
                break;
            }
            case 5:{
                getchar();
                listarServicos(tabela);
                break;
            }
            case 6:{
                getchar();
                mostrarFuncionarios();
                getchar();
                break;
            }
            case 7: {
                getchar();
                char nome[50], cargo[50];
                printf("Digite o nome do novo funcionário: ");
                scanf("%s", nome);
                printf("Digite o cargo do novo funcionário: ");
                scanf("%s", cargo);
                inserirFuncionario(nome, cargo);
                printf("Funcionário cadastrado com sucesso.\n");
                salvarFuncionarios();
                getchar();
                break;
            }
            case 8: {
                getchar();
                Funcionario removido = removerFuncionario();
                if (strcmp(removido.nome, "") != 0) {
                    printf("Funcionário removido: %s - %s\n", removido.nome, removido.cargo);
                }
                salvarFuncionarios();
                getchar();
                break;
            }
            case 9:{
                int confirmacao;
                printf("Deseja sair do sistema?\n");
                printf("[1] - SIM \n[2] - NÃO\n");
                printf("\n>>> ");
                scanf("%d", &confirmacao);
                if (confirmacao == 1) {
                    system("clear");
                    printf("\n\n==========================================");
                    printf("\n     OBRIGADO POR USAR NOSSO SISTEMA!!       ");
                    printf("\n==========================================\n\n");
                    exit(0);
                }
                break;
            }
            default:
                printf("Opção inválida, tente novamente.\n");
                getchar();
        }
    } while (opcao != 9);
    return opcao;

    liberarHorarios(arvoreHorarios); // Libera a memória alocada para a árvore de horários
    return 0;
}
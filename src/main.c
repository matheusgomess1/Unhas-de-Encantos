#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/neto/Documentos/Projeto/include/funcionario.h"
#include "/home/neto/Documentos/Projeto/include/horario.h"

// Função principal para executar o programa
int main() {
    Horario* arvoreHorarios = NULL; // Ponteiro para a raiz da árvore AVL de horários
    int opcao;

    // Inicializa a heap de funcionários e carrega dados de arquivo, se houver

    carregarFuncionarios();
    arvoreHorarios = carregarHorario(arvoreHorarios);

    do {
        // Exibe o menu principal
        printf("\n===== MENU =====\n");
        printf("1 - Marcar horário\n");
        printf("2 - Mostrar horários\n");
        printf("3 - Serviços\n");
        printf("4 - Profissionais disponíveis\n");
        printf("5 - Cadastrar novo funcionário\n");
        printf("6 - Remover funcionário\n");
        printf("7 - Salvar dados\n");
        printf("8 - Sair\n");
        printf("================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Executa a função correspondente à opção escolhida
        switch (opcao) {
            case 1: {
                // Marcar horário com nome do cliente e serviço
                int dia, hora;
                char nomeCliente[100], servico[100];
                printf("Digite o dia da semana (1-7): ");
                scanf("%d", &dia);
                printf("Digite a hora desejada (formato 24h): ");
                scanf("%d", &hora);
                printf("Digite o nome do cliente: ");
                scanf("%s", nomeCliente);
                printf("Digite o serviço desejado: ");
                scanf("%s", servico);

                arvoreHorarios = adicionarHorario(arvoreHorarios, dia, hora, nomeCliente, servico);
                printf("Horário marcado com sucesso para %s para o serviço %s no dia %d às %d:00.\n", nomeCliente, servico, dia, hora);
                break;
            }
            case 2:
                mostrarHorarios(arvoreHorarios);
                break;
            case 3:
                listarServicos();
                break;
            case 4:
                mostrarFuncionarios();
                break;
            case 5: {
                char nome[50], cargo[50];
                printf("Digite o nome do novo funcionário: ");
                scanf("%s", nome);
                printf("Digite o cargo do novo funcionário: ");
                scanf("%s", cargo);
                inserirFuncionario(nome, cargo);
                printf("Funcionário cadastrado com sucesso.\n");
                break;
            }
            case 6: {
                Funcionario removido = removerFuncionario();
                if (strcmp(removido.nome, "") != 0) {
                    printf("Funcionário removido: %s - %s\n", removido.nome, removido.cargo);
                }
                break;
            }
            case 7: {
                FILE* arquivoHorarios = fopen("horarios.txt", "w");
                if (arquivoHorarios == NULL) {
                    printf("Erro ao abrir o arquivo para salvar os horários!\n");
                } else {
                    salvarHorarios(arvoreHorarios, arquivoHorarios);
                    fclose(arquivoHorarios);
                    printf("Horários salvos com sucesso!\n");
                }
                salvarFuncionarios();
                break;
            }
            case 8:
                printf("Volte sempre!\n");
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (opcao != 8);

    //liberarHorarios(arvoreHorarios);
    return 0;
}
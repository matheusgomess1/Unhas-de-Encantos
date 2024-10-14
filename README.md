

# Unhas-de-Encanto.


### Requisitos para o projeto:

  * Manicure básica e completa
  
  * Pedicure básica e completa
  
  * Aplicação de unhas postiças, em gel ou acrílico
  
  * Decoração de unhas (nail art)

  * Tratamento de unhas e cutículas

# Linguagem utilizada
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="110px"/>


# sobre o projeto:

O projeto "Unhas de Encanto" tem como objetivo desenvolver um sistema de gerenciamento completo para salões de beleza especializados em manicure e pedicure. Focado em otimizar as operações diárias do salão, o sistema oferece uma solução eficiente para o controle de dados de clientes e profissionais, facilitando a manutenção de registros precisos e organizados. O sistema permitirá o agendamento de horários, o gerenciamento de serviços oferecidos e o controle de estoque de produtos. Além disso, será possível cadastrar e atualizar informações de clientes, funcionários e serviços, garantindo que o salão funcione de maneira integrada e eficiente. Com o "Unhas de Encanto", o fluxo de trabalho será otimizado, permitindo que o salão gerencie de forma centralizada o atendimento aos clientes, os serviços prestados e a equipe de profissionais, tudo isso visando proporcionar uma experiência de alta qualidade e melhorar a gestão interna.

## Funcionalidades do projeto:

Cadastro de Clientes e Profissionais: Permite o registro de clientes e profissionais no sistema, incluindo dados pessoais, especialidades de serviços oferecidos e horários de disponibilidade.

Edição de Informações: Facilita a atualização dos dados cadastrais dos clientes e profissionais, assegurando que as informações estejam sempre corretas e atualizadas.

Remoção de Registros: Oferece a opção de excluir cadastros do sistema, seja de clientes que optaram por outro salão ou profissionais que não fazem mais parte da equipe.

Consulta e Gestão de Dados: Proporciona uma interface intuitiva para visualizar e gerenciar as informações registradas, facilitando o acesso a dados importantes para a administração do salão.

Busca de Clientes: Implementa uma funcionalidade eficiente de busca para localizar rapidamente o cadastro de clientes utilizando o nome como critério de pesquisa.

## Preve resumo sobre as funções:
#### Funcionarios:
  
O arquivo de gerenciamento de funcionários define uma estrutura para armazenar informações básicas dos funcionários, como nome e cargo, limitados a 10 funcionários.

Principais funções:

* inicializarHeap(): Prepara a estrutura de dados para gerenciar os funcionários.
* carregarFuncionarios(): Carrega dados dos funcionários de um arquivo.
* mostrarFuncionarios(): Exibe os funcionários registrados.
* inserirFuncionario(): Adiciona um novo funcionário à estrutura.
* removerFuncionario(): Remove e retorna um funcionário.
* salvarFuncionarios(): Salva os funcionários em um arquivo.
* compararFuncionarios(): Compara dois funcionários.
* trocarFuncionarios(): Troca a posição de dois funcionários na estrutura.
* Essas funções facilitam o gerenciamento e organização de funcionários.

#### Horarios:

  O arquivo de gerenciamento de horários define uma estrutura e funções para gerenciar um sistema de agendamento de serviços usando uma árvore AVL. A estrutura Horario armazena informações como o dia da semana, horário, nome do cliente, serviço agendado e ponteiros para a subárvore esquerda e direita, além da altura do nó para manter a árvore balanceada.

Principais funções:

* novoHorario(): Cria um novo horário.
* carregarHorario(): Carrega os horários de um arquivo.
* adicionarHorario(): Insere um novo horário na árvore AVL.
* editarHorario(): Edita um horário já existente.
* removerHorario(): Remove um horário específico da árvore.
* balancearNo(): Mantém a árvore balanceada após inserção ou remoção.
* mostrarHorarios(): Exibe todos os horários agendados.
* salvarHorarios(): Salva os horários em um arquivo.
* marcarHorario(): Solicita informações ao usuário para agendar um novo horário.
* rotacaoDireita() / rotacaoEsquerda(): Funções de rotação para balancear a árvore.
* altura(), fatorBalanceamento(), atualizarAltura(): Funções auxiliares para manter a árvore AVL balanceada.
* liberarHorarios(): Libera a memória alocada para a árvore de horários.

#### Serviços:

O arquivo de serviços define a estrutura TabelaHash, que armazena informações sobre serviços e seus insumos. Cada serviço tem um id, um nome, uma lista de até 5 insumos, e o número total de insumos usados.

Principais funções:

* inicializarTabelaHash(): Inicializa a tabela de serviços.
* listarServicos(): Exibe a lista de serviços disponíveis.
* listarInsumosPorServico(): Mostra os insumos associados a um serviço específico, identificado por seu ID.
* bemVindo(): Provavelmente exibe uma mensagem de boas-vindas.

Essas funções ajudam a organizar e gerenciar os serviços e seus insumos de forma eficiente.


#### Para rodar o projeto "Unhas de Encanto" na sua máquina, siga os passos abaixo:
Clonar o repositório: Baixe o projeto para sua máquina local usando o comando:

    Git clone https://github.com/matheusgomess1/Unhas-de-Encanto.git

#### Para executar, garanta que você tenha um compilador C devidamente instalado no seu computador. Em seguida, navegue até o diretório onde o projeto está localizado. Você pode fazer isso utilizando o comando `cd`.

Ao entrar no terminal de comandos utilizer esse comando:

    gcc main.c -o main && ./main


## Desenvolvedores 👨‍💻👨‍💻

- [Samuel Saturno](https://github.com/Samuel-Saturno)
- [Matheus Gomes](https://github.com/matheusgomess1)
- [Antonio Neto](https://github.com/antonioneto2)
  











  

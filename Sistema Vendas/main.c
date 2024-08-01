#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// FUNÇÃO: Inicialização
int main() {
    setlocale(LC_ALL, "Portuguese");

    if (autenticarUsuario()) {
        exibirMenu();
    }

    return 0;
}



//*****************FUNÇÕES GLOBAIS*****************//
// FUNÇÃO: Limpar console
void limparConsole() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}



// FUNÇÃO: Limpar buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
//*****************FUNÇÕES GLOBAIS*****************//



// FUNÇÃO: Autenticação de usuário
int autenticarUsuario() {

    char nomeUsuario[100];
    char senhaUsuario[100];

    while (1) {
        system("color 07");

        printf("\n---------------------------------------------\n");
        printf("\t\tMUSEU NOME\n");
        printf("---------------------------------------------\n\n");
        printf(" SISTEMA DE CADASTRO E VENDA\n\n");
        printf("---------------------------------------------\n\n");
        printf("Insira seu nome e senha para continuar:\n\n");

        printf(" Nome de Usuário: ");
        scanf("%s", nomeUsuario);

        printf(" Senha: ");
        scanf("%s", senhaUsuario);

        FILE *arquivoUsuarios;
        arquivoUsuarios = fopen("usuarios.csv", "r");

        if (arquivoUsuarios == NULL) {
            printf("Erro ao abrir o arquivo de usuários.\n");
            return 0;  // Autenticação falhou
        }

        char linha[256];
        int autenticado = 0;

        while (fgets(linha, sizeof(linha), arquivoUsuarios) != NULL) {
            char nomeArquivo[100];
            char senhaArquivo[100];
            sscanf(linha, "%[^,],%s", nomeArquivo, senhaArquivo);

            if (strcmp(nomeArquivo, nomeUsuario) == 0 && strcmp(senhaArquivo, senhaUsuario) == 0) {
                autenticado = 1;
                break;
            }
        }

        fclose(arquivoUsuarios);

        if (autenticado) {
            return 1;  // Autenticação bem-sucedida

        } else {
            printf("Nome de usuário ou senha incorretos. Pressione ENTER e tente novamente.\n");
            limparBuffer();
            getchar(); // Espera o usuário pressionar qualquer tecla
            limparConsole(); // Limpa o console
        }
    }
}



//*****************MENU PRINCIPAL*****************//
void exibirMenu() {
    int opcao;
    system("color F4");
    limparConsole();

    while (1) {
        printf("\n---------------------------------------------\n");
        printf("\t\tMUSEU NOME\n");
        printf("---------------------------------------------\n\n");
        printf(" Seja bem-vindo(a)\n\n");
        printf("---------------------------------------------\n\n");
        printf(" Selecione uma das opções abaixo para continuar:\n\n");
        printf(" 1. Vendas\n");
        printf(" 2. Consultas\n");
        printf(" 3. Validação\n");
        printf(" 4. Sair da conta\n\n\n\n");
        printf(" Digite o número da opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarVenda();// Chama a função "realizarVenda".
                break;
            case 2:
                realizarConsulta();// Chama a função "realizarConsulta".
                break;
            case 3:
                validarIngresso();// Chama a função "validarIngresso".
                break;
            case 4:
                printf("Você está saindo da conta. Pressione ENTER para confirmar.\n");
                limparBuffer();
                getchar(); // Espera o usuário pressionar Enter
                limparConsole();
                autenticarUsuario(); // Volta para a função de autenticação
                break;
            default:
                printf("Opção inválida. Tente novamente (ENTER)");
                limparBuffer();
                getchar(); // Espera o usuário pressionar qualquer tecla
                limparConsole();
        }
    }
}
//*****************MENU PRINCIPAL*****************//



//*****************1. VENDAS*****************//
// FUNÇÃO: Calcular idade
int calcularIdade(const char *dataNascimento) {
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;

    // Extrair os valores do dia, mês e ano da data de nascimento
    sscanf(dataNascimento, "%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);

    // Obter a data atual
    time_t t;
    struct tm *dataAtual;
    time(&t);
    dataAtual = localtime(&t);

    diaAtual = dataAtual->tm_mday;
    mesAtual = dataAtual->tm_mon + 1;
    anoAtual = dataAtual->tm_year + 1900;

    // Calcular a idade
    int idade = anoAtual - anoNascimento;

    // Verificar se o aniversário já ocorreu neste ano
    if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
        idade--;
    }

    return idade;
}



// Estrutura de dados do comprador
struct Comprador {
    char nome[100];
    char documento[20];
    char documentoEstudante[20];
    char telefone[20];
    char dataNascimento[20];
    int tipoIngresso;
};



// FUNÇÃO: Solicitar dados do comprador
void solicitarDadosComprador(struct Comprador *comprador) {
    printf(" Nome: ");
    limparBuffer();
    fgets(comprador->nome, sizeof(comprador->nome), stdin);
    size_t len = strlen(comprador->nome);
    if (len > 0 && comprador->nome[len - 1] == '\n') {
        comprador->nome[len - 1] = '\0'; // Remove o '\n' substituindo por '\0'
}

    printf("\n Documento: ");
    scanf("%s", comprador->documento);

    printf("\n Telefone: ");
    scanf("%s", comprador->telefone);

    printf("\n Data de Nascimento (DD/MM/AAAA): ");
    scanf("%s", comprador->dataNascimento);

    int idade = calcularIdade(comprador->dataNascimento);
    printf("\n Idade: %d anos\n", idade);
}



double calcularPrecoIngresso(tipoIngresso) {

    #define PRECO_INTEIRA 30.00
    #define PRECO_MEIA_ESTUDANTE 15.00
    #define PRECO_ESPECIAL_CRIANCA 10.00
    #define PRECO_ESPECIAL_IDOSO 00.00
    #define PRECO_MEIA_ITAUCARD 15.00

    double preco;

    switch (tipoIngresso) {
        case 1:
            preco = PRECO_INTEIRA;
            break;
        case 2:
            preco = PRECO_MEIA_ESTUDANTE;
            break;
        case 3:
            preco = PRECO_ESPECIAL_CRIANCA;
            break;
        case 4:
            preco = PRECO_ESPECIAL_IDOSO;
            break;
        case 5:
            preco = PRECO_MEIA_ITAUCARD;
            break;
        default:
            break;
    }

    return preco;
}



void registrarIngresso(int numeroVenda, struct Comprador comprador, int tipoIngresso) {
    double precoIngresso = calcularPrecoIngresso(tipoIngresso);

    FILE *arquivoIngressos;
    arquivoIngressos = fopen("ingressos.csv", "a");

    if (arquivoIngressos == NULL) {
        printf("Erro ao abrir o arquivo de ingressos.\n");
        return;
    }

    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    char dataHoraEmissao[20];
    strftime(dataHoraEmissao, sizeof(dataHoraEmissao), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(arquivoIngressos, "%s; %d; %s; %s; %d; %.2f\n", dataHoraEmissao, numeroVenda, comprador.nome, comprador.documento, tipoIngresso, precoIngresso);

    fclose(arquivoIngressos);
}



//FUNÇÃO: Adicionar cabeçalho
void imprimirCabecalho() {
    system("cls");
    printf("\n---------------------------------------------\n");
    printf("\t\tMUSEU NOME\n");
    printf("---------------------------------------------\n\n");
    printf(" EMISSÃO DE INGRESSOS\n\n");
    printf("---------------------------------------------\n\n\n");
}



// FUNÇÃO: Venda
void realizarVenda() {
    int quantidade;
    int tipoIngresso;
    int numeroVenda = 0;
    double precoTotal = 0.0;
    double precoIngresso;
    char opcaoSN;

    // Solicitar os dados da venda
    limparConsole();
    imprimirCabecalho();
    printf(" Informe a quantidade de ingressos: ");
    scanf("%d", &quantidade);

    // Array de compradores
    struct Comprador compradores[quantidade];

    for (int i = 0; i < quantidade; i++) {

        numeroVenda = rand();

        imprimirCabecalho();
        printf(" Dados do Comprador %d:\n\n", i + 1);

        //Chama a função com os dados a serem inseridos
        solicitarDadosComprador(&compradores[i]);

        // Solicitar o tipo de ingresso
        do {
            printf("\n\n Escolha o tipo de ingresso:\n");
            printf(" 1. Inteira (R$%.2f)\n", PRECO_INTEIRA);
            printf(" 2. Meia Estudante (R$%.2f)\n", PRECO_MEIA_ESTUDANTE);
            printf(" 3. Especial Criança (R$%.2f)\n", PRECO_ESPECIAL_CRIANCA);
            printf(" 4. Especial Idoso (R$%.2f)\n", PRECO_ESPECIAL_IDOSO);
            printf(" 5. Meia Itaucard (R$%.2f)\n\n", PRECO_MEIA_ITAUCARD);
            printf(" Tipo: ");
            limparBuffer();
            if (scanf("%d", &compradores[i].tipoIngresso) != 1 || compradores[i].tipoIngresso < 1 || compradores[i].tipoIngresso > 5) {
                printf("Opção inválida. Tente novamente.\n");
                limparBuffer();
            } else {
                break; // A opção é válida, saia do loop
            }
        } while (1); // Repetir até que uma opção válida seja inserida

        // Verificar se o tipo de ingresso é Meia Estudante
        if (compradores[i].tipoIngresso == 2) {
            printf("\n Documento Estudante: ");
            scanf("%s", compradores[i].documentoEstudante);
            limparBuffer();
        }

        // Preço x Tipo de ingresso
        double precoIngresso = calcularPrecoIngresso(compradores[i].tipoIngresso);

        // Imprimir os valores para depuração
        printf(" Preço do Ingresso: R$%.2f\n", precoIngresso);
        printf(" Preço Total (anterior): R$%.2f\n", precoTotal);

        // Acumular para preço total
        precoTotal += precoIngresso;

        // Imprimir o novo valor do preço total
        printf(" Preço Total (atualizado): R$%.2f\n", precoTotal);

        // Gravação: ingressos.csv
        registrarIngresso(numeroVenda, compradores[i], compradores[i].tipoIngresso);

        // Questionamento para continuar ou cancelar a venda
        char opcaoContinuar;

        while (1) {
        printf("\n Deseja continuar para o próximo comprador (C) ou cancelar a venda (V)? ");
        scanf(" %c", &opcaoContinuar);

        if (opcaoContinuar == 'V' || opcaoContinuar == 'v') {
        printf("\n Venda cancelada. Pressione ENTER para retornar ao menu venda.\n");
        getchar();
        realizarVenda();
        } else if (opcaoContinuar == 'C' || opcaoContinuar == 'c') {
            break;  // Sai do loop, permitindo a continuação da venda
        } else {
        printf("\n Opção inválida. Digite 'C' para continuar ou 'V' para cancelar.\n");
        limparBuffer();
    }
}

    }

    char formaPagamento;
    int formaPagamentoValida = 0;

    while (!formaPagamentoValida) {
        imprimirCabecalho();
        printf(" Preço total da venda: R$%.2f\n\n", precoTotal);
        printf(" Escolha a forma de pagamento:\n");
        printf(" 1. Cartão de Débito\n");
        printf(" 2. Cartão de Crédito\n");
        printf(" 3. Dinheiro\n");
        printf(" 4. Pix\n\n");
        printf(" Forma de Pagamento: ");
        scanf(" %c", &formaPagamento);
        limparBuffer();

        switch (formaPagamento) {
            case '1':
                formaPagamentoValida = 1;
                break;
            case '2':
                formaPagamentoValida = 1;
                break;
            case '3':
                formaPagamentoValida = 1;
                break;
            case '4':
                formaPagamentoValida = 1;
                break;
            default:
                printf("Opção de pagamento inválida. Tente novamente (ENTER)");
                getchar();
                limparConsole();
        }
    }

    int i;
    int opcaoInvalida = 1; // Variável para rastrear se a opção é inválida
    while (opcaoInvalida) {
        imprimirCabecalho();
        printf(" PAGAMENTO APROVADO!\n");
        printf(" Preço total da venda: R$%.2f\n", precoTotal);
        printf(" Ingresso gerado e pronto para ser impresso.\n");
        printf(" Deseja imprimir o ingresso (S/N): ");
        scanf(" %c", &opcaoSN);

        if (opcaoSN == 'S' || opcaoSN == 's') {
            imprimirIngresso(numeroVenda, compradores, quantidade, tipoIngresso);
            opcaoInvalida = 0; // A opção é válida, saia do loop
        } else if (opcaoSN == 'N' || opcaoSN == 'n') {
            enviarIngressoEmail(numeroVenda, compradores, quantidade, tipoIngresso);
            opcaoInvalida = 0; // A opção é válida, saia do loop
        } else {
            printf("Opção inválida. Tente novamente (ENTER)");
            limparBuffer();
            getchar(); // Espera o usuário pressionar qualquer tecla
            limparConsole();
        }
    }
}



// FUNÇÃO: Data e hora da emissão do ingresso
void DataHoraEmissao() {
    time_t t;
    struct tm *dataHora;

    time(&t);
    dataHora = localtime(&t);

    printf(" Data e hora da emissão: %02d/%02d/%04d %02d:%02d:%02d\n", dataHora->tm_mday, dataHora->tm_mon + 1, dataHora->tm_year + 1900, dataHora->tm_hour, dataHora->tm_min, dataHora->tm_sec);
}



// FUNÇÃO: Impressão de ingressos
void imprimirIngresso(int numeroVenda, const struct Comprador compradores[], int quantidade, int tipoIngresso) {

    int i;

    system("cls");
    printf("\n---------------------------------------------\n");
    printf("\t\tMUSEU NOME\n");
    printf("---------------------------------------------\n\n");
    printf(" Venda Nr: %d\n",numeroVenda);
    printf("---------------------------------------------\n\n");

    for (int i = 0; i < quantidade; i++) {
        double precoIngresso = calcularPrecoIngresso(compradores[i].tipoIngresso);
        printf(" Ingresso %d\n\n", i + 1);
        printf(" Dados do Comprador:\n");
        printf(" Nome: %s\n", compradores[i].nome);
        printf(" Documento: %s\n", compradores[i].documento);
        printf(" Tipo de Ingresso: %d\n", compradores[i].tipoIngresso);
        printf(" Preço do Ingresso: R$%.2f\n", precoIngresso);
        DataHoraEmissao();
        printf("---------------------------------------------\n\n");
        printf(" Tenha uma ótima visita ao museu!\n");
        printf("---------------------------------------------\n\n");
    }

    char opcao;
    while (1) { // Loop infinito até que uma escolha válida seja feita
    printf(" Deseja fazer uma nova venda (V) ou voltar ao menu principal (M)? ");
    scanf(" %c", &opcao);

    if (opcao == 'V' || opcao == 'v') {
        system("cls");
        realizarVenda();  // Volta para a função de venda
        break; // Sai do loop se a escolha for válida
    } else if (opcao == 'M' || opcao == 'm') {
        system("cls");
        exibirMenu();  // Volta para a função do menu principal
        break; // Sai do loop se a escolha for válida
    } else {
        printf(" Opção inválida. Digite uma opção válida para continuar:\n\n");
        getchar();
    }
}
}



// FUNÇÃO: Enviar ingressos por e-mail
void enviarIngressoEmail(int numeroVenda, const struct Comprador compradores[], int quantidade, int tipoIngresso) {

    int i;
    char email[100];

    printf(" \nInforme o endereço de e-mail para enviar os ingressos: ");
    scanf("%s", email); // Solicita o endereço de e-mail

    getchar(); // Espera o usuário pressionar qualquer tecla
    limparConsole();

    system("cls");
    printf("\n---------------------------------------------\n");
    printf("\t\tMUSEU NOME\n");
    printf("---------------------------------------------\n\n");
    printf(" Venda Nr: %d\n", numeroVenda);
    printf("---------------------------------------------\n\n");

    for (int i = 0; i < quantidade; i++) {
        double precoIngresso = calcularPrecoIngresso(compradores[i].tipoIngresso);
        printf(" Ingresso %d\n\n", i + 1);
        printf(" Dados do Comprador:\n");
        printf(" Nome: %s\n", compradores[i].nome);
        printf(" Documento: %s\n", compradores[i].documento);
        printf(" Tipo de Ingresso: %d\n", compradores[i].tipoIngresso);
        printf(" Preço do Ingresso: R$%.2f\n", precoIngresso);
        DataHoraEmissao();
        printf("---------------------------------------------\n\n");
        printf(" Tenha uma ótima visita ao museu!\n");
        printf("---------------------------------------------\n\n");
    }

    printf(" Os ingressos foram enviados para o e-mail: %s\n", email);

    char opcao;
    while (1) { // Loop infinito até que uma escolha válida seja feita
    printf(" Deseja fazer uma nova venda (V) ou voltar ao menu principal (M)? ");
    scanf(" %c", &opcao);

    if (opcao == 'V' || opcao == 'v') {
        system("cls");
        realizarVenda();  // Volta para a função de venda
        break; // Sai do loop se a escolha for válida
    } else if (opcao == 'M' || opcao == 'm') {
        system("cls");
        exibirMenu();  // Volta para a função do menu principal
        break; // Sai do loop se a escolha for válida
    } else {
        printf("Opção inválida. Digite uma opção válida para continuar:\n\n");
        getchar();
    }
}
}
//*****************1. VENDAS*****************//



//*****************2. CONSULTAS*****************//
// FUNÇÃO: Consultas
void realizarConsulta() {
    limparConsole();
    imprimirCabecalhoConsulta();

    char filtro[100]; // Defina o filtro desejado
    printf(" *Você pode pesquisar por:\n");
    printf(" Hora\n");
    printf(" Data\n");
    printf(" Comprador\n");
    printf(" Documento\n");
    printf(" Tipo de ingresso\n\n");
    printf(" Digite o filtro para a consulta: ");
    scanf("%s", filtro);

    pesquisarIngressos("ingressos.csv", filtro);

    printf("\n Pressione ENTER para retornar ao menu principal.");
    limparBuffer();
    getchar(); // Espera o usuário pressionar Enter
    limparConsole();
}



// Estrutura para armazenar os dados dos ingressos
struct Ingresso {
    char dataHoraEmissao[20];
    int numeroVenda;
    char nomeComprador[100];
    char documento[20];
    int tipoIngresso;
    double precoIngresso;
};

#define MAX_INGRESSOS 100 // Defina o número máximo de ingressos que você deseja armazenar

struct Ingresso ingressos[MAX_INGRESSOS];
int numIngressosConsultados = 0; // Inicializa o contador de ingressos consultados


//FUNÇÃO: Adicionar cabeçalho
void imprimirCabecalhoConsulta() {
    system("cls");
    printf("\n---------------------------------------------\n");
    printf("\t\tMUSEU NOME\n");
    printf("---------------------------------------------\n\n");
    printf(" CONSULTA DE INGRESSOS\n\n");
    printf("---------------------------------------------\n\n\n");
}



// FUNÇÃO: Pesquisar e filtrar dados no arquivo "ingressos.csv"
void pesquisarIngressos(const char *arquivo, const char *filtro) {
    limparBuffer();
    limparConsole();
    imprimirCabecalhoConsulta();
    FILE *arquivoIngressos;
    int tentativas = 3; // Número máximo de tentativas

    do {
        arquivoIngressos = fopen(arquivo, "r");

        if (arquivoIngressos == NULL) {
            printf(" Erro ao abrir o arquivo de ingressos. Tentando novamente...\n");
            tentativas--;
        }
    } while (arquivoIngressos == NULL && tentativas > 0);

    if (arquivoIngressos == NULL) {
        printf(" Falha ao abrir o arquivo de ingressos. Pressione ENTER para retornar ao menu principal.\n");
        limparBuffer();
        getchar(); // Espera o usuário pressionar Enter
        limparConsole();
        return;
    }

    char linha[256];
    struct Ingresso ingresso;
    int encontrados = 0;

    printf("\n Resultados da Pesquisa:\n\n");

    while (fgets(linha, sizeof(linha), arquivoIngressos) != NULL) {
        sscanf(linha, "%[^;]; %d; %[^;]; %[^;]; %d; %lf", ingresso.dataHoraEmissao, &ingresso.numeroVenda,
               ingresso.nomeComprador, ingresso.documento, &ingresso.tipoIngresso, &ingresso.precoIngresso);

        if (strstr(linha, filtro) != NULL) {
            printf(" Data e Hora de Emissão: %s\n", ingresso.dataHoraEmissao);
            printf(" Número da Venda: %d\n", ingresso.numeroVenda);
            printf(" Nome do Comprador: %s\n", ingresso.nomeComprador);
            printf(" Documento: %s\n", ingresso.documento);
            printf(" Tipo de Ingresso: %d\n", ingresso.tipoIngresso);
            printf(" Preço do Ingresso: R$%.2lf\n", ingresso.precoIngresso);
            printf("---------------------------------------------\n");
            encontrados = 1;

            // Armazenar o ingresso consultado na matriz de ingressos
            ingressos[numIngressosConsultados] = ingresso;
            numIngressosConsultados++;
        }
    }

    fclose(arquivoIngressos);

    // Após a pesquisa
    if (!encontrados) {
        printf(" Nenhum resultado encontrado para o filtro: %s\n", filtro);
    } else {
        printf(" Digite uma das opções:\n\n");
        printf(" 1. Imprimir ingressos consultados\n");
        printf(" 2. Enviar ingressos por e-mail\n");
        printf(" 3. Voltar ao menu principal\n\n");
        printf(" Escolha uma opção: ");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirIngressosConsultados(ingressos, numIngressosConsultados);
                break;
            case 2:
                enviarIngressosPorEmail(ingressos, numIngressosConsultados);
                break;
            case 3:
                // Voltar ao menu principal
                break;
            default:
                printf(" Opção inválida. Voltando ao menu principal.\n");
                break;
        }
    }
}



// Função para imprimir os ingressos consultados
void imprimirIngressosConsultados(struct Ingresso ingressos[], int numIngressosConsultados) {
    printf("\nImprimindo Ingressos Consultados:\n\n");

    for (int i = 0; i < numIngressosConsultados; i++) {
        printf(" Data e Hora de Emissão: %s\n", ingressos[i].dataHoraEmissao);
        printf(" Número da Venda: %d\n", ingressos[i].numeroVenda);
        printf(" Nome do Comprador: %s\n", ingressos[i].nomeComprador);
        printf(" Documento: %s\n", ingressos[i].documento);
        printf(" Tipo de Ingresso: %d\n", ingressos[i].tipoIngresso);
        printf(" Preço do Ingresso: R$%.2lf\n", ingressos[i].precoIngresso);
        printf("---------------------------------------------\n\n");
    }
}



// Função enviar ingressos por e-mail
void enviarIngressosPorEmail(const struct Ingresso ingressos[], int numIngressos) {

    char email[100];
    printf(" \n Informe o endereço de e-mail para enviar os ingressos: ");
    scanf("%s", email); // Solicita o endereço de e-mail

    printf(" Enviando ingressos por e-mail para: %s\n", email);
    printf(" Ingressos enviados:\n");

    for (int i = 0; i < numIngressos; i++) {
        printf(" Número da Venda: %d\n", ingressos[i].numeroVenda);
        printf(" Nome do Comprador: %s\n", ingressos[i].nomeComprador);
        printf(" Tipo de Ingresso: %d\n", ingressos[i].tipoIngresso);
        printf(" Preço do Ingresso: R$%.2lf\n", ingressos[i].precoIngresso);
        printf("---------------------------------------------\n\n");
    }

    printf(" Ingressos enviados com sucesso!\n");
}
//*****************2. CONSULTAS*****************//



//*****************3. VALIDAÇÃO*****************//

#define MAX_LINE_LENGTH 1024

void validarIngresso() {

    limparConsole();

    // Abrir o arquivo CSV para leitura
    FILE *file = fopen("ingressos.csv", "r");
    if (file == NULL) {
        printf(" Erro ao abrir o arquivo CSV.\n");
        return 1;
    }


    printf("\n---------------------------------------------\n");
    printf("\t\tMUSEU NOME\n");
    printf("---------------------------------------------\n\n");
    printf(" VALIDAÇÃO DE INGRESSOS\n\n");
    printf("---------------------------------------------\n\n\n");

   int searchTicketNumber; // Número de ingresso a ser pesquisado
    printf(" Digite o número do documento impresso no ingresso: ");
    scanf("%d", &searchTicketNumber);

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Ler o arquivo linha por linha
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Divide a linha em tokens usando o ponto e vírgula como separador
        char *token = strtok(line, ";");

        // Pule o primeiro token (primeira coluna)
        token = strtok(NULL, ";");

        if (token != NULL) {
            // Converte a coluna "NumeroVenda" para um número inteiro
            int ticketNumber = atoi(token);

            // Se o número de ingresso na linha atual for igual ao digitado, faça a validação
            if (ticketNumber == searchTicketNumber) {
                found = 1;
                break;
            }
        }
    }

    // Fechar o arquivo
    fclose(file);

    if (found) {
        limparConsole();
        printf("\n---------------------------------------------\n");
        printf("\t\tMUSEU NOME\n");
        printf("---------------------------------------------\n\n");
        printf(" VALIDAÇÃO DE INGRESSOS\n\n");
        printf("---------------------------------------------\n\n\n");
        printf(" Ingresso válido.\n Seja bem-vindo(a)!\n\n");
        DataHoraEmissao();
        printf("\n\n---------------------------------------------\n\n");
        printf(" Pressione ENTER para voltar.");
        limparBuffer();
        getchar();
        validarIngresso();
}else {
        limparConsole();
        printf("\n---------------------------------------------\n");
        printf("\t\tMUSEU NOME\n");
        printf("---------------------------------------------\n\n");
        printf(" VALIDAÇÃO DE INGRESSOS\n\n");
        printf("---------------------------------------------\n\n\n");
        printf(" Ingresso inválido.\n Acesso negado!\n\n");
        printf(" Pressione ENTER para voltar.");
        limparBuffer();
        getchar();
        validarIngresso();
    }
}

//*****************3. VALIDAÇÃO*****************//

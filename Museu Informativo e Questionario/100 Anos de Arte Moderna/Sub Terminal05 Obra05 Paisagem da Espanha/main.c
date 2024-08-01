#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*=================== Variaveis Globais =====================*/
char titulo[3][80];
char texto[3][1000];
char autor[35];
char ano[35];
char tipo[35];
char local[100];
char meio[35];

char temporario[1000];// Coleta textos grandes de 680 caracteres, por isso o tamanho grande
FILE *entrada_obras;
/*===========================================================*/

/*================== Função Principal =======================*/
int main(){
    setlocale(LC_ALL,"Portuguese");
    system("color f0");
    dados_entrada_obra();
}
/*===========================================================*/

/*====== Copia informações do arquivo de info_obras.csv =====*/
void dados_entrada_obra (){

    entrada_obras = fopen("info_obras.csv", "r");
    if (entrada_obras == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //pega os titulos
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(2,2);
    strcpy(titulo[0], temporario);

    fseek(entrada_obras, 0, SEEK_SET);//zera o ponteiro de pesquisa do linha e coluna
    busca_info_entrada(3,2); //da a instrução para procurar a linha3 coluna2
    strcpy(titulo[1], temporario); //atribui o dado buscado ao subtitulo0

    //pega os textos
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(2,3);
    strcpy(texto[0], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,3);
    strcpy(texto[1], temporario);

    //pega o autor
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,4);
    strcpy(autor, temporario);

    //pega o ano
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,5);
    strcpy(ano, temporario);

    //pega o tipo
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,6);
    strcpy(tipo, temporario);

    //pega o local
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,7);
    strcpy(local, temporario);

    //pega o meio
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,8);
    strcpy(meio, temporario);

    fclose(entrada_obras);
    menu();
}
/*===========================================================*/

/*========= Copia o valor correto dentro do arquivo =========*/
void busca_info_entrada (const int* linha, const int* coluna){

    //entrada
    int linha_atual = 1;
    char trecho[1000];

    //processo
    while (fgets(trecho, sizeof(trecho), entrada_obras) != NULL) { // lê linhas do arquivo até  fgets retornar NULL
        if (linha_atual == linha) { // se a linha atual for igual a linha desejada ele guarda a posição da linha
            char *token = strtok(trecho, ";"); // identifica e separa cada campo (;) nomeando-os de token; ou seja, nesse caso o token é os ";"
            int coluna_atual = 1; //declara coluna atual e reinicia ela no valor 1 a cada looping

            while (token != NULL) { // looping que lê todos os token(;) até que não haja mais token (NULL)
                if (coluna_atual == coluna) { // se a coluna atual for igual a coluna desejada ele guarda a posição da coluna
                    strcpy(temporario, token); // Copie o valor entre o token para a variável global
                    break;
                }
                token = strtok(NULL, ";"); // após ler toda a linha
                coluna_atual++;
            }
        }
        linha_atual++;
    }
}
/*===========================================================*/

/*===========================================================*/
void perguntas() {
    char perguntas[10][90];
    char confirmar;
    char nome[12];
    int respostas[12];
    char resposta_escrita[100];
    int contar;
    FILE* entrada_perg;
    FILE* saida;

    entrada_perg = fopen("perguntas.txt", "r");
    saida = fopen("respostas.csv", "a");

    if (entrada_perg == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int respostaValida = 0;
    while (!respostaValida) {
        system("cls || clear");
        printf("Digite seu nome (apenas o nome): ");
        scanf("%s", nome);

        printf("\n%s está correto? (1. Sim / 2. Corrigir / 3. Retornar ao Menu)\n\n", nome);
        scanf(" %c", &confirmar);
            switch (confirmar) {
                case '1':
                    respostaValida = 1;
                    break;
                case '2':
                    break;
                case '3':
                    system("cls || clear");
                    fclose(entrada_perg);
                    fclose(saida);
                    menu();
                    break;
                default:
                    printf("\nValor incorreto.. Retornaremos a pergunta: ");
                    system("pause");
                    system("cls || clear");
                    break;
            }
    }
    system("cls || clear");



    for (int i = 0; i < 5; i++) {
        if (fgets(perguntas[i], sizeof(perguntas[i]), entrada_perg) != NULL) {
            perguntas[i][strcspn(perguntas[i], "\n")] = '\0';
            int respostaValida = 0;

            printf("Respostas de %s %d de 10 - ", nome, i+1);
            printf("Sobre a obra: %s\n", titulo[1]);

            while (!respostaValida) {
                printf("\n%s\n\nDigite uma resposta de 0 a 10: (10 = Muito / 5 = Neutro / 0 = Nada)\n\n", perguntas[i]);
                if (scanf("%d", &respostas[i]) != 1 || respostas[i] < 0 || respostas[i] > 10) {

                    printf("\nValor incorreto.\n\n");
                    limparBuffer();
                    printf("Quer tentar novamente ou retornar ao menu? (1. Tentar Novamente / 2. Retornar Menu)\n\n");
                    scanf(" %c", &confirmar);

                    switch (confirmar) {
                        case '1':
                            system("cls || clear");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a obra: %s\n", titulo[1]);
                            break;
                        case '2':
                            system("cls || clear");
                            fclose(entrada_perg);
                            fclose(saida);
                            menu();
                            break;
                        default:
                            printf("\nValor incorreto.. Retornaremos a pergunta: ");
                            system("pause");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a obra: %s\n", titulo[1]);
                            system("cls || clear");
                            break;
                    }
                }
                else {
                    printf("\nConfirmar envio? (1. Sim / 2. Corrigir / 3. Retornar ao Menu)\n\n");
                    scanf(" %c", &confirmar);

                    switch (confirmar) {
                        case '1':
                            respostaValida = 1;
                            system("cls || clear");
                            break;
                        case '2':
                            system("cls || clear");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a obra: %s\n", titulo[1]);
                            break;
                        case '3':
                            system("cls || clear");
                            fclose(entrada_perg);
                            fclose(saida);
                            menu();
                            break;
                        default:
                            printf("\nValor incorreto.. Retornaremos a pergunta: ");
                            system("pause");
                            system("cls || clear");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a obra: %s\n", titulo[1]);
                            break;
                    }
                }
            }
            // Saída
            contar++;
        }
    }


    fseek(saida, 0, SEEK_END);
    if (ftell(saida) == 0) { // Se a saida está vazia, então escreva o cabeçalho
        fprintf(saida, "Nome;Perg.1;Perg.2;Perg.3;Perg.4;Perg.5;Perg.6;Perg.7;Perg.8;Perg.9;Perg.10;\n");
    }

    fprintf(saida, "%s;", nome);
    fprintf(saida, "%d;", respostas[0]);
    fprintf(saida, "%d;", respostas[1]);
    fprintf(saida, "%d;", respostas[2]);
    fprintf(saida, "%d;", respostas[3]);
    fprintf(saida, "%d;", respostas[4]);

    for (int i = 5; i < 9; i++) {
        if (fgets(perguntas[i], sizeof(perguntas[i]), entrada_perg) != NULL) {
            perguntas[i][strcspn(perguntas[i], "\n")] = '\0';
            int respostaValida = 0;

            printf("Respostas de %s %d de 10 - ", nome, i+1);
            printf("Sobre a coleção: %s\n", titulo[0]);

            while (!respostaValida) {
                printf("\n%s\n\nDigite uma resposta de 0 a 10: (10 = Muito / 5 = Neutro / 0 = Nada)\n\n", perguntas[i]);
                if (scanf("%d", &respostas[i]) != 1 || respostas[i] < 0 || respostas[i] > 10) {

                    printf("\nValor incorreto.\n\n");
                    limparBuffer();
                    printf("Quer tentar novamente ou retornar ao menu? (1. Tentar Novamente / 2. Retornar Menu)\n\n");
                    scanf(" %c", &confirmar);

                    switch (confirmar) {
                        case '1':
                            system("cls || clear");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a coleção: %s\n", titulo[0]);
                            break;
                        case '2':
                            system("cls || clear");
                            fprintf(saida, "\n");
                            fclose(entrada_perg);
                            fclose(saida);
                            menu();
                            break;
                        default:
                            printf("\nValor incorreto.. Retornaremos a pergunta: ");
                            system("pause");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a coleção: %s\n", titulo[0]);
                            system("cls || clear");
                            break;
                    }
                }
                else {
                    printf("\nConfirmar envio? (1. Sim / 2. Corrigir / 3. Retornar ao Menu)\n\n");
                    scanf(" %c", &confirmar);

                    switch (confirmar) {
                        case '1':
                            respostaValida = 1;
                            system("cls || clear");
                            break;
                        case '2':
                            system("cls || clear");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a coleção: %s\n", titulo[0]);
                            break;
                        case '3':
                            system("cls || clear");
                            fprintf(saida, "\n");
                            fclose(entrada_perg);
                            fclose(saida);
                            menu();
                            break;
                        default:
                            printf("\nValor incorreto.. Retornaremos a pergunta: ");
                            system("pause");
                            system("cls || clear");
                            printf("Respostas de %s %d de 10 - ", nome, i+1);
                            printf("Sobre a coleção: %s\n", titulo[0]);
                            break;
                    }
                }
            }
            // Saída
            contar++;
        }
    }
    printf("Respostas de %s 10 de 10 - ", nome);
    printf("Sobre a coleção: %s\n", titulo[0]);
    fgets(perguntas[9], sizeof(perguntas[9]), entrada_perg);
    perguntas[9][strcspn(perguntas[9], "\n")] = '\0';

    printf("\n%s\n\n", perguntas[9]);
    getchar();
    fgets(resposta_escrita, sizeof(resposta_escrita), stdin);


    fprintf(saida, "%d;", respostas[5]);
    fprintf(saida, "%d;", respostas[6]);
    fprintf(saida, "%d;", respostas[7]);
    fprintf(saida, "%d;", respostas[8]);
    fprintf(saida, " %s", resposta_escrita);

    printf("\nObrigado pelas respostas %s e por visitar essa seção!!!\n\n", nome);
    system("pause");
    system("cls || clear");
    fclose(entrada_perg);
    fclose(saida);
    menu();
}
/*===========================================================*/

/*===========================================================*/
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
/*===========================================================*/

/*=================== menus Principal =======================*/
void menu() {

    // Entrada
    char navegar;

    printf("\n\t%s\n", titulo);
    printf("\nInforme uma opção válida e aperte a tecla enter\n\n");
    printf("1. Sobre a Obra %s\n", titulo[1]);
    printf("2. Sobre o Tema %s\n", titulo[0]);
    printf("3. Questionário\n");
    printf("0. Sair\n\n");
    scanf(" %c", &navegar);  // Use " %c" para evitar quebras de linha indesejadas.

    switch (navegar) {
        case '1':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[1]);
            printf("\n\tAno: %s\n", ano);
            printf("\tAutor(a): %s\n", autor);
            printf("\tTipo: %s\n", tipo);
            printf("\tLocal Atual: %s\n", local);
            printf("\tFeito Por Meio De: %s\n", meio);
            printf("\n\n%s\n\n", texto[1]);
            retornar_menu();
            break;
        case '2':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\t%s\n\n", texto[0]);

            retornar_menu();
            break;
        case '3':
            perguntas();
            break;
        case '0':
            sair();
            break;
        default:
            printf("\nDigite uma opção válida\n");
            retornar_menu();
    }
}
/*===========================================================*/

/*===================== Retorna Menu ========================*/
void retornar_menu(){
    system("pause");
    system("cls || clear");
    menu();
}
/*===========================================================*/

/*========================= sair ============================*/
void sair(){
    printf("\nObrigado por visitar essa seção!!!\n\n");
    system("pause");
}
/*===========================================================*/



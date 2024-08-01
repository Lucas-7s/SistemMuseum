#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*=================== Variaveis Globais =====================*/
char titulo[6][80];
char texto[7][1000];
char autor[7][35];
char ano[7][35];
char tipo[7][35];
char local[7][100];
char meio[7][35];

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

    entrada_obras = fopen("info_obras_b.csv", "r");
    if (entrada_obras == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    busca_info_entrada(2,2);
    strcpy(titulo[0], temporario);

    fseek(entrada_obras, 0, SEEK_SET);//zera o ponteiro de pesquisa do linha e coluna
    busca_info_entrada(3,2); //da a instrução para procurar a linha3 coluna2
    strcpy(titulo[1], temporario); //atribui o dado buscado ao subtitulo0

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,2);
    strcpy(titulo[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,2);
    strcpy(titulo[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,2);
    strcpy(titulo[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,2);
    strcpy(titulo[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,2);
    strcpy(titulo[6], temporario);

    //pega os textos
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(2,3);
    strcpy(texto[0], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,3);
    strcpy(texto[1], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,3);
    strcpy(texto[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,3);
    strcpy(texto[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,3);
    strcpy(texto[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,3);
    strcpy(texto[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,3);
    strcpy(texto[6], temporario);

    //pega os autores
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,4);
    strcpy(autor[1], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,4);
    strcpy(autor[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,4);
    strcpy(autor[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,4);
    strcpy(autor[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,4);
    strcpy(autor[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,4);
    strcpy(autor[6], temporario);

    //pega o ano
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,5);
    strcpy(ano[1], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,5);
    strcpy(ano[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,5);
    strcpy(ano[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,5);
    strcpy(ano[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,5);
    strcpy(ano[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,5);
    strcpy(ano[6], temporario);

    //pega o tipo
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,6);
    strcpy(tipo[1], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,6);
    strcpy(tipo[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,6);
    strcpy(tipo[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,6);
    strcpy(tipo[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,6);
    strcpy(tipo[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,6);
    strcpy(tipo[6], temporario);

    //pega o Local
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,7);
    strcpy(local[1], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,7);
    strcpy(local[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,7);
    strcpy(local[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,7);
    strcpy(local[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,7);
    strcpy(local[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,7);
    strcpy(local[6], temporario);

    //pega o meio
    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(3,8);
    strcpy(meio[1], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(4,8);
    strcpy(meio[2], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(5,8);
    strcpy(meio[3], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(6,8);
    strcpy(meio[4], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(7,8);
    strcpy(meio[5], temporario);

    fseek(entrada_obras, 0, SEEK_SET);
    busca_info_entrada(8,8);
    strcpy(meio[6], temporario);

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

/*=================== menus Principal =======================*/
void menu() {

    // Entrada
    char navegar;

    printf("\n\t%s\n", titulo);
    printf("\nInforme uma opção válida e aperte a tecla enter\n\n");
    printf("1. Sobre as Obras\n");
    printf("2. Sobre o Tema\n");
    printf("0. Sair\n\n");
    scanf(" %c", &navegar);  // Use " %c" para evitar quebras de linha indesejadas.

    switch (navegar) {
        case '1':
            system("cls || clear");
            menu_obras();
            break;
        case '2':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\t%s\n\n", texto[0]);

            retornar_menu();
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

/*===================== Retorna obras =======================*/
void retornar_menu2(){
    system("pause");
    system("cls || clear");
    menu_obras();
}
/*===========================================================*/

/*========================= sair ============================*/
void sair(){
    printf("\nObrigado por visitar essa seção!!!\n\n");
    system("pause");
}
/*===========================================================*/

/*====================== Menu obras =========================*/
void menu_obras(){
    // Entrada
    char navegar;


    printf("\n\t%s\n", titulo);
    printf("\nQual obra deseja mais informações?\n");
    printf("\nInforme uma opção válida e aperte a tecla enter\n\n");

    printf("1. %s - %s\n", titulo[1], tipo[1]);
    printf("2. %s - %s\n", titulo[2], tipo[2]);
    printf("3. %s - %s\n", titulo[3], tipo[3]);
    printf("4. %s - %s\n", titulo[4], tipo[4]);
    printf("5. %s - %s\n", titulo[5], tipo[5]);
    printf("6. %s - %s\n", titulo[6], tipo[6]);
    printf("7. Retornar\n");
    printf("0. Sair\n\n");
    scanf(" %c", &navegar);

        switch (navegar) {
        case '1':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[1]);
            printf("\n\tAno: %s\n", ano[1]);
            printf("\tAutor(a): %s\n", autor[1]);
            printf("\tTipo: %s\n", tipo[1]);
            printf("\tLocal Atual: %s\n", local[1]);
            printf("\tFeito Por Meio De: %s\n", meio[1]);
            printf("\n\n%s\n\n", texto[1]);
            retornar_menu2();
            break;
        case '2':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[2]);
            printf("\n\tAno: %s\n", ano[2]);
            printf("\tAutor(a): %s\n", autor[2]);
            printf("\tTipo: %s\n", tipo[2]);
            printf("\tLocal Atual: %s\n", local[2]);
            printf("\tFeito Por Meio De: %s\n", meio[2]);
            printf("\n\n%s\n\n", texto[2]);
            retornar_menu2();
            break;
        case '3':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[3]);
            printf("\n\tAno: %s\n", ano[3]);
            printf("\tAutor(a): %s\n", autor[3]);
            printf("\tTipo: %s\n", tipo[3]);
            printf("\tLocal Atual: %s\n", local[3]);
            printf("\tFeito Por Meio De: %s\n", meio[3]);
            printf("\n\n%s\n\n", texto[3]);
            retornar_menu2();
            break;
        case '4':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[4]);
            printf("\n\tAno: %s\n", ano[4]);
            printf("\tAutor(a): %s\n", autor[4]);
            printf("\tTipo: %s\n", tipo[4]);
            printf("\tLocal Atual: %s\n", local[4]);
            printf("\tFeito Por Meio De: %s\n", meio[4]);
            printf("\n\n%s\n\n", texto[4]);
            retornar_menu2();
            break;
        case '5':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[5]);
            printf("\n\tAno: %s\n", ano[5]);
            printf("\tAutor(a): %s\n", autor[5]);
            printf("\tTipo: %s\n", tipo[5]);
            printf("\tLocal Atual: %s\n", local[5]);
            printf("\tFeito Por Meio De: %s\n", meio[5]);
            printf("\n\n%s\n\n", texto[5]);
            retornar_menu2();
            break;
        case '6':
            system("cls || clear");
            printf("\n\t%s\n", titulo[0]);
            printf("\n\n\tObra: %s\n", titulo[6]);
            printf("\n\tAno: %s\n", ano[6]);
            printf("\tAutor(a): %s\n", autor[6]);
            printf("\tTipo: %s\n", tipo[6]);
            printf("\tLocal Atual: %s\n", local[6]);
            printf("\tFeito Por Meio De: %s\n", meio[6]);
            printf("\n\n%s\n\n", texto[6]);
            retornar_menu2();
            break;
        case '7':
            system("cls || clear");
            menu();
            break;
        case '0':
            sair();
            break;
        default:
            printf("\nDigite uma opção válida\n");
            retornar_menu2();
    }

}
/*===========================================================fim*/

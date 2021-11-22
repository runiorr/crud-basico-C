#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int estoque[10][3];

int estoque_quantidade = 0;
int x;
void menu(void);

void cadastrar(void) {
    int quantidade;
    int tipo;
    if (estoque_quantidade<10){
        while (x<10){
            if (estoque[x][2] == 0){
                printf("Digite a quantidade: ");
                scanf("%d", &estoque[x][1]);

                printf("1 - Largura 140cm\n2 - Largura 80cm\n3 - Largura 50 cm\nDigite o tipo: ");
                scanf("%d", &estoque[x][2]);
                if(estoque[x][2] > 3) { printf("Digite um valor valido.\n"); estoque[x][1]=0; estoque[x][2]=0; x=0; Sleep(2000); cadastrar(); }
                else{
                    estoque[x][0] = x;

                    x = 0;

                    estoque_quantidade++;
                    Sleep(1000);
                    printf("\n");
                    menu();
                }
            }
            else { x++; cadastrar(); }
        }
    }
    else {
            printf("Estoque cheio!\n");
            Sleep(1000);
            printf("\n");
            menu();
    }   
}
void remover(void) {
    if (estoque_quantidade != 0) {
        int escolha;

        printf("Escolha o codigo do produto a ser removido (0 a 9): ");
        scanf("%d", &escolha);
        if ( escolha > 10) { printf("Escolha um codigo valido.\n"); Sleep(2000); remover(); }
        else {
            estoque[escolha][1] = 0;
            estoque[escolha][2] = 0;
            estoque_quantidade--;
            
            Sleep(1000);
            printf("\n");
            menu();
        } 
    }
    else {
        printf("Insira algo no estoque primeiro.\n");
        Sleep(1000);
        printf("\n");
        menu();
    }
}

void total_por_tipo(void) {
    if (estoque_quantidade != 0) {
        int total_tipo1=0;
        int total_tipo2=0;
        int total_tipo3=0;

        for(int i=0;i<10;i++) { //Rows
            for(int j=0;j<3;j++) { //Cols
                if (j == 2) {
                    if (estoque[i][j] == 1 ) {
                        total_tipo1 += estoque[i][1];
                    }
                    else if (estoque[i][j] == 2 ) {
                        total_tipo2 += estoque[i][1];
                    }
                    else {
                        total_tipo3 += estoque[i][1];
                    }
                }
            }
        }
        printf("Total de tecidos por tipo\n1\t2\t3\t\n");
        printf("%d\t%d\t%d\n",total_tipo1,total_tipo2,total_tipo3);
        Sleep(1000);
        printf("\n");
        menu();
    }
    else {
        printf("Insira algo no estoque primeiro.\n");
        Sleep(1000);
        printf("\n");
        menu();
    }
}
void tipo_sem_estoque(void) {
    int total_tipo1=0;
    int total_tipo2=0;
    int total_tipo3=0;

    for(int i=0;i<10;i++){ //Rows
        for(int j=0;j<3;j++) { //Cols
            if (j==2){
                if (estoque[i][j] == 1 ) {
                    total_tipo1 += estoque[i][1];
                }
                else if (estoque[i][j] == 2 ) {
                    total_tipo2 += estoque[i][1];
                }
                else {
                    total_tipo3 += estoque[i][1];
                }
            }
        }
    }

    printf("Tipos de tecido sem estoque\n");
    if (total_tipo1 == 0) {
        printf("1\t");
    }
    if (total_tipo2 == 0){
        printf("2\t");
    }
    if (total_tipo3 == 0){
       printf ("3\n");
    }
    Sleep(1000);
    printf("\n");
    menu();
}

void total_sem_tipo(void) {
    if (estoque_quantidade != 0) {
        int total = 0;
        printf("Estoque total de tecidos\n");

        for(int i=0;i<10;i++){ //Rows
            for(int j=0;j<3;j++) { //Cols
                if (j == 1) {
                total += estoque[i][j];
                }
            }
        }
        printf("Total de tecidos:\t");
        printf("%d\n", total);
        Sleep(1000);
        printf("\n");
        menu();
    }
    else {
        printf("Insira algo no estoque primeiro.\n");
        Sleep(1000);
        printf("\n");
        menu();
    }
    
}

void metros_quadrados(void) {
    if (estoque_quantidade != 0) {
        int total_tipo1;
        int total_tipo2;
        int total_tipo3;

        int metros_totais_1;
        int metros_totais_2;
        int metros_totais_3;
        int metros_totais;

        for(int i=0;i<10;i++) { //Rows
            for(int j=0;j<3;j++) { //Cols
                if (j == 2) {
                    if (estoque[i][j] == 1 ) {
                        total_tipo1 += estoque[i][1];
                    }
                    else if (estoque[i][j] == 2 ) {
                        total_tipo2 += estoque[i][1];
                    }
                    else {
                        total_tipo3 += estoque[i][1];
                    }
                }
            }
        }

        metros_totais_1 = total_tipo1 * 7;
        metros_totais_2 = total_tipo2 * 8;
        metros_totais_3 = total_tipo3 * 3;
        metros_totais = (metros_totais_1 + metros_totais_2 + metros_totais_3);

        printf("A quantidade de metros quadrados estocados e: ");
        printf("%d", metros_totais);
        printf("m2");
        Sleep(1000);
        printf("\n");
        menu();
    }
    else {
        printf("Insira algo no estoque primeiro.\n");
        Sleep(1000);
        printf("\n");
        menu();
    }
}

void alterar_quantidade(void) {
    if (estoque_quantidade != 0) {
        int escolha;
        int quant;
        char opcao;
        int teste;

        printf("Escolha o codigo do produto a ser alterado (0 a 9): ");
        scanf("%d", &escolha);
        if ( escolha > 10) { printf("Escolha um codigo valido.\n"); Sleep(2000); alterar_quantidade(); }

        printf("\nQuantos produtos serao adicionados/removidos? ");
        scanf("%d", &quant);

        printf("\nVoce quer acrescentar ou remover? [+/-] ");
        scanf (" %c", &opcao);

        if (opcao == '+') {
            estoque[escolha][1] += quant;
            Sleep(1000);
            printf("\n");
            menu();
        }
        else if (opcao == '-') {
            teste = estoque[escolha][1] - quant;
            if (teste >= 0){
                estoque[escolha][1] -= quant;

                Sleep(1000);
                printf("\n");
                menu();
            }
            else {
                printf("O produto ficou negativo! Acao invalida. Repita!\n");
                Sleep(3500);
                menu();
            }
        }
        else {
            printf("Opcao invalida. Repita o processo por favor!\n");
            Sleep(2000);
            alterar_quantidade();
        }
    }
    else {
        printf("Insira algo no estoque primeiro.\n");
        Sleep(1000);
        printf("\n");
        menu();
    }
}

void sair(void) {
    printf("Volte sempre!\n");
    printf("*saindo*");
    Sleep(3000);
    exit(0);

}

void menu(void) {
    int escolha;

    printf("Bem vindo a loja de tecidos! \n");
    printf("Escolha uma opcao abaixo: \n");
    printf("1 - Cadastrar tecido \n");
    printf("2 - Remover tecido \n");
    printf("3 - Quantidade de rolos estocados por tipo de tecido \n");
    printf("4 - Tipos de tecido sem estoque \n");
    printf("5 - Quantidade total de rolos dos tecidos estocados \n");
    printf("6 - Quantidade em metros quadrados estocados \n");
    printf("7 - Alteracao da quantidade de rolos estocados \n");
    printf("8 - Sair da loja \n");

    scanf("%d", &escolha);

    if (escolha < 9) {
        switch (escolha) {
        case 1:
        cadastrar();
        break;

        case 2:
        remover();
        break;

        case 3:
        total_por_tipo();
        break;

        case 4:
        tipo_sem_estoque();
        break;

        case 5:
        total_sem_tipo();
        break;

        case 6:
        metros_quadrados();
        break;

        case 7:
        alterar_quantidade();
        break;

        case 8:
        sair();
        break;
        }
    }
    else {
        printf("Escolha uma opcao valida.\n");
        Sleep(3000);
        menu();
    }
    
}

int main (void) {
    menu();
    return 0;
}
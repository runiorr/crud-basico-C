#include <stdio.h>
#include <stdlib.h>

// Codigo - Peso - Raca
float bois[10][3];
float terneiros[10][3];
float vacas[10][3];
float terneiras[10][3];

int femea = 0;
int infantil = 0;
int macho = 1; 
int adulto = 1;

int neutro = 9;

int nelore = 1;
int angus = 2;
int gir = 3;
int jersey = 4;


void menu(void);

void limpar_tela() {
    system("cls");
}

void status_atual(int sexo) {
    printf("=== Status dos animais ===\n");
    if (sexo == femea) {
        printf("Vacas: %d posicoes livres\n", matriz_livres(vacas));
        printf("Terneiras: %d posicoes livres\n", matriz_livres(terneiras));
    }
    else if (sexo == macho) {
        printf("Bois: %d posicoes livres\n", matriz_livres(bois));
        printf("Terneiros: %d posicoes livres\n", matriz_livres(terneiros));
    }
}

void informacoes_raca(int sexo) {
    if (sexo == femea) {
        printf("=== Cadastre uma vaca/terneira ===\n");
        printf("Escolha a raca:\n1 - Nelore\n3 - Gir\n4 - Jersey\n --- ");
    }
    else if (sexo == macho) {
        printf("=== Cadastre um boi/terneiro === \n");
        printf("Escolha a raca:\n1 - Nelore\n2 - Angus\n3 - Gir\n --- ");
    }
    else {
        printf("Escolha a raca:\n1 - Nelore\n2 - Angus\n3 - Gir\n4 - Jersey\n --- ");
    }
}

void informacoes_peso(int sexo) {
    printf("\n=== Digite o peso do animal ===\n");
    if (sexo == femea) {
        printf("*Vacas tem mais de 100 kg\n*Terneiras tem menos de 100kg e mais de 20kg\n*Nenhum animal pode possuir menos de 20kg\n--- ");
    }
    else if (sexo == macho) {
        printf("*Bois tem mais de 120 kg\n*Terneiros tem menos de 120kg e mais de 20kg\n*Nenhum animal pode possuir menos de 20kg\n--- ");
    }
}

void informacao_animais(int sexo, int maturidade) {
    if (sexo == femea) {
        if (maturidade == infantil) {
            for(int i=0; i < 10; i++) {
                if (terneiras[i][2] != 0) {
                    printf("Terneira %.0f - %.2f kgs - Raca %.0f\n", terneiras[i][0], terneiras[i][1], terneiras[i][2]);
                }
            }
        }
        if (maturidade == adulto) {
            for(int i=0; i < 10; i++) {
                if (vacas[i][2] != 0) {
                    printf("Vaca %.0f - %.2f kgs - Raca %.0f\n", vacas[i][0], vacas[i][1], vacas[i][2]);
                }
            }
        }
    }
    if (sexo == macho) {
        if (maturidade == infantil) {
            for(int i=0; i < 10; i++) {
                if (terneiros[i][2] != 0) {
                    printf("Terneiro %.0f - %.2f kgs - Raca %.0f\n", terneiros[i][0], terneiros[i][1], terneiros[i][2]);
                }
            }  
        }
        if (maturidade == adulto) {
            for(int i=0; i < 10; i++) {
                if (bois[i][2] != 0) {
                    printf("Boi %.0f - %.2f kgs - Raca %.0f\n", bois[i][0], bois[i][1], bois[i][2]);
                }
            }
        }
    }
}

int validar_raca(int sexo, int raca) {
    if (sexo == femea) {
        if (raca != nelore & raca != gir & raca != jersey) {
            printf("Digite uma raca valida!\n\n");
            cadastrar_femea();
        }
        return 0;
    }
    else if (sexo == macho) {
        if (raca != nelore & raca != angus & raca != gir) {
            printf("Digite uma raca valida!\n\n");
            cadastrar_macho();
        }
        return 0;
    }
    else {
        if (raca != nelore & raca != angus & raca != gir & raca != jersey) {
            printf("Digite uma raca valida!\n\n");
            menu();
        }
        return 0;
    }
}

int validar_peso(int sexo, int maturidade, float peso) {
    if (sexo == femea) {
        if (maturidade == adulto) {
            if (peso < 100) {
                printf("Digite um peso valido\n");
                menu();
            }
        }
        if (peso >= 100) {
            return adulto;
        }
        else if (20 < peso & peso < 100) {
            return infantil;
        }
        else if (peso < 20) {
            printf("Digite um peso valido\n");
            menu();
        }
    }
    if (sexo == macho) {
        if (maturidade == adulto) {
            if (peso < 120) {
                printf("Digite um peso valido\n");
                menu();
            }
        }
        if (peso >= 120) {
            return adulto;
        }
        else if (20 < peso & peso < 120) {
            return infantil;
        }
        else if (peso < 20) {
            printf("Digite um peso valido\n");
            menu();
        }
    }
}


int validar_maturidade(int sexo, float peso) {
    if (sexo == femea) {
        if (peso >= 100) {
            return adulto;
        }
        else if (20 < peso & peso < 100) {
            return infantil;
        }
        else if (peso < 20) {
            printf("Digite um peso valido\n");
            menu();
        }
    }
    if (sexo == macho) {
        if (peso >= 120) {
            return adulto;
        }
        else if (20 < peso & peso < 120) {
            return infantil;
        }
        else if (peso < 20) {
            printf("Digite um peso valido\n");
            menu();
        }
    }
}

float **descobrir_matriz(int sexo, int maturidade) {
    if (sexo == femea) {
        if (maturidade == infantil) {
            return terneiras;
        }
        if (maturidade == adulto) {
            return vacas;
        }
    }
    if (sexo == macho) {
        if (maturidade == infantil) {
            return terneiros;
        }
        if (maturidade == adulto) {
            return bois;
        }
    }
}

int matriz_livres(float matriz[][3]) {
    int livres = 10;
    for (int i = 0; i < 10; i++) {
        if (matriz[i][2] != 0) {
            livres = livres - 1;
        }
    }
    return livres;
}

int matriz_posicao_disponivel(float matriz[][3]) {    
    for (int x = 0; x < 10; x++) {
        if (matriz[x][2] == 0) {
            return x;
        }
    }
    printf("O curral esta cheio!\n");
    menu();
}

int matriz_raca_atual(float matriz[][3], int escolha) {
    for (int x = 0; x < 10; x++) {
        if (matriz[x][0] == escolha) {
            return matriz[x][2];
        }
    }
}

void remover_matriz(int escolha, int sexo, int maturidade) {
    if (sexo == femea) {
        if (maturidade == infantil) {
            for(int i=0; i < 10; i++) {
                if (terneiras[i][0] == escolha) {
                    terneiras[i][0] = 0;
                    terneiras[i][1] = 0;
                    terneiras[i][2] = 0;
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
        if (maturidade == adulto) {
            for(int i=0; i < 10; i++) {
                if (vacas[i][0] == escolha) {
                    vacas[i][0] = 0;
                    vacas[i][1] = 0;
                    vacas[i][2] = 0;
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
    }
    if (sexo == macho) {
        if (maturidade == infantil) {
            for(int i=0; i < 10; i++) {
                if (terneiros[i][0] == escolha) {
                    terneiros[i][0] = 0;
                    terneiros[i][1] = 0;
                    terneiros[i][2] = 0;
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
        if (maturidade == adulto) {
            for(int i=0; i < 10; i++) {
                if (bois[i][0] == escolha) {
                    bois[i][0] = 0;
                    bois[i][1] = 0;
                    bois[i][2] = 0;
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
    }
}

void alterar_matriz(int escolha, int sexo, int maturidade, float peso) {
    if (sexo == femea) {
        if (maturidade == infantil) {
            for(int i=0; i < 10; i++) {
                if (terneiras[i][0] == escolha) {
                    terneiras[i][0] = terneiras[i][0];
                    terneiras[i][1] = peso;
                    terneiras[i][2] = terneiras[i][2];
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
        if (maturidade == adulto) {
            for(int i=0; i < 10; i++) {
                if (vacas[i][0] == escolha) {
                    vacas[i][0] = vacas[i][0];
                    vacas[i][1] = peso;
                    vacas[i][2] = vacas[i][2];
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
    }
    if (sexo == macho) {
        if (maturidade == infantil) {
            for(int i=0; i < 10; i++) {
                if (terneiros[i][0] == escolha) {
                    terneiros[i][0] = terneiros[i][0];
                    terneiros[i][1] = peso;
                    terneiros[i][2] = terneiros[i][2];
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
        if (maturidade == adulto) {
            for(int i=0; i < 10; i++) {
                if (bois[i][0] == escolha) {
                    bois[i][0] = bois[i][0];
                    bois[i][1] = peso;
                    bois[i][2] = bois[i][2];
                }
                else {
                    printf("\nEscolha um valor valido!\n");
                    menu();
                }
            } 
        }
    }
}

void inserir_matriz(int posicao, int sexo, int maturidade, float peso, int codigo_raca) {
    if (sexo == femea) {
        if (maturidade == infantil) {
            terneiras[posicao][0] = posicao;
            terneiras[posicao][1] = peso;
            terneiras[posicao][2] = codigo_raca;
            printf("=== Terneira cadastrada! ===\n\n");
        }
        if (maturidade == adulto) {
            vacas[posicao][0]= posicao;
            vacas[posicao][1]= peso;
            vacas[posicao][2]= codigo_raca;
            printf("=== Vaca cadastrada! ===\n\n");
        }
    }
    if (sexo == macho) {
        if (maturidade == infantil) {
            terneiros[posicao][0] = posicao;
            terneiros[posicao][1] = peso;
            terneiros[posicao][2] = codigo_raca;
            printf("=== Terneiro cadastrado! ===\n\n");
        }
        if (maturidade == adulto) {
            bois[posicao][0] = posicao;
            bois[posicao][1] = peso;
            bois[posicao][2] = codigo_raca;
            printf("=== Boi cadastrado! ===\n\n");
        }
    }
}

void cadastro(int sexo) {
    int codigo_raca, posicao, maturidade;
    float peso;
    int opcao_raca;

    limpar_tela();
    status_atual(sexo);
    informacoes_raca(sexo);
    scanf("%d", &opcao_raca);
    validar_raca(sexo, opcao_raca);
    informacoes_peso(sexo);
    scanf("%f", &peso);
    maturidade = validar_maturidade(sexo, peso);
    posicao = matriz_posicao_disponivel(descobrir_matriz(sexo, maturidade));
    inserir_matriz(posicao, sexo, maturidade, peso, opcao_raca);
}

void cadastrar_femea() {
    cadastro(femea);
    menu();
}

void cadastrar_macho() {
    cadastro(macho);
    menu();
}

void remover_animal() {
    int sexo;
    int maturidade;
    int escolha;

    printf("Remover femea ou macho?\n0 - Femea\n1 - Macho\n5 - Voltar ao menu\n--- ");
    scanf("%d", &sexo);
    if (sexo == 5) { menu();}
    status_atual(sexo);
    sleep(1);
    printf("Remover infantil ou adulto?\n0 - Infantil\n1 - Adulto\n--- ");
    scanf("%d", &maturidade);
    informacao_animais(sexo, maturidade);
    sleep(1);
    printf("Insira o codigo de qual voce deseja remover\n--- ");
    scanf("%d", &escolha); 
    remover_matriz(escolha, sexo, maturidade);
    printf("Animal removido!\n");
    sleep(2);
    limpar_tela();
    
    menu();
}

void quantidade_total() {
    int qt_bois, qt_terneiros, qt_vacas, qt_terneiras, qt_total;

    qt_bois = (matriz_livres(bois) - 10) * -1; 
    qt_terneiros = (matriz_livres(terneiros) - 10) * -1;
    qt_vacas = (matriz_livres(vacas) - 10) * -1;
    qt_terneiras = (matriz_livres(terneiras) - 10) * -1;
    qt_total = qt_bois + qt_terneiros + qt_vacas + qt_terneiras;

    printf("\nTotal de animais: %d\n\n", qt_total);
    printf("Total de bois: %d\n", qt_bois);
    printf("Total de terneiros: %d\n", qt_terneiros);
    printf("Total de vacas: %d\n", qt_vacas);
    printf("Total de terneiras: %d\n\n", qt_terneiras);
    menu();
}

void peso_animal() {
    float qt_bois = 0.0;
    float qt_terneiros = 0.0; 
    float qt_vacas = 0.0; 
    float qt_terneiras = 0.0; 
    float qt_total = 0.0;

    for(int i=0; i < 10; i++) {
        if (bois[i][1] != 0) { qt_bois += bois[i][1]; }
    }
    for(int i=0; i < 10; i++) {
        if (terneiros[i][1] != 0) { qt_terneiros += terneiros[i][1]; }
    }
    for(int i=0; i < 10; i++) {
        if (vacas[i][1] != 0) { qt_vacas = qt_vacas + vacas[i][1]; }
    }
    for(int i=0; i < 10; i++) {
        if (terneiras[i][1] != 0) { qt_terneiras += terneiras[i][1]; }
    }
    qt_total = qt_bois + qt_terneiros + qt_vacas + qt_terneiras;

    limpar_tela();
    printf("\nTotal do rebanho: %.2f kgs\n\n", qt_total);
    printf("Peso dos bois: %.2f kgs\n", qt_bois);
    printf("Peso dos terneiros: %.2f kgs\n", qt_terneiros);
    printf("Peso das vacas: %.2f kgs\n", qt_vacas);
    printf("Peso das terneiras: %.2f kgs\n\n", qt_terneiras);
    sleep(5);
    menu();
}

void animais_raca(void) {
    int qt_bois = 0;
    int qt_terneiros = 0; 
    int qt_vacas = 0; 
    int qt_terneiras = 0; 
    int qt_total = 0;
    int raca;
    
    informacoes_raca(neutro);
    scanf("%d", &raca);
    validar_raca(neutro, raca);

    for(int i=0; i < 10; i++) {
        if (bois[i][2] == raca) { qt_bois++; }
    }
    for(int i=0; i < 10; i++) {
        if (terneiros[i][2] == raca) { qt_terneiros++; }
    }
    for(int i=0; i < 10; i++) {
        if (vacas[i][2] == raca) { qt_vacas++; }
    }
    for(int i=0; i < 10; i++) {
        if (terneiras[i][2] == raca) { qt_terneiras++; }
    }
    qt_total = qt_bois + qt_terneiros + qt_vacas + qt_terneiras;

    // Criar funcao para converter codigo de raca para nome
    limpar_tela();
    printf("\nTotal de animais: %d\n\n", qt_total);
    printf("Total de bois: %d\n", qt_bois);
    printf("Total de terneiros: %d\n", qt_terneiros);
    printf("Total de vacas: %d\n", qt_vacas);
    printf("Total de terneiras: %d\n\n", qt_terneiras);
    sleep(5);
    menu();
}

void alterar_animal() {
    int sexo;
    int maturidade1;
    int maturidade2;
    int escolha;
    int posicao_disponivel;
    int raca;
    float peso;

    printf("Alterar femea ou macho?\n0 - Femea\n1 - Macho\n5 - Voltar ao menu\n--- ");
    scanf("%d", &sexo);
    if (sexo == 5) { menu();}
    status_atual(sexo);
    sleep(1);
    printf("Alterar infantil ou adulto?\n0 - Infantil\n1 - Adulto\n--- ");
    scanf("%d", &maturidade1);
    informacao_animais(sexo, maturidade1);
    sleep(1);
    printf("Insira o codigo de qual voce deseja Alterar\n--- ");
    scanf("%d", &escolha);
    informacoes_peso(sexo);
    scanf("%f", &peso);
    validar_peso(sexo, maturidade1, peso);
    maturidade2 = validar_maturidade(sexo, peso);
    if (maturidade1 == maturidade2) {
        alterar_matriz(escolha, sexo, maturidade2, peso);
    }
    else {
        posicao_disponivel = matriz_posicao_disponivel(descobrir_matriz(sexo, maturidade2));
        raca = matriz_raca_atual(descobrir_matriz(sexo, maturidade1), escolha);
        remover_matriz(escolha, sexo, maturidade1);
        inserir_matriz(posicao_disponivel, sexo, maturidade2, peso, raca);
    }

    printf("Animal alterado!\n");
    sleep(2);
    limpar_tela();
    menu();
}

void sair(void) {
    printf("Ate logo!\n");
    printf("*saindo*");
    sleep(1);
    exit(0);
}

void menu() {
    int escolha;

    printf("Bem vindo ao controle de bovinos \n");
    printf("Escolha uma opcao abaixo: \n");
    printf("1 - Cadastrar vacas/terneiras \n");
    printf("2 - Cadastrar bois/terneiros \n");
    printf("3 - Remover animal \n");
    printf("4 - Quantidade total de animais no rebanho \n");
    printf("5 - Peso total do rebanho \n");
    printf("6 - Quantidade de animais de cada raca \n");
    printf("7 - Alteracao do peso do animal \n");
    printf("8 - Sair \n--- ");

    scanf("%d", &escolha);

    if (escolha < 9) {
        switch (escolha) {
        case 1:
        limpar_tela();
        cadastrar_femea();
        break;

        case 2:
        limpar_tela();
        cadastrar_macho();
        break;

        case 3:
        limpar_tela();
        remover_animal();
        break;

        case 4:
        limpar_tela();
        quantidade_total();
        break;

        case 5:
        limpar_tela();
        peso_animal();
        break;

        case 6:
        limpar_tela();
        animais_raca();
        break;

        case 7:
        limpar_tela();
        alterar_animal();
        break;

        case 8:
        limpar_tela();
        sair();
        break;
        }
    }
    else {
        printf("Escolha uma opcao valida.\n");
        menu();
    }
}

int main() {
    limpar_tela();
    menu();
    return 0;
}
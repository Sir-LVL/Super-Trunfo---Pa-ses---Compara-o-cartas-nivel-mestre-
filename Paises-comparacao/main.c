#include <stdio.h>
#include <stdlib.h>

void LimpaConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main()
{
    int opcao;
    LimpaConsole();

    while(1) {
        printf("\n==================================\n");
        printf("          MENU PRINCIPAL          \n");
        printf("==================================\n");
        printf("1 - Item 1\n");
        printf("2 - Sobre o Desenvolvedor\n");
        printf("3 - Sair\n");
        printf("==================================\n");
        printf("Escolha uma opcão: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
        case 1:
            printf("teste switch");
            break;
        case 2:
            printf("Ainda pensando");
            break;
        case 3:
            printf("Saindo...\n");
            printf("Aperte Enter para encerrar...");
            return 0;
        default:
            printf("opção invalida, digite novamente\n");
        }
    }
    return 0;
}

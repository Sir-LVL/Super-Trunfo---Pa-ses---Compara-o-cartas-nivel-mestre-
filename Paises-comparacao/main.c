#include <stdio.h>
#include <stdlib.h>


int main()
{
    int opcao;

    while(1) {
        printf("\n==================================\n");
        printf("          MENU PRINCIPAL          \n");
        printf("==================================\n");
        printf("1 - Cadastrar Países\n");
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
            printf("Opa me chamo Lucas, sou estudante de Ciência da Computação, e você está executando um programa meu ;)");
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

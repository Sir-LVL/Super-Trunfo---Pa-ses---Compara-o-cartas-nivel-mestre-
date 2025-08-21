#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;


    printf("==================================\n");
    printf("          MENU PRINCIPAL          \n");
    printf("==================================\n");
    printf("1 - Item 1\n");
    printf("2 - Item 2\n");
    printf("==================================\n");
    printf("Escolha uma opcão: ");
    scanf("&d", &opcao);
    getchar();

    switch (opcao){
    case 1:
        printf("teste switch");
        break;
    case 2:
        printf("Teste 2");
        break;
    default:
        printf("opção invalida, digite novamente");
            }
    return 0;
}

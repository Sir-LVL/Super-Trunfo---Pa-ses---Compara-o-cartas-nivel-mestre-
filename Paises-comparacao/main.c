#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int pontos_turi1, pontos_turi2, pontuacao1, pontuacao2;//Variaveis globais
    float area1, area2, pib1, pib2, pibcapi1,pibcapi2, densidade_popu1,
    densidade_popu2, densidade_inver1, densidade_inver2, super1, super2;
    unsigned long int populacao1, populacao2;
    char pais1[50], pais2[50];

void Cadastro(); //Declaração da Função

int main()
{
    int opcao;

    while(1) {
        printf("\n==================================\n");//Menu Principal
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
        case 1: //Opção Um e Principal
            Cadastro();
            break;
        case 2: //Opção semelhante o 'sobre mim'
            printf("Opa me chamo Lucas, sou estudante de Ciência da Computação, e você está executando um programa meu ;)");
            break;
        case 3: // Opção de Saída
            printf("Saindo...\n");
            printf("Aperte Enter para encerrar...");
            return 0;
        default: //Mensagem de erro para caso selecionar uma opção inexistente
            printf("opção invalida, digite novamente\n");
        }
    }
    return 0;
}

void Cadastro(){

    printf("\n===== CADASTRO DE PAISES =====\n");

    printf("Digite o nome do País 1: \n");
    fgets(pais1, 50, stdin);// Ler o nome do país
    pais1[strcspn(pais1, "\n")] = '\0';// retira o \n que fica armazenado junto com a variavel, assim corrigindo o erro do código ser 'pulado'

    printf("Digite a área de %s: \n", pais1);
    scanf("%f", &area1);

    printf("Digite a população de %s: \n", pais1);
    scanf("%lu", &populacao1);

    printf("Digite o PIB de %s: \n", pais1);
    scanf("%f", &pib1);

    printf("Quantos pontos turisticos tem %s? \n", pais1);
    scanf("%d", &pontos_turi1);

    densidade_popu1 = (float) populacao1 / area1; //calculo da densidade populacional

    pibcapi1 = pib1 / (float) populacao1; // Pib per Capita
    densidade_inver1 = 1 / densidade_popu1; // densidade invertida

    getchar();//retira o \n do buffer

    printf("\nDigite o nome do País 2: \n");
    fgets(pais2, 50, stdin);
    pais2[strcspn(pais2, "\n")] = '\0';

    printf("Digite a área de %s: \n", pais2);
    scanf("%f", &area2);

    printf("Digite a população de %s: \n", pais2);
    scanf("%lu", &populacao2);

    printf("Digite o PIB de %s: \n", pais2);
    scanf("%f", &pib2);

    printf("Quantos pontos turisticos tem %s? \n", pais2);
    scanf("%d", &pontos_turi2);

    densidade_popu2 = (float) populacao2 / area2;

    pibcapi2 = pib2 / (float) populacao2;

    densidade_inver2 = 1 / densidade_popu2;

    super1 = area1 + densidade_popu1 + densidade_inver1 + pib1 + pibcapi1 + populacao1 + pontos_turi1;//calculo do super poder
    super2 = area2 + densidade_popu2 + densidade_inver2 + pib2 + pibcapi2 + populacao2 + pontos_turi2;

    printf("Deu bom");
}

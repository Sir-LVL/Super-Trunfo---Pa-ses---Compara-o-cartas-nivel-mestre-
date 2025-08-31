#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    int pontos_turi1, pontos_turi2, pontuacao1, pontuacao2;//Variaveis globais
    float area1, area2, pib1, pib2, pibcapi1,pibcapi2, densidade_popu1,
    densidade_popu2, densidade_inver1, densidade_inver2, super1, super2;
    unsigned long int populacao1, populacao2;
    char pais1[50], pais2[50];

void Cadastro(); //Declaração da Função de cadastro
int validar_inteiro(char str[]); //  declaração de validação de um número inteiro
int ler_inteiro(); // declaracao da funcao
int validar_float(char str[]); // funcao de validar o float
float ler_float(); // funcao de ler o float
void MenuComparacao(); // menu de comparacao
int CompararTodos();

int main()
{ //teste
    int opcao;
    pontuacao1 = 0;// pontuacao dos paises
    pontuacao2 = 0;

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
    area1 = ler_float();

    printf("Digite a população de %s: \n", pais1);
    populacao1 = ler_inteiro();

    printf("Digite o PIB de %s: \n", pais1);
    pib1 = ler_float();

    printf("Quantos pontos turisticos tem %s? \n", pais1);
    pontos_turi1 = ler_inteiro();

    densidade_popu1 = (float) populacao1 / area1; //calculo da densidade populacional

    pibcapi1 = pib1 / (float) populacao1; // Pib per Capita
    densidade_inver1 = 1 / densidade_popu1; // densidade invertida

    printf("\nDigite o nome do País 2: \n");
    fgets(pais2, 50, stdin);
    pais2[strcspn(pais2, "\n")] = '\0';

    printf("Digite a área de %s: \n", pais2);
    area2 = ler_float();

    printf("Digite a população de %s: \n", pais2);
    populacao2 = ler_inteiro();

    printf("Digite o PIB de %s: \n", pais2);
    pib2 = ler_float();

    printf("Quantos pontos turisticos tem %s? \n", pais2);
    pontos_turi2 = ler_inteiro();

    densidade_popu2 = (float) populacao2 / area2;

    pibcapi2 = pib2 / (float) populacao2;

    densidade_inver2 = 1 / densidade_popu2;

    super1 = area1 + densidade_popu1 + densidade_inver1 + pib1 + pibcapi1 + populacao1 + pontos_turi1;//calculo do super poder
    super2 = area2 + densidade_popu2 + densidade_inver2 + pib2 + pibcapi2 + populacao2 + pontos_turi2;

    MenuComparacao();
}

int validar_inteiro(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // contém algo que não é número
        }
    }
    return 1; // só tem números
}

// Função para ler um inteiro seguro
int ler_inteiro() {
    char buffer[100];
    int numero;

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove o \n

        if (validar_inteiro(buffer)) {
            numero = atoi(buffer); // converte string para int
            return numero;
        } else {
            printf("Entrada inválida! Digite apenas números: ");
        }
    }
}

int validar_float(char str[]) {
    int ponto = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (ponto) return 0; // mais de um ponto → inválido
            ponto = 1;
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

float ler_float() {
    char buffer[100];
    float numero;

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (validar_float(buffer)) {
            numero = atof(buffer); // converte string para float
            return numero;
        } else {
            printf("Entrada inválida! Digite um número válido: ");
        }
    }
}

void MenuComparacao() {
    int opcao;

    while (1) {
        printf("\n==================================\n");
        printf("         %s VS %s      \n", pais1, pais2);
        printf("====================================\n");
        printf("1 - Comparar todos os Atributos\n");
        printf("2 - Comparar apenas 1 atributo\n");
        printf("3 - Mostrar Super Poder de cada país\n");
        printf("4 - Voltar ao menu principal\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");
        opcao = ler_inteiro();

        switch (opcao) {
        case 1:
        CompararTodos();
        MenuComparacao();
        break;

        case 2:
            printf("\nDensidade Populacional de %s: %.2f hab/km²\n", pais1, densidade_popu1);
            printf("Densidade Populacional de %s: %.2f hab/km²\n", pais2, densidade_popu2);
            break;

        case 3:
            printf("\nSuper Poder de %s: %.2f\n", pais1, super1);
            printf("Super Poder de %s: %.2f\n", pais2, super2);

            if (super1 > super2) {
                printf("%s é o país mais forte!\n", pais1);
            } else if (super2 > super1) {
                printf("%s é o país mais forte!\n", pais2);
            } else {
                printf("Empate técnico entre os dois países!\n");
            }
            break;

        case 4:
            main();
            return; //Retorna para o menu principal

        default:
            printf("Opcao invalida, tente novamente.\n");
        }
    }
}

int CompararTodos(){
        if (area1 > area2)  { //condições que observam qual país tem maior atributo
        ++pontuacao1; //aumenta o valor da pontuação se a condição for verdadeira
        printf("\nÁrea: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("Área: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (populacao1 > populacao2) {
        ++pontuacao1;
        printf("População: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("População: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (densidade_popu1 < densidade_popu2) {
        ++pontuacao1;
        printf("Densindade Populacional: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("Densindade Populacional: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (pontos_turi1 > pontos_turi2) {
        ++pontuacao1;
        printf("Pontos Turísticos: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("Pontos Turísticos: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (pib1 > pib2) {
        ++pontuacao1;
        printf("PIB: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("PIB: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (pibcapi1 > pibcapi2) {
        ++pontuacao1;
        printf("PIB Per Capita: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("PIB Per Capita: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (super1 > super2) {
        ++pontuacao1;
        printf("Super Poder: %s ganha. %s %d X %d %s\n", pais1, pais1, pontuacao1, pontuacao2, pais2);
        } else{
        ++pontuacao2;
        printf("Super Poder: %s ganha. %s %d X %d %s\n", pais2, pais1, pontuacao1, pontuacao2, pais2);
        }

        if (pontuacao1 > pontuacao2) { // Diz qual país tem a maior pontuação
        printf("\nO País Ganhador é %s!\n", pais1);
        } else {
        printf("\nO País Ganhador é %s!\n", pais2);
        }
}

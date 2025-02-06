// Projeto para o desafio de Super Trunfo para Faculdade (Estácio)
// Autor: Adriano Santos
// Nivel: Aventureiro
// Obs: O comando system("cls") da pau se usado no VScode, ele limpa a tela mas o terminal do VScode fica ilegível.
//      Para dar certo tem que rodar o executável direto no terminal ou comentar o comando. 



#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados das cartas de cidades
typedef struct
{
    char codigo[4];       // Código da carta (ex.: A01)
    int populacao;        // População da cidade
    float area;           // Área da cidade
    float pib;            // Produto Interno Bruto (PIB) da cidade
    int pontosTuristicos; // Número de pontos turísticos
    float densidadePop;
    float perCapta;
} CartaCidade;

int main()
{
    // Número de estados e cidades
    int numEstados = 8;
    int numCidadesPorEstado = 4;

    // vetor para armazenar as estruturas das cartas
    CartaCidade cartas[32];

    // Total das cartas
    int totalCartas = numEstados * numCidadesPorEstado;

    // array dos estados
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // incremento da carta que será adicionada.
    int incremento = 0;

    // ação da de operação do cadastro
    char acao = 's';

//label para cadastrar as cartas. 
cadastrar:
    if (incremento < 32 && acao == 's')
    {
        system("cls");
        printf("*************************************\n");
        printf("* Super Trunfo - Cadastro de cartas *\n");
        printf("*************************************\n\n");
        printf("Cadastro da carta %c%02d\n", estados[incremento / numCidadesPorEstado], (incremento % numCidadesPorEstado) + 1);


        // Pegar os dados e jogar no array (vetor)
        printf("Populacao da cidade: ");
        scanf("%d", &cartas[incremento].populacao);

        printf("Area da cidade: ");
        scanf("%f", &cartas[incremento].area);

        printf("PIB da cidade: ");
        scanf("%f", &cartas[incremento].pib);

        printf("Pontos turisticos da cidade: ");
        scanf("%d", &cartas[incremento].pontosTuristicos);

        cartas[incremento].densidadePop =  cartas[incremento].populacao / cartas[incremento].area;
        cartas[incremento].perCapta =  cartas[incremento].pib / cartas[incremento].populacao;

        printf("Digite s para cadastrar outra carta ou n para listar: ");
        scanf(" %c", &acao);
        
        incremento++;   

        if (acao == 's')
        {
            goto cadastrar;
        }else{
            goto listar;
        }

        printf("\n");
    }

// Exibição dos dados das cartas cadastradas
listar:    
    system("cls");
    printf("*************************************\n");
    printf("* Super Trunfo - Listagem de Cartas *\n");
    printf("*************************************\n\n");
    for (int i = 0; i < incremento; i++)
    {
        snprintf(cartas[i].codigo, sizeof(cartas[i].codigo), "%c%02d", estados[i / numCidadesPorEstado], (i % numCidadesPorEstado) + 1);
        printf("Carta: %s\n", cartas[i].codigo);
        printf("Populacao: %d\n", cartas[i].populacao);
        printf("Area: %.2f km^2\n", cartas[i].area);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
        printf("Renda Percapta: %.2f\n", cartas[i].perCapta);
        printf("Densidade: %.2f\n", cartas[i].densidadePop);
        printf("\n");
    }

    return 0;
}

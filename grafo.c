#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grafo C# possui 3 vertices e 2 arestas
struct g_csharp {
    int matriz[3][3];
};

struct g_csharp GrafoCSharp() {
    struct g_csharp csharp = {
        {
            {0, 1, 1},
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    return csharp;
}

int main()
{
    // Adicionar essa linha dentro de um switch talvez
    struct g_csharp csharp = GrafoCSharp();
    int i, j;

    // Controle da aplicacao
    int quit = 0;
    int grafoSelecionado = 0;

    while(quit != 1)
    {
        // Exibicao do Menu
        printf("\n--- Trabalho de FMC - Grafos --- \n\n\n");
        printf("Selecione um dos grafos a seguir:\n\n");
        printf("[1] C#\n");


        printf("[0] Encerrar aplicacao")

        printf("\n\n");
        printf("Digite a sua opcao: ");
        scanf("%d", &grafoSelecionado);

        switch(grafoSelecionado)
        {
            case 0:
                printf("\nAplicacao sendo encerrada...\n\n");
                quit = 1;
            break;

            case 1:

            break;

            default:
                printf("\nGrafo selecionado nao existe, por favor digite uma opcao valida!\n\n");
            break;
        }
        system("pause");
        system("cls");
    }


    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", csharp.matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

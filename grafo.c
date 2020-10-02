#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NODE 5
#define MAX_SIZE 100

char * ParaMinusculo(char * str);
void VerticeSelecionado(char * nomeDoVertice);

void traverse(int u, bool visited[]);
bool isConnected();
int isEulerian();

int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {0, 0, 0, 1, 0}
};

/*
 int graph[NODE][NODE] = {
   {0, 1, 1, 1, 1},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {1, 0, 0, 1, 0}
};
 */
    //uncomment to check Euler Circuit
/*
 int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 0, 0},
   {1, 1, 0, 0, 1},
   {0, 0, 0, 1, 0}
};
 */   //Uncomment to check Non Eulerian Graph

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

void DesenharGrafoCSharp() {
    struct g_csharp csharp = GrafoCSharp();
    int i, j;
    int vertices = 3;
    int aux;

    char nomeDoVertice[MAX_SIZE];

    // Desenha o grafo C#
    printf("\n--------------------------------------------------------------------------------------\n\n");
    printf("\nGrafo de C#:\n\n");

    printf("\t\t\t\t+-------+\n");
    printf("\t\t\t\t|   C#  |\n");
    printf("\t\t\t\t+-------+\n");
    printf("\t\t\t\t/\t\\\n");
    printf("\t\t\t       /\t \\\n");
    printf("\t+------------------------+\t +--------+\n");
    printf("\t|  Basicos da Linguagem  |\t |  LINQ  |\n");
    printf("\t+------------------------+\t +--------+\n");

    // Exibe a Matriz de Adjacencia
    printf("\nMatriz de Adjacencia:\n\n");

    printf("  ");
    for(i = 1; i <= 3; i++) {
        printf("%d ", i);
    }
    printf("\n");

    aux = 1;
    for(i = 0; i < 3; i++)
    {
        printf("%d ", aux);
        aux++;
        for(j = 0; j < 3; j++)
        {
            printf("%d ", csharp.matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSelecione um vertice digitando o nome: ");
    scanf("%s", &nomeDoVertice);

    VerticeSelecionado(nomeDoVertice);

    printf("\n--------------------------------------------------------------------------------------\n\n");

    printf("\n\n");
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


        printf("[0] Encerrar aplicacao");

        printf("\n\n");
        printf("Digite a sua opcao: ");
        scanf("%d", &grafoSelecionado);
        int check;

        switch(grafoSelecionado)
        {
            case 0:
                printf("\nAplicacao sendo encerrada...\n\n");
                quit = 1;
            break;

            case 1:
                //DesenharGrafoCSharp();

                check = isEulerian();
                printf("%d", check);
                if (check == 0) {
                    printf("\nThe graph is not an Eulerian graph.\n");
                }
                if (check == 1) {
                    printf("\nThe graph has an Eulerian path.\n");
                }
                if (check == 2) {
                    printf("\nThe graph has a Eulerian circuit.\n");
                }
            break;

            default:
                printf("\nGrafo selecionado nao existe, por favor digite uma opcao valida!\n\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

char * ParaMinusculo(char * str) {
    // Loop para transformar toda string para minisculo
    int i;

    for (i = 0; str[i]!='\0'; i++) {
       if(str[i] >= 'A' && str[i] <= 'Z') {
          str[i] = str[i] + 32;
       }
    }
    return str;
}

void VerticeSelecionado(char * nomeDoVertice) {

    nomeDoVertice = ParaMinusculo(nomeDoVertice);
    printf("%s", nomeDoVertice);
}

void traverse(int u, bool visited[])
{
   visited[u] = true; //mark v as visited

   for (int v = 0; v < NODE; v++)
   {
      if (graph[u][v])
      {
         if (!visited[v])
            traverse(v, visited);
      }
   }
}

bool isConnected()
{
   bool *vis;
   //for all vertex u as start point, check whether all nodes are visible or not
   for (int u; u < NODE; u++)
   {
      for (int i = 0; i < NODE; i++)
         vis[i] = false; //initialize as no node is visited

      traverse(u, vis);

      for (int i = 0; i < NODE; i++)
      {
         if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
            return false;
      }
   }
   return true;
}

int isEulerian()
{
   if (isConnected() == false) //when graph is not connected
      return 0;
   int degree[NODE];
   int oddDegree = 0;

   for (int i = 0; i < NODE; i++)
   {
      for (int j = 0; j < NODE; j++)
      {
         if (graph[i][j])
            degree[i]++; //increase degree, when connected edge found
      }

      if (degree[i] % 2 != 0) //when degree of vertices are odd
         oddDegree++;         //count odd degree vertices
   }

   if (oddDegree > 2) //when vertices with odd degree greater than 2
      return 0;

   return (oddDegree) ? 1 : 2; //when oddDegree is 0, it is Euler circuit, and when 2, it is Euler path
}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define NODE 5
#define MAX_SIZE 100

char * ParaMinusculo(char * str);
void VerticeSelecionado(char * nomeDoVertice);

// Grafo Euleriano
void traverse(int u, bool visited[]);
bool isConnected();
void isEulerian();

// Manipulacao de Arquivo
int **readmatrix(size_t *rows, size_t *cols, const char *filename);

/*
int graph[NODE][NODE] = {
   {0, 1, 1},
   {1, 0, 0},
   {1, 0, 0}
};
*/

/*
int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {0, 0, 0, 1, 0}
};
*/


 int graph[NODE][NODE] = {
   {0, 1, 1, 1, 1},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {1, 0, 0, 1, 0}
};

    //uncomment to check Euler Circuit
/*
 int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 0, 0},
   {1, 1, 0, 0, 1},
   {0, 0, 0, 1, 0}
};
*/
//Uncomment to check Non Eulerian Graph

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
    // File
    FILE *fp;
    char filename[20];

    // Adicionar essa linha dentro de um switch talvez
    struct g_csharp csharp = GrafoCSharp();
    int i, j;

    // Controle da aplicacao
    int quit = 0;
    int grafoSelecionado = 0;

    int check;
    int aux;

    int quantidadeVertices;

    while(quit != 1)
    {
        // Exibicao do Menu
        printf("\n--- Trabalho de FMC - Grafos --- \n\n\n");
        printf("Selecione um dos grafos a seguir:\n\n");
        printf("[1] C#\n");
        printf("[5] Ler Arquivo\n");


        printf("\n[0] Encerrar aplicacao");

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
                //DesenharGrafoCSharp();
                isEulerian();
            break;

            case 5:
                printf("\n--------------------------------------------------------------------------------------\n");
                printf("\nEnter a filename: ");
                scanf("%s", &filename);

                fp = fopen(filename, "r");

                if (fp == NULL)
                {
                    printf("Erro! O arquivo nao foi encontrado ou nao pode ser aberto.\n\n");
                    break;
                }

                size_t cols, rows;
                int **matrix = readmatrix(&rows, &cols, filename);

                if (matrix == NULL)
                {
                    fprintf(stderr, "Nao foi possivel ler a matriz.\n");
                    return 1;
                }

                printf("\nDigite a quantidade de vertices do grafo: ");
                scanf("%d", &quantidadeVertices);

                if (quantidadeVertices != rows || quantidadeVertices != cols) {
                    printf("\nErro! Quantidade de vertices inserida incompativel com a quantidade de vertices do arquivo.\n\n");
                    break;
                }

                // Exibe a Matriz de Adjacencia
                printf("\nMatriz de Adjacencia:\n\n");

                printf("  ");
                for(i = 1; i <= cols; i++) {
                    printf("%d ", i);
                }
                printf("\n");

                aux = 1;
                for (size_t i = 0; i < rows; ++i)
                {
                    printf("%d ", aux);
                    aux++;
                    for (size_t j = 0; j < cols; ++j)
                        printf("%d ", matrix[i][j]);
                    puts("");
                }
                puts("");

                // freeing memory
                for (size_t i = 0; i < rows; ++i)
                    free(matrix[i]);
                free(matrix);

            break;

            default:
                printf("\nOpcao nao existe, por favor digite uma opcao valida!\n\n");
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

void isEulerian()
{
    if (isConnected() == false) {
        printf("\nO grafo nao eh Euleriano.\n");
        return;
    }

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

    if (oddDegree > 2) {
        printf("\nO grafo nao e' Euleriano - Possui %d vertices de grau impar.\n\n", oddDegree);
        return;
    }

    // Quando oddDegree for 0 é um circuito Euleriano quando for 2 é um caminho Euleriano
    int check = (oddDegree) ? 1 : 2;

    switch(check) {
        case 1:
            printf("\nO grafo e' um caminho Euleriano.\n\n");
        break;

        case 2:
            printf("\nO grafo e' um circuito Euleriano.\n\n");
        break;
    }
    return;
}

int **readmatrix(size_t *rows, size_t *cols, const char *filename)
{
    if(rows == NULL || cols == NULL || filename == NULL)
        return NULL;

    *rows = 0;
    *cols = 0;

    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        fprintf(stderr, "Nao foi possivel abrir %s: %s\n", filename, strerror(errno));
        return NULL;
    }

    int **matrix = NULL, **tmp;

    char line[1024];

    while(fgets(line, sizeof line, fp))
    {
        if(*cols == 0)
        {
            // determine the size of the columns based on
            // the first row
            char *scan = line;
            int dummy;
            int offset = 0;
            while(sscanf(scan, "%d%n", &dummy, &offset) == 1)
            {
                scan += offset;
                (*cols)++;
            }
        }

        tmp = realloc(matrix, (*rows + 1) * sizeof *matrix);

        if(tmp == NULL)
        {
            fclose(fp);
            return matrix; // return all you've parsed so far
        }

        matrix = tmp;

        matrix[*rows] = calloc(*cols, sizeof *matrix[*rows]);

        if(matrix[*rows] == NULL)
        {
            fclose(fp);
            if(*rows == 0) // failed in the first row, free everything
            {
                fclose(fp);
                free(matrix);
                return NULL;
            }

            return matrix; // return all you've parsed so far
        }

        int offset = 0;
        char *scan = line;
        for(size_t j = 0; j < *cols; ++j)
        {
            if(sscanf(scan, "%d%n", matrix[*rows] + j, &offset) == 1)
                scan += offset;
            else
                matrix[*rows][j] = 0; // could not read, set cell to 0
        }

        // incrementing rows
        (*rows)++;
    }

    fclose(fp);

    return matrix;
}




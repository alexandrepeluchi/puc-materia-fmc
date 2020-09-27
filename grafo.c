#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define length 100

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

int main() {
    struct g_csharp csharp = GrafoCSharp();

    int i, j;

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

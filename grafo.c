#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define length 100

struct t_thing {
    int a[3][3];
};

struct t_thing retArr() {
    struct t_thing thing = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    };

    return thing;
}

int main() {
    struct t_thing thing = retArr();

    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ",thing.a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

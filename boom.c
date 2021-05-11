#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000


int main()
{
    int** a = malloc(sizeof(int*) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        a[i] = malloc(sizeof(int) * MAX);
        for (int j = 0; j < MAX; j++)
        {
            a[i][j] = 1;
        }
    }
}
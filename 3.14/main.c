#include<stdio.h>
#include<stdlib.h>
#define M_MAX 10

int isSafe(int x, int y, int **sol, int n)
{
    if ( x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1)
        return 1;
    else
        return 0;
}

void printSolution(int **sol, int n)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
    printf("\n");
}

void solveKnightTour(int x, int y, int stepNo, int **sol, int *xMove, int *yMove, int *solNo, int n)
{
    int k, next_x, next_y;
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol, n))
        {
            sol[next_x][next_y] = stepNo;
            if (stepNo == n * n - 1)
            {
                (*solNo)++;
                printf("Solution no %d:\n", *solNo);
                printSolution(sol,n);
            }
            solveKnightTour(next_x, next_y, stepNo + 1, sol, xMove, yMove, solNo, n);
            sol[next_x][next_y] = -1;// backtracking
        }
    }
}

int main()
{
    int m, k=0;
    scanf("%d", &m);

    int **sol = (int**)malloc(M_MAX * sizeof(int*));

    for (int x = 0; x < m; x++){
        sol[x]=(int*)malloc(M_MAX * sizeof(int));
        for (int y = 0; y < m; y++){
            sol[x][y] = -1;
        }
    }

    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0]  = 0;

    solveKnightTour(0, 0, 1, sol, xMove, yMove, &k, m);

    for(int x=0; x<m; x++)
        free(sol[x]);
    free(sol);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 50
#define MAX_M 50


int printSolution(int **a, int n, int m)
{
    printf("The solution matrix is: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isInLabyrinth(int x, int y, int n, int m)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return 0;
    return 1;
}

void findWay (int **a, int x, int y, int n, int m, int stepNo, int *xMove, int *yMove, int *solNo, int **ok)
{
    int next_x, next_y, k;
    if(x==0 || y==0 || x==n-1 || y==n-1)
    {
        (*solNo)++;
        printf("Solution no %d: \n", *solNo);
        printf("The exit is at position: %d, %d\n", x, y);
        printSolution(a,n,m);
    }

    for(k=0;k<4;k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(a[next_x][next_y]==1 && ok[next_x][next_y]==1)
        {
            if(next_x==0 || next_x==n-1 || next_y==0 || next_y==m-1)
            {
                a[next_x][next_y]=stepNo;
                ok[next_x][next_y]=0;
                (*solNo)++;
                printf("Solution no %d: \n", *solNo);
                printf("The exit is at position: %d, %d\n", next_x, next_y);
                printSolution(a,n,m);
                ok[next_x][next_y]=1;
                a[next_x][next_y]=1;
            }
            else
            {
                if(isInLabyrinth(next_x,next_y,n,m)==1)
                {
                    a[next_x][next_y]=stepNo;
                    ok[next_x][next_y]=0;
                    findWay(a, next_x, next_y, n, m, stepNo+1, xMove, yMove, solNo,ok);
                    ok[next_x][next_y]=1;
                    a[next_x][next_y]=1;
                }
            }
        }
    }
}

int main() {
    int n, m, x, y, k=0;
    printf("Please input coordinates of the initial position: \n");
    scanf("%d %d", &x, &y);
    printf("Please input the dimension of the matrix: \n");
    scanf("%d %d", &n, &m);
    printf("Please input the elements of the matrix (these should be 0 or 1): \n");
    int **a = (int **) malloc (MAX_N * sizeof(int*));
    int **ok = (int **) malloc (MAX_N * sizeof(int*));

    for(int i=0;i<n;i++){
        a[i] = (int *) malloc (MAX_M * sizeof(int));
        ok[i] = (int *) malloc (MAX_M * sizeof(int));
        for(int j=0;j<m;j++)
        {
            scanf("%d", &a[i][j]);
            ok[i][j]=1;
        }
    }

    int xMove[4] = {1, 0, -1, 0};
    int yMove[4] = {0, 1, 0, -1};

    findWay(a,x,y,n,m,2,xMove,yMove,&k,ok);

    for(int i=0;i<n;i++){
        free(a[i]);
        free(ok[i]);
    }
    free(a);
    free(ok);
    return 0;
}
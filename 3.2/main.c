#include <stdio.h>

int hn (int x, int n);

int h0(int x)
{
    return 1;
}

int h1(int x)
{
    return 2*x;
}

int hn(int x, int n)
{
    if(n==0)
        return h0(x);
    else
    if(n==1)
        return h1(x);
    else
        return 2 * n * hn(x,n-1) - 2* (n-1)  * hn(x,n-2);
}

int hn_iterative(int x, int n)
{
    int a0, a1, result;
    a0=1;
    a1=2*x;
    if(n==0)
        return 1;
    else
    if(n==1)
        return 2*x;
    else
    {
        for(int i=2;i<=n;i++)
        {
            result =  2 * i * a1 - 2 * (i - 1) * a0;
            a0=a1;
            a1=result;
        }
        return result;
    }
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    printf("the result using the recursive function: %d\n", hn(x,n));
    printf("the result using the non-recursive function: %d\n", hn_iterative(x,n));
    return 0;
}
#include<stdio.h>


int F(int n)
{
    return n == 1 ? 1 : F(n/2) + 1;
}


int main ()
{
    int n;
    while(~scanf("%d" ,&n))
    {
       printf("%d\n" ,F(n));
    }
    return 0;
}
    
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
int flag = 0;
int count = 0;
int main(void)
{
    int n, m, a[80];
    int j, i;
    system("COLOR f3");
    printf("Enter n:");
    scanf("%d", &n);
    printf("Enter m:");
    scanf("%d", &m);
 
    for (i = 1; i <= n; i++)
        a[i] = 0;
    // for (i = 1; i <= n; i++)
    //     printf("%d", a[i]);
 
    while (flag<n)
    {
        for (i = 1; i <= n; i++)
        {
 
            if (a[i] == 0)//==
            {
 
                count++;
                if (count%m == 0)
                {
                    a[i] = 1;
                    flag++;
                    printf("%d \n", i);
					// cout << flag << i << endl;
				}
			}
            /*else
                break;*/
        }
    }
 
    return 0;
 
}
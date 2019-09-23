#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include<vector>

using namespace std;

/**
 * Welcome to vivo !
 */

typedef struct _node
{
    int num;
    struct _node * next;
}node;

void solution(int N, int M)
{
	// TODO Write your code here
    int flag = 0;
    int count = 0;
    int n=N;
    int m = M;
    // int a[80];
    vector<int> a;
    a.push_back(0);
    for (int i = 1; i <= n; i++)
        a.push_back(0);
    // for (i = 1; i <= n; i++)
    //     printf("%d", a[i]);
 
    while (flag<n)
    {
        for (int i = 1; i <= n; i++)
        {
 
            if (a[i] == 0)//==
            {
 
                count++;
                if (count%m == 0)
                {
                    a[i] = 1;
                    flag++;
                    printf("%d ", i);
					// cout << flag << i << endl;
				}
			}
            /*else
                break;*/
        }
    }
    
}

int main()
{
	int N;
	int M;
	
	string str("");
	getline(cin, str);
	
	char *p;
	const char* strs = str.c_str();
	
	p = strtok((char *)strs, " ");
	N = atoi(p);

	p = strtok(NULL, " ");
	M = atoi(p);
	
	solution(N, M);
	
	return 0;
}
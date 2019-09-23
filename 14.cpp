#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

/**
* Welcome to vivo
*/

#define MAX_NUM 101

int solution(int n, int weight[]) {

    // TODO Write your code here
	int N = n;
	int A[N] = weight[];
	char flag[N][N];
	int sum = 0;
	for (int i = 0; i < n;i++)
		sum += A[i];
	for (int i = 0; i < N + 1; i++)
		for (int j = 0; j < sum / 2 + 1; j++)
			flag[i][j] = false;      
	flag[0][0] = true;      
	for(int k = 1; k <= 2*N; k++) {      
		for(int i = k > N ? N : k; i >= 1; i--) {      //这点有点难以理解啊
			//两层外循环是遍历集合S(k,i)      
			for(int j = 0; j <= sum/2; j++) {      
				if(j >= A[k] && flag[i-1][j-A[k]])      
					flag[i][j] = true;      
			}      
		}      
	}      
	for(int i = sum/2; i >= 0; i--) {      
		if(flag[N][i]) {      
			// cout << "minimum delta is " << abs(2*i - sum) << endl;      //求最小的差值
			return abs(2 * i - sum);
			break;
		}      
	}   

    return 1;
}

int main()
{    
	string str("");
	getline(cin, str);
	int a[MAX_NUM];
	int i = 0;
	char *p;
	int count = 0;
	
	const char* strs = str.c_str();
	p = strtok((char *)strs, " ");
	while(p)
	{
		a[i] = atoi(p);
		count++;
		p = strtok(NULL, " ");
		i++;
		if(i >= MAX_NUM)
			break;
	}
	
	int result = solution(count, a);
	cout << result << endl;
	return 0;
}
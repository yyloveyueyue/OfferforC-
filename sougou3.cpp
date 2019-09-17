#include <iostream>
#include <cmath>    // for sqrt()


 
using namespace std;
 
int numberofno(int a){
    int num = a;
    int sum = 1;
    int geshu = 1;
    bool flag;
    int t = num;
    for (int i = 2;i<num;i++){
        flag = true;
        for (int m = 2; m < sqrt(i);m++){
            if(i%m==0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            while(t%i==0){
                sum=sum*i;
                if(sum<num){
                    // cout << i << "*";
                    geshu++;
                }
                // else if(sum==num)
                //     cout << i << endl;
                t = t / i;    
                
               
            } 
        }
    }
    return geshu;
}

bool isprime(int a)
{
 if(a<13)
  if(a<=1 || a==4 || a==6 || a==8 || a==9 || a==10 || a==12)
   return false;
  else
   return true;
 else
  if((a+1)%6==0 || (a-1)%6==0)
   if(a%2!=0)
    for(int i=4;i*i<=a;i%2!=0)
     if(a%i==0)
      return false;
     else
      i++;
   else
    for(int i=4;i*i<=a;i++)
     if(a%i==0)
      return false;
 return true; 
}


int main() {
	// cout << 2 << endl; //2是质数
    int n = 0;
    cin >> n;
    int number = 1;
    // for (int i = 3; i <= n; i ++) { //偶数不是质数，步长可以加大
	// 	float temp = static_cast<float>(i);
	// 	int mid = static_cast<int>(sqrt(temp));
	// 	int j;
	// 	for (j = 3; j <= mid; j++)//i是奇数，当然不能被偶数整除，步长也可以加大。
	// 		if (i % j == 0)
	// 			break;
 
	// 	if (j > mid){
    //         number++;
    //         cout << 1;
    //     }
    //     else
    //     {
    //         number = number + numberofno(i);
    //         cout << numberofno(i);
    //     }
        

			
	// }
    if(n==2){
        cout << 1;
    }  else{

    
        for (int i = 3; i <= n; i ++){
            if(isprime(i))
                number++;
            else
                {number = number + numberofno(i);
                    // cout << numberofno(i);
                }
        
        }
        cout << number << endl;
    }
    return 0;
}
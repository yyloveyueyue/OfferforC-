#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


float computer(float a,float b)
{
    if(b<=0)
        return 1;
    if(a<=0)
        return 0;
     if(a==1&&b==1)
        return 0.5;   
    if(a==2&&b==1)
        return 2.0 / 3;
    if(a==1&&b==2)
        return 1.0 / 3;
    float da1 = (b / (a + b)) * ((b - 1) / (a + b - 1));
    float da2 = (a / (a + b - 2)) * computer(a - 1, b - 2) + ((b-2)/(a+b-2))*computer(a,b-3);
    float da3 = a / (a + b);
    return da1 * da2 + da3;

}


int main()
{
    float *a = new float[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> a[i];
    }

    float data = computer(a[0], a[1]);
    printf("%.5f", data);
    // cout << data;
    return 0;

}


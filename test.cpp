#include <iostream>
#include <string>
#include <vector>
#include "stdio.h"
#include<sstream>
#include <cstring> 
using namespace std;

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k == 1)    return 0;
        int l = 0,sum = 0,res = 1;
        for(int r=0;r<nums.size();++r){
            res *= nums[r];
            while(res >= k){
                res /= nums[l];
                l++;
            }
            sum += (r-l+1);
        }
        return sum;
    }


int main()
{
    string s;
    vector<int> v;
    getline(cin, s);
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter)
    {
         v.push_back(inter);
         is >> ch;
    }
    int k = 0;
    cin >> k;
    int result1 = numSubarrayProductLessThanK(v, k);
    cout << result1;
    return 0;
}
#include<iostream>
#include<vector>
#include <algorithm>
#include<math>
using namespace std;

int findfirst(float*xy,int n)
{
    for (int i = 0; i < n;i++){
        if (xy[i+4]>0){
            continue;
        }else
        {
            return i;
            break;
        }
        
        }return -1;
}

int findnext(float*xy,int n ,int first,int R,vector<int>v){
    for (int i = 0; i < n;i++){
        vector<int>::iterator it=find(v.begin(),v.end(),i);
        if (it!=v.end()){
            continue;
        }else if (sqrt((xy[first]-xy[i])*(xy[first]-xy[i])+(xy[first+1]-xy[i+1])*(xy[first+1]-xy[i+1]))>=R)
        {
            continue;
        }else
        {
            return i;
            break;
        }
        result -1;
    }
}

int main(){
    int n=0;
    cin >> n;
    float R = 0;
    cin >> R;
    float D=0;
    cin >> D;
    int totaln = 6 * n;
    float *xy = new float[totaln];
    for (int i =0; i < n; i++)
    {
        cin >> xy[i];
        cin >> xy[i + 1];
        xy[i + 2] = xy[i] - R;
        xy[i + 3] = xy[i] + R;
        xy[i + 4] = xy[i+1] - R;
        xy[i + 5] = xy[i+1] + R;
    }
    int resultoffirst = findfirst(xy, n);
    int resultofnext = 0;
    char result = 'N';
    vector<int> v;
    if(resultoffirst==-1){
         result = 'N';
    }else if(resultofnext!=-1){
        v.push_back(resultoffirst);
        resultofnext = findnext(xy, n, R, v);
        v.push_back(resultofnext);
    }
    
    


    

}
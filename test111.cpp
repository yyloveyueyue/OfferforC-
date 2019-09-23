#include<iostream>
#include<vector>
using namespace std;




int main(){
    vector<vector<int>> vv = {{1, 3, 9, 2, 6}, {4, 2, 9, 16, 7}};
    
    int rows = vv.size();
    for (int i = 0; i < rows;i++){
        vector<int> maxlens;
        int cows = vv[i].size();
        
        for (int j = cows - 1; j >= 0;j--){
            int max_len = 1;
            int chazhi = vv[i][j];
            for (int m = j - 1; m >= 0;m--){
                if(vv[i][m]>=chazhi){
                    maxlens.push_back(max_len);
                    break;
                }
                else if(vv[i][m]<=vv[i][m+1]){
                    chazhi = chazhi - vv[i][m];
                    max_len++;
                }
            }
            maxlens.push_back(max_len);

        }
        int temp = 0;
        for (int i = 0; i < maxlens.size();i++){
            if (temp<maxlens[i])
                temp = maxlens[i];
            
        }
        cout << temp << endl;
    }

    // cout << vv[0][0] << endl;
    // cout << vv.size() << endl;
    // cout << vv[0].size() << endl;
    return 0;
}
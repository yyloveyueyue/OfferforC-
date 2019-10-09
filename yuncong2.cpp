#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <string> 
#include <sstream>   
using namespace std;   
int main() {     
    string raw_data, tmp;
    cin >> raw_data;
    vector<string> data;     
    stringstream input(raw_data);      
    while (getline(input, tmp, ',')) 
        data.push_back(tmp);
    vector<int> vv;
    for (auto s : data) 
        vv.push_back(stoi(s)) ;      
    return 0; 
}
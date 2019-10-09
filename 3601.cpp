#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    vector<int> aa;
    vector<int> tt;
    multimap<int, int> ta;
    multimap<int, int> tat;
    float lengths = 0;
    for (int i = 0; i < num;i++)
    {
        int a = 0;
        cin >> a;
        int t = 0;
        cin >> t;
        aa.push_back(a);
        tt.push_back(t);
        lengths += 0.5 * a * t * t;
        ta.insert(make_pair(t, a));
        tat.insert(make_pair(t*a, t ));



    }

    float lengths1 = 0;
    for (multimap<int, int>::iterator it = tat.end(); it != tat.begin();it--)
    {
        float lengths2 = it->first;
        for (multimap<int, int>::iterator itt = (it-1); itt != tat.begin();itt--)
        {
            lengths2 *= itt->second;
        }
        lengths1 += lengths2;
    }

    lengths += lengths1;
    cout << lengths << endl;

    return 0;


}
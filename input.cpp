#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //一、以空格为间隔的数组
    // input:
    // 5
    // 1 2 3 4 5
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    //二、不定长输入，以空格为间隔的数组
    // input:
    // 1 2 3 4 5
    int number;
    vector<int> v;
    while (1)
    {
        cin >> number;
        v.push_back(number);
        if (cin.get() == '\n')
            break;
    }

    //三、不定长输入，带空格的，回车结束的字符串
    // input:
    // dfaj djfa.
    string s;
    getline(cin, s);

    //四、数字以逗号间隔

    //套一个while t

}

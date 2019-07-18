/*
替换空格
题目：将字符串中的每个空格替换为“%20”
思路：从前往后遍历，碰到空格就替换，需要把空格后的字符后移2个字节，时间复杂度O(n^2)。从后往前考虑，设置两个指针，时间复杂度O(n)
 */

#include<iostream>
using namespace std;
void ReplaceBlack( char string[], int length)
{
    
    if (string == NULL &&length<0)
    {
        return;
    }
    int originalLength = 0;
    int numberofBlank = 0;
    int i = 0;
    while(string[i]!='\0')
    {
        originalLength++;
        if(string[i]==' ')
        {
            numberofBlank++;
        }
        i++;
    }

    int newLength = originalLength + numberofBlank * 2;
    if(newLength>length)
    {
        return;
    }
    int indexofOld = originalLength;
    int indexofNew = newLength;
    while(indexofOld>=0 && indexofNew>indexofOld)
    {
        if(string[indexofOld]==' ')
        {
            string[indexofNew--] = '0';
            string[indexofNew--] = '2';
            string[indexofNew--] = '%';

        }
        else
        {
            string[indexofNew--] = string[indexofOld];
            
        }
        indexofOld--;
        }
}


void test01()
{
    char str[20] = "abc abc abc";
    ReplaceBlack(str, 20);
    cout << str << endl;


}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}
/*
二维数组的查找
题目：给定一个二维数组，每一行从左往右递增，每一列从上往下递增，查找书否含有一个整数。
思路：从右上角开始查找，若正好相等，查找结束，若需要查找的数比右上角小，删除当前列，反之删除当前行。
 */

#include<iostream>
using namespace std;

bool Find(int* matrix, int rows,int cols, int number)
{
    bool found = false;
    if (matrix!=NULL && rows>=1 && cols>=0)
    {
        int row = 0;
        int col = cols - 1;
        while(row<rows && col>=0)
        {
            if (matrix[row*cols+col]==number)
            {
                found = true;
                break;
            }
            else if(matrix[row*cols+col]>number)
            {
                col--;
            }
            else
            {
                row++;
            }
            
            
        }
    }
    return found;
}


void test01()
{
    int matrix[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
    int rows = 4;
    int cols = 4;
    int number = 7;
    bool result = Find(matrix, rows, cols, number);
    cout << result << endl;
}

void test02()
{
    int matrix[2][2] = {1, 2, 3, 4};
    cout << "matrix: " << matrix << endl;
    cout << "*matrix: " << *matrix << endl;
    cout << "**matrix: " << **matrix << endl;
    cout << "*(*matrix+1): " << *(*matrix+1) << endl;
    cout << "*(*(matrix+1)+1):   " << *(*(matrix+1)+1) << endl;



}

int main()
{
    // test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;
}
/*
重建二叉树
题目：输入某二叉树的前序遍历和中序遍历的结果，重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 */


#include<iostream>
#include<exception>
#include<string>
using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;

};

BinaryTreeNode *ConstructCore(int *startPre, int *endPre, int *startIno, int *endIno);

BinaryTreeNode* Construct(int* preoder, int* inorder, int lenght)
{
    if(preoder==nullptr||inorder==nullptr||lenght<=0)
    {
        return nullptr;
    }
    return ConstructCore(preoder, preoder + lenght - 1, inorder, inorder + lenght - 1);
}


BinaryTreeNode *ConstructCore(int *startPre, int *endPre, int *startIno, int *endIno)
{
    //前序遍历第一个数据就是根节点的值
    int rootValue = startPre[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_value = rootValue;
    root->m_left = NULL;
    root->m_right = NULL;

    //如果只有一个节点，就是根节点，直接输出，但中序遍历和前序遍历值不同，说明输入数据错误
    if(startPre==endPre)
    {
        if(startIno==endIno && *startPre==*startIno)
        {
            return root;
        }
        else
        {
            cout << "Invalid input" << endl;
            return nullptr;
        }
        
    }
    //在中序遍历中找到根节点的值
    int * rootInorder = startIno;
    while(rootInorder<=endIno&& *rootInorder!=rootValue)
    {
        ++rootInorder;
    }

    if(rootInorder==endIno&&*rootInorder!=rootValue)
    {
        cout << "Invalid input" << endl;
        return nullptr;
    }

    int leftLength = rootInorder - startIno;
    int *leftPreEnd = startPre + leftLength;

    if(leftLength>0)
    {
        root->m_left = ConstructCore(startPre + 1, leftPreEnd, startIno, rootInorder - 1);
    }
    if(leftLength< endPre-startPre)
    {
        root->m_right = ConstructCore(leftPreEnd + 1, endPre, rootInorder + 1, endIno);
    }
    return root;
}

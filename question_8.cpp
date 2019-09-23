/* 
寻找下一个节点
问题描述：给定一个二叉树和其中的一个节点，找出中序遍历中的下一个节点。树中的节点除了有左右子节点，还有指向父节点的指针。
分析：1.如果一个节点有右子树，那门右子树中的最左节点就是下一个节点
     2。如果没有右子树：2.1 节点是其父节点的左节点，那门下一个节点就是父节点
     2.2 既没有右子树，又是父节点的右子树，需要沿着指向父节点的指针向上遍历，直到碰到一个节点是其父节点的左节点，那门这个父节点就是我们要找的
*/

#include<stdio.h>


struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode *m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode==nullptr)
        return nullptr;

    BinaryTreeNode *pNext = nullptr;
    //情况1的判断
    if(pNode->m_pRight !=nullptr)
    {
        BinaryTreeNode *pRight = pNode->m_pRight;
        while(pRight->m_pLeft!=nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    else if(pNode->m_pParent!=nullptr)  //情况2也需要判断父节点不为0，特例只有一个节点的情况
    {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_pParent;

        while(pParent!=nullptr && pCurrent==pParent->m_pRight)  //2.1 2.2 情况往上遍历
        {
            pCurrent = pParent;
            pParent = pCurrent->m_pParent;
        }
        return pParent;
    }
    return pNext;
}


//=========辅助代码用来构建二叉树===============
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent!=nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft!=nullptr)
            pLeft->m_pParent = pParent;
        if(pRight!=nullptr)
            pRight->m_pParent = pParent;
    }
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode!=nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);
    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }



}


void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}


//=================测试代码========================
void Test(char* testName,BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if (testName!=nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode *pNext = GetNext(pNode);
    if(pNext==expected)
        printf("Passed.\n");
    else
    {
        printf("Failed.\n");
    }
    
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

    DestroyTree(pNode8);
}


int main(int argc, char* argv[])
{
    Test1_7();
    return 0;
}
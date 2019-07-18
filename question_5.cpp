#include<iostream>
#include<stack>
using namespace std;

//定义一个链表结构
class Node
{
 public:  
    int value;
    Node *next;
};

class ListNode
{
public:
    ListNode()
    {
        head = new Node;
        head->value = 0;
        head->next = NULL;
    }

    //尾插法
    void InsertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
        Node *p = head;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = newNode;
        }
        
    }

public:
    Node *head; //头结点
};


void PrintListReverse(Node* pHead)
{
    stack<Node *> nodes;
    Node *pNode = pHead;
    while (pNode !=NULL)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->value << endl;
        nodes.pop();
    }
    
}

void test()
{
    ListNode list;
    list.InsertEnd(1);
    list.InsertEnd(2);
    list.InsertEnd(3);
    list.InsertEnd(4);
    list.InsertEnd(5);
    PrintListReverse(list.head);

}


int main()
{
    test();
    system("pause");
    return EXIT_SUCCESS;
}
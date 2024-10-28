//用栈反转链表
#include<iostream>
#include<stack>
using namespace std;

struct Node* head; //定义head为全局变量

struct Node
{
    int data;
    Node* next;
};

struct Node* GetNewNode(int x)
{
    Node* node=new Node();  //在堆上创建一个新对象
    node->data=x;
    node->next=NULL;
    return node;
}

void Insert(int x)
{
    Node* temp=GetNewNode(x);
    temp->next=head;
    head=temp;
}

void Print()
{
    Node* temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}

void Reverse()
{
    stack<Node*> S; //这个栈中存放元素的类型为指向结构体Node的指针
    Node* temp=head;
    while(temp!=NULL)
    {
        S.push(temp);   //将链表的值压入栈中
        temp=temp->next;    
    }
    
    Node* temp1=S.top();    
    head=temp1;         //此时将head指向栈顶元素
    S.pop();            //更新栈顶元素
    while (!S.empty())  //栈顶非空时进入循环
    {
        temp1->next=S.top();    //开始反转链表
        S.pop();
        temp1=temp1->next;
    }
    temp1->next=NULL;   //一定要更新链表末尾为NULL
}


int main()
{
    head=NULL;

    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();
    printf("\n");

    Reverse();
    Print();

    return 0;
}
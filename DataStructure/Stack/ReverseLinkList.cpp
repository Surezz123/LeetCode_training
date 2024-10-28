//��ջ��ת����
#include<iostream>
#include<stack>
using namespace std;

struct Node* head; //����headΪȫ�ֱ���

struct Node
{
    int data;
    Node* next;
};

struct Node* GetNewNode(int x)
{
    Node* node=new Node();  //�ڶ��ϴ���һ���¶���
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
    stack<Node*> S; //���ջ�д��Ԫ�ص�����Ϊָ��ṹ��Node��ָ��
    Node* temp=head;
    while(temp!=NULL)
    {
        S.push(temp);   //�������ֵѹ��ջ��
        temp=temp->next;    
    }
    
    Node* temp1=S.top();    
    head=temp1;         //��ʱ��headָ��ջ��Ԫ��
    S.pop();            //����ջ��Ԫ��
    while (!S.empty())  //ջ���ǿ�ʱ����ѭ��
    {
        temp1->next=S.top();    //��ʼ��ת����
        S.pop();
        temp1=temp1->next;
    }
    temp1->next=NULL;   //һ��Ҫ��������ĩβΪNULL
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
//����ʵ�ֶ���
#include <iostream>
#include <list>   //�����Ѿ���װ�õ�����

using namespace std;

struct Node
{
    int value;
    Node* next;
};
Node* head = nullptr;   //���ﶨ��rear��ԭ������ΪҪƥ����г��Ӻ���ӵ�ʱ�䶼ΪO(1)
Node* rear = nullptr;   //���ʱ����Ҫͷ��β������һ��

Node* GetNewNode(int x) //�����½ڵ�
{
    Node* node =new Node();
    node->value=x;
    node->next=NULL;

    return node;
}

int Dequeue()  //���Ӻ���(ʱ�临�Ӷ�ΪO(1))�������������ʱҪƥ��ʱ�临�Ӷ�ֻ�ܴ�ͷ�ڵ���ӣ�����ʱ����ֵ
{
    Node* temp=head;
    int value;
    if (head==NULL) //�������޽ڵ�
    {
        cout<< "The queue is empty!" << "\n";
        cout<< "Can not Dequeue!" <<endl;
        return 0;
    }   

    if (head==rear) //�����н�һ�ڵ�
    {
        head=rear=NULL;
    }
    else    //�����ж���ڵ�
        head=head->next;

    value=temp->value;
    free(temp); //�������������ȡ�����ӻ���������Ҫ�ͷŸýڵ���ڴ�
    return value;
}

void Enqueue(int x)  //��Ӻ���(ʱ�临�Ӷ�ΪO(1))�����ʱ�Ӷ�β���
{
    Node* ptr=GetNewNode(x);

    if (head==NULL && rear==NULL)   //������û�нڵ�ʱ����ʱͷ��β��ָ���һ���ڵ㣬�൱�������ʼ��
    {
        head=rear=ptr;
        return;
    }
    rear->next=ptr; //�½ڵ㽨������
    rear=ptr;       //����βָ��

    //free(ptr);
    
    // ���ﲻ�ܱ�����������ʱ�临�ӶȾͱ�Ϊ��O(n)
    // temp=head;
    // while (temp->next!=NULL)    //���������һ���ڵ�
    // {
    //     temp=temp->next;
    // }
    // rear=temp;  //����βָ��
}   

bool IsEmpty()
{
    if (head==NULL)
        return 1;
    else
        return 0;
    
}

//������ʵ�ֲ�����full�����
// void IsFull()
// {

// }

int main()
{
    int value=0;
    Enqueue(2);
    Enqueue(4);
    Enqueue(6);
    Enqueue(8);

    Node* temp=head;
    while (temp != NULL)
    {
        cout<< temp->value <<" ";
        temp=temp->next;
    }

    cout<< "\n";
    value=Dequeue();
    cout<< value <<"\n";
    
    temp=head;
    while (temp != NULL)
    {
        cout<< temp->value <<" ";
        temp=temp->next;
    }
}

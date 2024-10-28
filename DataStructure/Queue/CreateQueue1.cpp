//链表实现队列
#include <iostream>
#include <list>   //包含已经封装好的链表

using namespace std;

struct Node
{
    int value;
    Node* next;
};
Node* head = nullptr;   //这里定义rear的原因是因为要匹配队列出队和入队的时间都为O(1)
Node* rear = nullptr;   //这个时候需要头跟尾都更新一下

Node* GetNewNode(int x) //创建新节点
{
    Node* node =new Node();
    node->value=x;
    node->next=NULL;

    return node;
}

int Dequeue()  //出队函数(时间复杂度为O(1))，单向链表出队时要匹配时间复杂度只能从头节点出队，出队时返回值
{
    Node* temp=head;
    int value;
    if (head==NULL) //队列中无节点
    {
        cout<< "The queue is empty!" << "\n";
        cout<< "Can not Dequeue!" <<endl;
        return 0;
    }   

    if (head==rear) //队列中仅一节点
    {
        head=rear=NULL;
    }
    else    //队列中多个节点
        head=head->next;

    value=temp->value;
    free(temp); //仅把其从链表中取消链接还不够，还要释放该节点的内存
    return value;
}

void Enqueue(int x)  //入队函数(时间复杂度为O(1))，入队时从队尾入队
{
    Node* ptr=GetNewNode(x);

    if (head==NULL && rear==NULL)   //链表中没有节点时，此时头和尾都指向第一个节点，相当于链表初始化
    {
        head=rear=ptr;
        return;
    }
    rear->next=ptr; //新节点建立连接
    rear=ptr;       //更新尾指针

    //free(ptr);
    
    // 这里不能遍历，遍历了时间复杂度就变为了O(n)
    // temp=head;
    // while (temp->next!=NULL)    //遍历到最后一个节点
    // {
    //     temp=temp->next;
    // }
    // rear=temp;  //更新尾指针
}   

bool IsEmpty()
{
    if (head==NULL)
        return 1;
    else
        return 0;
    
}

//用链表实现不存在full的情况
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

//����ʵ�ֶ���(ʵ��ʱҪ��˳�����Ӳ�����ʱ�临�Ӷ�)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int front=-1,rear=-1;
int size=10;

int IsEmpty()
{
    if(front==-1 && rear==-1) //front==rearҲ������������
        return 1;
    else
        return 0;
}

int IsFull()
{
    if((rear+1+size)%size == front)   //ѭ����������������ʱ��ʱ��������
        return 1;
    else
        return 0;
}

void Dequeue()  //���Ӻ���
{
    if(IsEmpty())
    {
        printf("The queue is empty!\n");
    }
    else
    {
        rear=(rear-1+size)%size;    //ѭ�������е�0����ʱ��9����֤rear�Ǹ�

    }
}

void Enqueue(int x,int *A)  //��Ӻ���
{
    if(IsFull())    //����Ϊ��
    {
        printf("The queue is full!\n");
    }
    else if(IsEmpty())  //����Ϊ��
    {
        front=rear=0;
    }
    else    //������ֵ
    {
        rear=(rear+1+size)%size;    //ѭ������
    }
    A[rear]=x;
}


int main()
{
    int A[10];
    Enqueue(2,A);
    Enqueue(3,A);
    Enqueue(4,A);
    Enqueue(5,A);
    Dequeue();
    
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",A[i]);
    }
    
}

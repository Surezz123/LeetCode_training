//数组实现队列(实现时要兼顾出队入队操作的时间复杂度)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int front=-1,rear=-1;
int size=10;

int IsEmpty()
{
    if(front==-1 && rear==-1) //front==rear也可能是满队列
        return 1;
    else
        return 0;
}

int IsFull()
{
    if((rear+1+size)%size == front)   //循环数组中条件成立时此时队列已满
        return 1;
    else
        return 0;
}

void Dequeue()  //出队函数
{
    if(IsEmpty())
    {
        printf("The queue is empty!\n");
    }
    else
    {
        rear=(rear-1+size)%size;    //循环数组中当0出队时到9，保证rear非负

    }
}

void Enqueue(int x,int *A)  //入队函数
{
    if(IsFull())    //队列为满
    {
        printf("The queue is full!\n");
    }
    else if(IsEmpty())  //队列为空
    {
        front=rear=0;
    }
    else    //队列有值
    {
        rear=(rear+1+size)%size;    //循环数组
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

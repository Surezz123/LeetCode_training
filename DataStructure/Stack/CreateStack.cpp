//����ʵ��ջ
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int size=10;
int top=-1; //ջΪ��ʱȡջ��Ϊ-1


int IsEmpty() //�ж��Ƿ�Ϊ��
{
    if (top==-1)
    {
        return 1;
    }
    else
        return 0;
}

int IsFull() //�ж��Ƿ�Ϊ��
{
    if (top==size)
    {
        return 1;
    }
    else 
        return 0;
}

int Top(int *A) //ȡջ��ֵ
{
    return A[top];  //ֱ�ӷ���ջ��ֵ
}

void Pop()  //��ջ����
{
    if (IsEmpty())  //ջΪ��ʱ�޷���ջ
    {
        printf("The stack is empty!\n");
        return;
    }
    else
    {
        top=top-1;
    }
}
void Push(int x,int *A)  //��ջ����
{
    if (IsFull()) //ջ��ʱ�޷���ջ
    {
        printf("The stack is full!\n");
        return;
    }
    else
    {
        top=top+1;  //ջΪ��Ҳ����
        A[top]=x;
    }
}

int main()
{
    int A[size];
    int a;

    Push(2,A);
    Push(4,A);
    Push(6,A);
    Push(8,A);
    Pop();

    for (int i = 0; i <= top; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    a=Top(A);
    printf("%d",a);

}
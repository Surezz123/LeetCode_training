//数组实现栈
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int size=10;
int top=-1; //栈为空时取栈顶为-1


int IsEmpty() //判断是否为空
{
    if (top==-1)
    {
        return 1;
    }
    else
        return 0;
}

int IsFull() //判断是否为空
{
    if (top==size)
    {
        return 1;
    }
    else 
        return 0;
}

int Top(int *A) //取栈顶值
{
    return A[top];  //直接返回栈顶值
}

void Pop()  //出栈函数
{
    if (IsEmpty())  //栈为空时无法出栈
    {
        printf("The stack is empty!\n");
        return;
    }
    else
    {
        top=top-1;
    }
}
void Push(int x,int *A)  //入栈函数
{
    if (IsFull()) //栈满时无法入栈
    {
        printf("The stack is full!\n");
        return;
    }
    else
    {
        top=top+1;  //栈为空也符合
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
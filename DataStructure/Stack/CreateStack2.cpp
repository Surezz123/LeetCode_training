//链表实现栈
//用链表时，不会受到数组确定大小的影响

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};
struct Node* top = NULL;    //链表为空时栈顶为NULL

int IsEmpty() //判断是否为空
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
    
}

int Top(struct Node* p)  //获取栈顶元素
{
    int a;
    a=p->value;
    return a;
}

void Pop()  //出栈函数(相当于删除头节点)
{
    if (top==NULL)
    {
        printf("The stack is empty!\n");
    }
    struct Node* temp = top;
    top=top->next;      //直接指向下一个
    free(temp);         //此时temp指向上一个头节点，释放上一个头节点
}

void Push(int x)  //入栈函数(相当于在头节点插入新节点)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));    //在栈上新建节点
    temp->value=x;
    temp->next=top;
    top=temp;
}

int main()
{
    struct Node* temp;

    Push(2);
    Push(4);
    Push(6);
    Push(8);

    //这个实现方法有点蠢，需要把所有的Push和Pop放在temp之前
    // temp=top
    // while (temp!=NULL)  //打印链表
    // {
    //     printf("%d ",temp->value);
    //     temp=temp->next;
    // }

    while (!IsEmpty())  //栈非空时
    {
        printf("%d ",Top(top));
        Pop();
    }
    
    
    return 0;
}
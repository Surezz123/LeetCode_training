//����ʵ��ջ
//������ʱ�������ܵ�����ȷ����С��Ӱ��

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};
struct Node* top = NULL;    //����Ϊ��ʱջ��ΪNULL

int IsEmpty() //�ж��Ƿ�Ϊ��
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
    
}

int Top(struct Node* p)  //��ȡջ��Ԫ��
{
    int a;
    a=p->value;
    return a;
}

void Pop()  //��ջ����(�൱��ɾ��ͷ�ڵ�)
{
    if (top==NULL)
    {
        printf("The stack is empty!\n");
    }
    struct Node* temp = top;
    top=top->next;      //ֱ��ָ����һ��
    free(temp);         //��ʱtempָ����һ��ͷ�ڵ㣬�ͷ���һ��ͷ�ڵ�
}

void Push(int x)  //��ջ����(�൱����ͷ�ڵ�����½ڵ�)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));    //��ջ���½��ڵ�
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

    //���ʵ�ַ����е������Ҫ�����е�Push��Pop����temp֮ǰ
    // temp=top
    // while (temp!=NULL)  //��ӡ����
    // {
    //     printf("%d ",temp->value);
    //     temp=temp->next;
    // }

    while (!IsEmpty())  //ջ�ǿ�ʱ
    {
        printf("%d ",Top(top));
        Pop();
    }
    
    
    return 0;
}
//ʹ��ջ����ת�ַ���������
#include<iostream>
#include<stack>     //��׼ģ������б�׼ջ
#include<cstring>
using namespace std;

void Reverse(char c[],int n)
{
    stack<char> S;  //
    
    for (int i = 0; i < n; i++)
    {
        S.push(c[i]);   //��ջ�ַ���
    }
    
    while (!S.empty())  //ջ�ǿ�ʱ����ѭ��
    {
        for (int j = 0; j < n; j++)
        {
            c[j]=S.top();   //ȡջ��Ԫ��
            S.pop();        //��ջ����ջ��ֵ
        }
    }
    
}

int main()
{
    char C[10];
    printf("Enter a string:");
    gets(C);
    Reverse(C,strlen(C));
    printf("%s",C);
}
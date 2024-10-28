//使用栈来反转字符串或链表
#include<iostream>
#include<stack>     //标准模板库中有标准栈
#include<cstring>
using namespace std;

void Reverse(char c[],int n)
{
    stack<char> S;  //
    
    for (int i = 0; i < n; i++)
    {
        S.push(c[i]);   //入栈字符串
    }
    
    while (!S.empty())  //栈非空时进入循环
    {
        for (int j = 0; j < n; j++)
        {
            c[j]=S.top();   //取栈顶元素
            S.pop();        //出栈更新栈顶值
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
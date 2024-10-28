#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool IsCorrection(char c[],int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        if (c[i]=='('||c[i]=='['||c[i]=='{')   //���ַ�������������ʱѹ��ջ
        {
            S.push(c[i]);
        }
        else if(c[i]==')'||c[i]==']'||c[i]=='}')   //���ַ�������������ʱ����ջ���Ƿ����������ܹ�ƥ��
        {
            if(S.empty())  //ջΪ��ʱ,�϶�û���������ܹ�ƥ��������
            {
                return false;
            }

            if (c[i]==')')
            {
                if (S.top()=='(')
                {
                    S.pop();
                }
                else 
                    return false;
                    
            }
            else if (c[i]==']')
            {
                if (S.top()=='[')
                {
                    S.pop();
                }
                else 
                    return false;
                    
            }
            else
            {
                if (S.top()=='{')
                {
                    S.pop();
                }
                else 
                    return false;
            }
        }
    }
    if (S.empty())
        return true;
    else   
        return false;
    
}

int main()
{
    char c[50];
    int n;
    cout << "Enter a string:";
    cin.getline(c,50);
    n=strlen(c);

    if(IsCorrection(c,n)==true)
        cout << "The string is correct" << endl;
    else
        cout << "The string is not correct" << endl;
    
    return 0;
}
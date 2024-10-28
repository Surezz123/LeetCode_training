//ͨ����׺���ʽת��Ϊǰ׺�ͺ�׺���ʽ��ֵ

#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Operation
{  
    public:
        //�Ƚ�������������ȼ�
        int GetPriority(char op)
        {
            if (op=='*' || op=='/')
                return 2;
            if (op=='+' || op=='-')
                return 1;
            return 0;   //���ǲ�����ʱ����0              
        }

        //��׺תǰ׺�Ǵ����������Բ�����֮������ȼ�ֻ�д���
        bool HasHigherPriorityPrefix(char op1,char op2) 
        {
            return GetPriority(op1)>GetPriority(op2);  //����ֵΪ��ʱ����op1���ȼ�����op2
        }

        //��׺ת��׺�Ǵ������ң���ʱ����˳��ҲΪ�������ң���ʱ��߲����������ȼ�������Ϊ�����ұ߲����������ȼ�
        bool HasHigherPriorityPostfix(char op1,char op2)
        {
            return GetPriority(op1)>=GetPriority(op2);  //����ֵΪ��ʱ����op1���ȼ�����op2
        }

        //��׺->ǰ׺(ת��ǰ׺���ַ���ĩβ��ʼ����ʱ���ڴ�ĩβ��ʼ��������֮����Ҫ��ת�ַ���)
        char* InfixToPrefix(vector<char> c,int n)
        {
            stack<char> S;
            string result;

            for (int i = n-1; i >= 0; i--)
            {
                if (c[i]>='0' && c[i]<='9')
                {
                    result+=c[i];
                }
                else if (c[i]=='*' || c[i]=='/' || c[i]=='+' || c[i]=='-')
                {
                    while (!S.empty() && HasHigherPriorityPrefix(S.top(),c[i]))   //ջ�������������ȼ�����c[i]ʱ������ջ
                    {
                        result+=S.top();
                        S.pop();
                    }
                    S.push(c[i]);   //ջ�������������ȼ�С��c[i]��ѹ��ջ
                }
                
            }

            while (!S.empty())  //ջ�ǿ�ʱ�������в�����
            {
                result+=S.top();
                S.pop();
            }
            
            reverse(result.begin(),result.end());   //��ת�ַ���

            char* res = new char[result.length()+1];
            strcpy(res,result.c_str());
            return res;
        }

        //��׺->��׺(ת�ɺ�׺���ַ�����ͷ��ʼ)
        char* InfixToPostfix(vector<char> c,int n)   //����������
        {
            stack<char> S;  //�����ǽ����ʽת��������Ҫ�������㣬��˹�����ջ���char�͵ı���
            string result;

            for (int i = 0; i < n; i++)
            {
                if (c[i]>='0' && c[i]<='9')
                {
                    result += c[i];
                }
                else if(c[i]=='*' || c[i]=='/' || c[i]=='+' || c[i]=='-')
                {
                    while(!S.empty() && HasHigherPriorityPostfix(S.top(),c[i]))  //�ж�ջ����������c[i]�����ȼ���С(��ͬ���ȼ��¼���˳���Ǵ�������)
                    {
                        result += S.top();
                        S.pop();
                    }
                    S.push(c[i]);   //ջΪ�ջ��ߵ�ǰ�Ĳ��������ȼ�����ջ�����ȼ�ʱѹ��ջ��
                }
                   
            }

            while (!S.empty())  //��ջ�л����ַ�ʱ����ȫ������
            {
                result+=S.top();
                S.pop();
            }
            
            char* res=new char[result.length()+1];  //�ڶ��Ϸ����ڴ棬�ڴ�Ĵ�СΪresult.length()+1���ַ�
            strcpy(res,result.c_str());             //��result���ݸ��Ƶ�res�������'/0'
            return res;
        }

        //����ǰ׺���ʽ��ֵ(����ǰ׺ֵʱҲ�Ǵ��ַ���ĩβ��ʼ)
        int EvaluationPrefix(char* c,int n)
        {
            stack<int> S;
            for (int i = n-1; i >= 0; i--)  //��ǰ׺���ʽ��ֵʱ���ұ߽�������ѹ��ջ��
            {
                if (c[i]>='0' && c[i]<='9')
                {
                    S.push(c[i]-'0');
                }
                else if(c[i]=='*' || c[i]=='/' || c[i]=='+' || c[i]=='-')
                {
                    if (S.size()<2) //û���㹻�Ĳ���������ʱ�����ʽ��Ч
                    {
                        cout << "Prefix Error: Insufficient operands for operator " << c[i] <<endl;
                        return -1;
                    }
                    
                    int a=S.top();  //ȡջ������Ԫ��������
                    S.pop();
                    int b=S.top();
                    S.pop();

                    if (c[i]=='*')
                        S.push(a*b);
                
                    else if (c[i]=='/') //δ���Ƿ��������
                        S.push(a/b);  
    
                    else if (c[i]=='+')
                        S.push(a+b);

                    else
                        S.push(a-b);
                }
            }   
            if (S.size()!=1)    //���ʽ�����ȷ��ջ�ڱض�ֻ��һ�����ս������
            {
                cout << "The expression is invalid" << endl;
                return -1;
            }
            
            return S.top();
        }

        //�����׺���ʽ��ֵ(�����׺ֵʱ���ַ�����ͷ��ʼ)
        int EvaluationPostfix(char* c,int n)
        {
            stack<int> S;
            for (int i = 0; i < n; i++)     //���׺���ʽ��ֵʱ����߽�������ѹ��ջ��
            {
                if (c[i]>='0'&&c[i]<='9')
                {
                    S.push(c[i]-'0');
                }
                else if(c[i]=='*'||c[i]=='/'||c[i]=='+'||c[i]=='-')
                {
                    if (S.size()<2) //û���㹻�Ĳ���������ʱ�����ʽ��Ч
                    {
                        cout << "Postfix Error: Insufficient operands for operator " << c[i] <<endl;
                        return -1;
                    }

                    int a=S.top();  //ȡջ������Ԫ��������
                    S.pop();
                    int b=S.top();
                    S.pop();

                    if (c[i]=='*')
                        S.push(a*b);
                
                    else if (c[i]=='/') //δ���Ƿ��������
                        S.push(b/a);  
    
                    else if (c[i]=='+')
                        S.push(a+b);

                    else
                        S.push(b-a);
                }
            }

            if (S.size()!=1)    //���ʽ�����ȷ��ջ�ڱض�ֻ��һ�����ս������
            {
                cout << "The expression is invalid" << endl;
                return -1;
            }

            return S.top();
        }
};


int main()
{
    Operation operation;

    char *a,*b;
    vector<char> c(50);
    int value1=0,value2=0;
    int n=c.size();
    string input;   //������ż�����������ַ���
    cout << "Enter a string:";
    getline(cin,input);

    for (int i = 0; i < input.size(); i++)
    {
        c[i]=input[i];
    }
    

    a=operation.InfixToPrefix(c,n);  //��׺��ǰ׺
    b=operation.InfixToPostfix(c,n);   //��׺����׺

    value1=operation.EvaluationPrefix(a,n);
    value2=operation.EvaluationPostfix(b,n);

    cout<< a <<"\n";
    cout<< value1 <<"\n";

    cout<< b <<"\n";
    cout<< value2 <<endl;
    
    return 0;
}
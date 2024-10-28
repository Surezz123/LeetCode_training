//通过中缀表达式转化为前缀和后缀表达式求值

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
        //比较两个运算符优先级
        int GetPriority(char op)
        {
            if (op=='*' || op=='/')
                return 2;
            if (op=='+' || op=='-')
                return 1;
            return 0;   //不是操作符时返回0              
        }

        //中缀转前缀是从右往左，所以操作符之间的优先级只有大于
        bool HasHigherPriorityPrefix(char op1,char op2) 
        {
            return GetPriority(op1)>GetPriority(op2);  //返回值为真时表明op1优先级高于op2
        }

        //中缀转后缀是从左往右，此时计算顺序也为从左往右，此时左边操作符的优先级可以认为大于右边操作符的优先级
        bool HasHigherPriorityPostfix(char op1,char op2)
        {
            return GetPriority(op1)>=GetPriority(op2);  //返回值为真时表明op1优先级高于op2
        }

        //中缀->前缀(转成前缀从字符串末尾开始，此时由于从末尾开始，处理完之后需要反转字符串)
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
                    while (!S.empty() && HasHigherPriorityPrefix(S.top(),c[i]))   //栈顶操作符的优先级大于c[i]时，弹出栈
                    {
                        result+=S.top();
                        S.pop();
                    }
                    S.push(c[i]);   //栈顶操作符的优先级小于c[i]，压入栈
                }
                
            }

            while (!S.empty())  //栈非空时弹出所有操作符
            {
                result+=S.top();
                S.pop();
            }
            
            reverse(result.begin(),result.end());   //反转字符串

            char* res = new char[result.length()+1];
            strcpy(res,result.c_str());
            return res;
        }

        //中缀->后缀(转成后缀从字符串开头开始)
        char* InfixToPostfix(vector<char> c,int n)   //函数有问题
        {
            stack<char> S;  //这里是将表达式转换，不需要进行运算，因此构建的栈存放char型的变量
            string result;

            for (int i = 0; i < n; i++)
            {
                if (c[i]>='0' && c[i]<='9')
                {
                    result += c[i];
                }
                else if(c[i]=='*' || c[i]=='/' || c[i]=='+' || c[i]=='-')
                {
                    while(!S.empty() && HasHigherPriorityPostfix(S.top(),c[i]))  //判断栈顶操作符和c[i]的优先级大小(相同优先级下计算顺序是从左至右)
                    {
                        result += S.top();
                        S.pop();
                    }
                    S.push(c[i]);   //栈为空或者当前的操作符优先级低于栈顶优先级时压入栈中
                }
                   
            }

            while (!S.empty())  //当栈中还有字符时将其全部弹出
            {
                result+=S.top();
                S.pop();
            }
            
            char* res=new char[result.length()+1];  //在堆上分配内存，内存的大小为result.length()+1个字符
            strcpy(res,result.c_str());             //将result内容复制到res，并添加'/0'
            return res;
        }

        //计算前缀表达式的值(计算前缀值时也是从字符串末尾开始)
        int EvaluationPrefix(char* c,int n)
        {
            stack<int> S;
            for (int i = n-1; i >= 0; i--)  //求前缀表达式的值时从右边将操作数压入栈中
            {
                if (c[i]>='0' && c[i]<='9')
                {
                    S.push(c[i]-'0');
                }
                else if(c[i]=='*' || c[i]=='/' || c[i]=='+' || c[i]=='-')
                {
                    if (S.size()<2) //没有足够的操作数弹出时，表达式无效
                    {
                        cout << "Prefix Error: Insufficient operands for operator " << c[i] <<endl;
                        return -1;
                    }
                    
                    int a=S.top();  //取栈顶两个元素做运算
                    S.pop();
                    int b=S.top();
                    S.pop();

                    if (c[i]=='*')
                        S.push(a*b);
                
                    else if (c[i]=='/') //未考虑非整除情况
                        S.push(a/b);  
    
                    else if (c[i]=='+')
                        S.push(a+b);

                    else
                        S.push(a-b);
                }
            }   
            if (S.size()!=1)    //表达式如果正确，栈内必定只有一个最终结果存在
            {
                cout << "The expression is invalid" << endl;
                return -1;
            }
            
            return S.top();
        }

        //计算后缀表达式的值(计算后缀值时从字符串开头开始)
        int EvaluationPostfix(char* c,int n)
        {
            stack<int> S;
            for (int i = 0; i < n; i++)     //求后缀表达式的值时从左边将操作数压入栈中
            {
                if (c[i]>='0'&&c[i]<='9')
                {
                    S.push(c[i]-'0');
                }
                else if(c[i]=='*'||c[i]=='/'||c[i]=='+'||c[i]=='-')
                {
                    if (S.size()<2) //没有足够的操作数弹出时，表达式无效
                    {
                        cout << "Postfix Error: Insufficient operands for operator " << c[i] <<endl;
                        return -1;
                    }

                    int a=S.top();  //取栈顶两个元素做运算
                    S.pop();
                    int b=S.top();
                    S.pop();

                    if (c[i]=='*')
                        S.push(a*b);
                
                    else if (c[i]=='/') //未考虑非整除情况
                        S.push(b/a);  
    
                    else if (c[i]=='+')
                        S.push(a+b);

                    else
                        S.push(b-a);
                }
            }

            if (S.size()!=1)    //表达式如果正确，栈内必定只有一个最终结果存在
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
    string input;   //用来存放键盘上输入的字符串
    cout << "Enter a string:";
    getline(cin,input);

    for (int i = 0; i < input.size(); i++)
    {
        c[i]=input[i];
    }
    

    a=operation.InfixToPrefix(c,n);  //中缀到前缀
    b=operation.InfixToPostfix(c,n);   //中缀到后缀

    value1=operation.EvaluationPrefix(a,n);
    value2=operation.EvaluationPostfix(b,n);

    cout<< a <<"\n";
    cout<< value1 <<"\n";

    cout<< b <<"\n";
    cout<< value2 <<endl;
    
    return 0;
}
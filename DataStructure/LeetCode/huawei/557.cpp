//翻转字符串里的单词

#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>    //包含交换函数reverse
using namespace std;

class Solution
{
    public:
        string ReverseWord(string s)
        {
            if(s.empty())
                return s;
            
            int left=0,right=0,len=s.size();

            while (right<len)   //右边长度不越界时
            {
                while (right<len && s[right]!=' ')  //防止最后一个单词没有控制从而无限增加
                {
                    right++;
                }
                reverse(s.begin()+left,s.begin()+right);    //交换元素
                left=right+1;   //用这种方法跳过空格
                right++;
            }
            
            //reverse(s.begin()+left,s.begin()+right);
            return s;
        }
    
};

int main()
{
    Solution solution;  //这种写法是在栈上创建对象，由系统自动释放
    //Solution* solution1=new Solution(); //这种写法是在堆上创建对象，由用户自己释放

    string c="Let's take Leetcode contest";

    c=solution.ReverseWord(c);

    cout << c << endl;
    //free;
}
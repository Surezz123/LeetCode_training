//替换数字
#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
        //双指针
        void ReplaceNumber(string& s)
        {
            int slow,fast=0;
            while (fast < s.size())   //未到字符串末尾时进入循环
            {
                if (s[fast]>='1' && s[fast]<='9')   //遇到数字
                {
                    s.resize(s.size()+5);
                }
                fast++;
            }
            
        }
};


int main()
{
    Solution solution;
    string s = "a1b1c3";

    solution.ReplaceNumber(s);
    cout<< s << endl;

}
//�滻����
#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
        //˫ָ��
        void ReplaceNumber(string& s)
        {
            int slow,fast=0;
            while (fast < s.size())   //δ���ַ���ĩβʱ����ѭ��
            {
                if (s[fast]>='1' && s[fast]<='9')   //��������
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
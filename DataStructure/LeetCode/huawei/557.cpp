//��ת�ַ�����ĵ���

#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>    //������������reverse
using namespace std;

class Solution
{
    public:
        string ReverseWord(string s)
        {
            if(s.empty())
                return s;
            
            int left=0,right=0,len=s.size();

            while (right<len)   //�ұ߳��Ȳ�Խ��ʱ
            {
                while (right<len && s[right]!=' ')  //��ֹ���һ������û�п��ƴӶ���������
                {
                    right++;
                }
                reverse(s.begin()+left,s.begin()+right);    //����Ԫ��
                left=right+1;   //�����ַ��������ո�
                right++;
            }
            
            //reverse(s.begin()+left,s.begin()+right);
            return s;
        }
    
};

int main()
{
    Solution solution;  //����д������ջ�ϴ���������ϵͳ�Զ��ͷ�
    //Solution* solution1=new Solution(); //����д�����ڶ��ϴ����������û��Լ��ͷ�

    string c="Let's take Leetcode contest";

    c=solution.ReverseWord(c);

    cout << c << endl;
    //free;
}
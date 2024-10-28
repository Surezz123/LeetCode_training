//翻转字符串里的单词
//题解的思路为先去除多余空格，再反转单词，最后反转字符串
#include<iostream>
#include<string>

using namespace std;

class Solution
{
    private:
        //方法一：直接了当法
        void RemoveExtraSpace1(string &s)
        {
            //处理头部空格
            int fast=0,slow=0,precount=0,postcount=0,incount=0;
            while (s[fast]==' ')   //先找字符串头部空格
            {
                fast++;
                precount++;
            }
            
            while (fast<s.size())      
            {
                s[slow]=s[fast];
                slow++;
                fast++;
            }
            s.resize(s.size()-precount);
            
            //处理尾部空格
            while (s[fast-1]==' ')  //fast指向n，从后面开始找空格个数
            {
                fast--;
                postcount++;
            }
            s.resize(s.size()-postcount);   

             //处理中间多余空格
            fast=0;
            slow=0;
            while (s[fast]!=' ' && fast<s.size())
            {
                fast++;
            }
            while (s[fast]==' ' && fast<s.size())
            {
                fast++;
                incount++;
            }
            if (incount > 1)
            {
                while (fast<s.size())     
                {
                    s[fast-incount+1]=s[fast];
                    fast++;
                }
                s.resize(s.size()-incount);
            }
            
        }
    public:
        //反转字符串
        void ReverseString(string &s,int begin,int end)
        {
            for (int i = begin,j=end; i < j; i++,j--)
            {
                swap(s[i],s[j]);
            }
        }
        
        //清除多余空格(头尾没有空格，单词与单词之间仅有一个空格)
        //方法二：双指针法(类似于移除元素)
        void RemoveExtraSpace2(string &s)
        {
            int slow=0;
            for (int i = 0; i < s.size(); i++)  
            {
                if (s[i] != ' ')    //寻找不是空格的元素进行重组，有点类似于删除元素，找到不是value的元素
                {
                    if (slow!=0)    //slow不为0说明不是在第一个单词,此时保证单词和单词之间一定要有一个空格
                        s[slow++]=' ';
                    while (s[i]!=' '&& i<s.size())
                    {
                        s[slow++]=s[i++];
                    }
                    
                }
            }
            s.resize(slow); //最后slow就指向最后一个单词的末尾
        }

        //反转单词
        string ReverseWord(string s)    
        {
            RemoveExtraSpace2(s);
            ReverseString(s,0,s.size()-1);
            int slow=0,fast=0;

            while (fast < s.size())
            {
                while (s[fast] != ' ' && fast<s.size())    //跳出循环时表明已经找到一个单词
                {
                    fast++;
                }

                int temp = fast-1;

                while (slow<temp)   //找到一个单词并原地交换
                {
                    swap(s[slow],s[temp]);
                    slow++;
                    temp--;
                }
                
                while (s[fast]==' ' && fast<s.size())  //寻找下一个单词
                {
                    slow=fast+1;
                    fast++;
                }
                
            }
            return s;
        }
};


int main()
{
    Solution solution;
    string s="  hello   world!  ";

    string res = solution.ReverseWord(s);
    cout << res << endl;
}


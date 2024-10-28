//找到字符数组中的最长公共前缀

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
    public:
        string LongstCommonPrefix(vector<string> & strs)    //加上&strs之后是直接对strs这个数组进行操作，不加的话仅对输入字符串的副本进行操作
        {
            if (strs.empty())   //字符串为空直接返回
                return "";
            
            string prefix=strs[0];  //把字符数组中的第一个字符串当作前缀
            int count = strs.size();    //记录字符数组中的字符个数
            for (int i = 1; i < count; i++)
            {
                prefix=LongstCommonPrefix(prefix,strs[i]);  //用prefix接收最长公共前缀
                if (prefix.empty()) //只要任意两个字符串公共前缀为空，所有的公共前缀都为空
                {
                    break;
                }
                
            }
            return prefix;  
        }

        //提取两个字符串的最长公共前缀
        string LongstCommonPrefix(const string& str1,const string& str2)  //这里的str2=strs[i],这样的就可以通过str2[i]访问字符串中的字符
        {
            int length=min(str1.size(),str2.size());
            int index=0;    //初始下标为0

            while (index<length && str1[index]==str2[index])    //依次比较字符串中的元素
            {
                index++;
            }
            return str1.substr(0,index);    //返回最长公共前缀
        }
};


int main()
{
    Solution solution;  //在栈上创建对象
    vector<string> strs={"flower","flow","flight"};
    
    string result=solution.LongstCommonPrefix(strs);    

    cout<< result <<endl;
}
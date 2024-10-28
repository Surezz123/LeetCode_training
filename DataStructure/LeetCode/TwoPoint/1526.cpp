//字符串压缩
//主要还是用双指针，如何更新快慢指针是关键
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution
{
    public:
        //可以直接用字符串处理，无需将其当成字符数组处理
        string CompressString(string s)
        {
            string result;
            //strlen() 函数需要一个以 \0 结尾的 C 风格字符串作为参数
            //int n=strlen(s);
            int n = s.length();
            int i=0,j=1;
            while (i < n)   //跳出循环表示遍历完成
            {
                while (s[i] == s[j] && j<n) //跳出循环时表明j已经移动到了元素不相同的位置
                {
                    j++;
                }
                result+=s[i];
                result+=to_string(j-i); //把j-i转换为字符类型
                i=j; 
            } 

            if (result.length()>s.length())   //压缩后的字符串长度大于未压缩前
                return s;
            else
                return result;
        }
};


int main()
{
    Solution solution;

    //string类型可以直接给字符串定义
    string S1 = "aabccccaaa";
    string S2 = "abbcdd";

    string result1 = solution.CompressString(S1);   
    string result2 = solution.CompressString(S2);

    //string类型也可以直接打印
    cout << result1 << "\n";
    cout << result2 << endl;
    
}
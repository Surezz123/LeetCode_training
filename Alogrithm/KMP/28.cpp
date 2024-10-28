//KMP算法进行字符串匹配
//遇见冲突看前一位
#include<iostream>
#include<string>
#include<vector>

using namespace std;

 class Solution
 {
    public:
        //得到next数组
        void GetNext(int* next, const string& s)
        {
            //初始化，这里的next数组就是前缀表
            int j = 0;
            next[j] = 0;
            for (int i = 1; i < s.size(); i++)
            {
                while (j > 0 && s[i] != s[j])   //数组不越界同时匹配发生冲突时，此时j要回退
                {
                    j = next[j-1];
                }
                if (s[i] == s[j])   //前后缀匹配成功时j++
                {
                    j++;
                }
                next[i] = j;    //最后把值赋给next[i]
            }
            
        }

        //字符串匹配，第一次匹配成功时返回下标，匹配失败则返回0
        int strstr(const string& heystack, const string& needle)
        {
            if (needle.size() == 0)
            {
                return -1;
            }
            
            vector<int> next(needle.size());    //先确定动态数组的大小，再把next[0]的地址作为指针传入GetNext中
            GetNext(&next[0], needle);
            int j = 0;

            for (int i = 0; i < heystack.size(); i++)
            {  
                while(needle[j] != heystack[i] && j > 0)
                {
                    j = next[j-1];  //j要回退到的位置
                }

                if (needle[j] == heystack[i])
                {
                    j++;
                }

                if (j == needle.size()) //模式串与文本串匹配时，j应该指向末尾，此时返回下标
                {
                    return (i-needle.size()+1);
                }
            }
            return -1;   //出了循环就表明文本串和模式串匹配不上，返回-1
        }
 };

 int main()
 {
    Solution solution;
    string heystack;   //存放文本串
    cout << "Enter heystack:";
    getline(cin, heystack);

    string needle;   //存放模式串
    cout << "Enter needle:";
    getline(cin, needle);

    int res = solution.strstr(heystack, needle);
    cout << res << endl;
 }
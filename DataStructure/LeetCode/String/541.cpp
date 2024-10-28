//反转字符串Ⅱ
#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
        //简单写法
        void ReverseString(string& s,int k)
        {
            int len = s.size();
            for (int i = 0,j=k-1; i < k/2; i++,j--) //交换前k个字符
            {
                swap(s[i],s[j]);
            }
            
            if (len-2*k < k)    //如果剩余字符小于k个,剩余字符全部反转
            {
                for (int i = 2*k,j=len-1; i < (len-2*k)/2; i++)
                {
                    swap(s[i],s[j]);
                } 
            }
            
            if (len-2*k < 2*k && len-2*k >= k)  //剩余字符小于2k但大于或等于k个,则反转前k个
            {
                for (int i = 2*k,j=3*k-1; i < 5*k/2; i++,j--)
                {
                    swap(s[i],s[j]);
                } 
            }
        
        }
};

int main()
{
    string s = "abcdefghigklm";
    int x = 2;
    Solution solution;
    solution.ReverseString(s,4);

    cout << s << endl;
}
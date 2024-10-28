//????

#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
        //方法一：用另一个字符串来存储转换的结果
        string SwapNumber(string s)
        {
            string res="";
            int n = s.size();
            int i=0;
            for (int i = 0; i < n; i++)
            {
                if (s[i]>='0' && s[i]<='9')
                {
                    res+="number";
                }
                if (s[i]>='a' && s[i]<='z')
                {
                    res+=s[i];
                }
            }
            return res;  
        }

        //方法二：双指针法
        string SwapNumber1(string s)
        {
            int count=0;    
            int oldindex=0;
            for (oldindex = 0; oldindex < s.size(); oldindex++) //??????????
            {
                if (s[oldindex]>='0' && s[oldindex]<='9')
                    count++;
            }
            
            //????
            s.resize(s.size()+count*5);
            int newindex = s.size()-1;    //newindex????????

            while (oldindex>=0)
            {
                if (s[oldindex-1]>='0' && s[oldindex-1]<='9')   
                {
                    s[newindex--]='r';
                    s[newindex--]='e';
                    s[newindex--]='b';
                    s[newindex--]='m';
                    s[newindex--]='u';
                    s[newindex--]='n';
                }
                
                //oldindex??????
                else
                {
                    s[newindex] = s[oldindex-1]; 
                    newindex--;
                }
                oldindex--;
            }
            return s;
        }
    
};

int main()
{
    Solution solution;
    string s="ab12cd";
    string res=solution.SwapNumber1(s);

    cout << res << endl;
}
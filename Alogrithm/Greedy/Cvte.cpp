//有一千张卡片上面分别写着0-999的数字,分别从其中抽取5张，将其组成一个最小的整数比如:
//选择1 10 23 9 41 输出:10123419
//选择4 48 9 40 5 输出:4044859
//这个题其实是一个贪心算法的题，5个数任意取2个数，先找到2个数组成的最小值，记为a，再找到第三个数b与a组成的最小值，从局部最优到全局最优

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    private:
        string res; //记录返回的最小数字
        //自定义比较函数，把数字转化为字符串，比较a+b和b+a的大小，然后通过sort排序
        static bool Strcompare(string& a, string& b)
        {
            return a+b < b+a;
        }

    public:
        string MinNumber(vector<int>& num)
        {
            //用于存放num从int类型转为string类型的值
            vector<string> str; 
            for(int n : num)
            {
                str.push_back(to_string(n));
            }

            //sort函数可以接受任意符合要求的比较函数。只要这个比较函数能够接收两个参数并返回布尔值，表示这两个参数的相对顺序
            sort(str.begin(), str.end(), Strcompare); 

            for (int i = 0; i < str.size(); i++)
            {
                res += str[i];
            }
            
            //处理全0的情况
            if (res[0] == '0')
            {
                return "0";
            }
            
            return res;
        }
};

int main()
{
    vector<int> num = {0, 10, 23, 9, 41};
    Solution solution;
    string res = solution.MinNumber(num);
    cout << res << endl;
    return 0;
}
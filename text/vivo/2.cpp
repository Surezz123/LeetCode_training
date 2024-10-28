//滑动窗口
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        vector<int> FindFluctuations(vector<int>& memoryusage, int k)
        {
            int n = memoryusage.size();
            int left = 0;
            int right = k;
            int max = 0, min = 0;
            vector<int> res;

            while (right < n)
            {
                for (int i = left; i < right; i++)  //遍历滑动窗口
                {
                    max = (max < memoryusage[i]) ? memoryusage[i] : max;    //记录滑动窗口中的最大值和最小值
                    min = (min > memoryusage[i]) ? memoryusage[i] : min;
                }
                res.push_back(max - min);
            }
            return res;
        }
};

int main()
{
    vector<int> memoryusage;  // 定义一个 vector 来存储输入的数组
    int num;

    // 使用 cin 从输入读取，用空格隔开的数字，直到输入结束
    while (cin >> num) {
        memoryusage.push_back(num);  // 将读取到的数字存储到 res 数组中
        if (cin.peek() == '\n')
            break; 
    }

    // int k;
    // cin >> k;

    Solution solution;
    vector<int> res = solution.FindFluctuations(memoryusage, 4);
    for(int num : res)
    {
        cout << num << ' ';
    }

    return 0;
}
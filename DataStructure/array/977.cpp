//有序数组的平方
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    private:
        int square(int a)
        {
            return a * a;
        }
    public:
        vector<int> sortedSquares(vector<int>& nums)
        {
            vector<int> res;
            int left = 0, right = nums.size() - 1;

            //有序数组，数组元素平方后的最大值肯定都集中在两边，所以判断两边的大小
            while (left <= right)
            {
                if (square(nums[left]) >= square(nums[right]))
                {
                    res.push_back(square(nums[left]));
                    left++;
                }
                else
                {
                    res.push_back(square(nums[right]));
                    right--;
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
};

int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    
    Solution solution;
    vector<int> res = solution.sortedSquares(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    
}
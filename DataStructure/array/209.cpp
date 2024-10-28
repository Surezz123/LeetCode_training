//长度最小的子数组
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        //双指针
        int minSubArrayLen(int target, vector<int>& nums)
        {
            int left = 0;
            int sum = 0, res = INT32_MAX;
            int length = 0;
            for (int right = 0; right < nums.size(); right++)
            {
                sum += nums[right];
                while (sum >= target)
                {
                    length = right - left + 1;
                    res = res < length ? res : length;
                    sum -= nums[left++];
                }
            }
            return res == INT32_MAX ? 0 : res;
        }
};

int main()
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution solution;
    int res = solution.minSubArrayLen(target, nums); 

    cout << res << endl;
}
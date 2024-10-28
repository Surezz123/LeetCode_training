//三数之和
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> ThreeSum(vector<int>& nums)
        {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());     //对nums进行排序，方便后续双指针移动

            //a = nums[i], b = nums[i+1], c = nums[nums.size()-1]
            for (int i = 0; i < nums.size(); i++)
            {
                //因为nums排序过，所以当nums[i] > 0时后续不可能出现a + b + c = 0的情况，直接return
                if (nums[i] > 0)
                {
                    return res;
                }
                
                //这里是对a进行去重，不能用nums[i] == nums[i+1]去重是因为这样实际上是判断三数集合中是否有相同元素，因为a = nums[i], b = nums[i+1]
                if(i > 0 && nums[i] == nums[i-1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    //三数之和大于0时，此时right左移
                    if (nums[i] + nums[left] + nums[right] > 0)
                    {
                        right--;
                    }
                    //三数之和小于0时，此时left右移
                    else if (nums[i] + nums[left] + nums[right] < 0)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        
                        //对b进行去重，
                        while (right > left && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        //对c进行去重
                        while (right > left && nums[left] == nums[left + 1])
                        {
                            left++;
                        }

                        //找到符合情况的a,b,c之后，需要继续移动指针
                        left++;
                        right--;
                    }  
                }
            }
            return res;
        }
};


int main()
{
    Solution solution;
    vector<int> nums;
    vector<vector<int>> result;
    int num;

    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    
    result = solution.ThreeSum(nums);
    //打印二维数组
    for(const auto& row : result)
    {
        for(const auto& ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}
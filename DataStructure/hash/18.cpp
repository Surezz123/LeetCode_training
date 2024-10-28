//四树之和
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end()); //对nums进行排序，方便后续双指针移动

            //a = nums[i], b = nums[j], c = nums[j+1], d = nums[nums.size()-1]
            for (int i = 0; i < nums.size(); i++)
            {
                //这里不能直接通过nums[i] > target做剪枝操作，因为负数相加可以变得更小，如nums = [-4, -1, 0, 0], target = -5时，如果直接判断就会漏掉这种情况
                //三数之和能直接判断，是因为target = 0，在排序后的nums[i] > 0时必然三数之和不会为0
                //这里可以用break也可以用return res，因为这已经是最外层循环
                if (nums[i] > target && nums[i] >= 0)
                {
                    break;
                }

                //对a去重
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                
                
                for (int j = i + 1; j < nums.size(); j++)
                {
                    //继续剪枝，这里剪枝时一定要用break而不是return res，因为break会重新跳回上层循环，而return res会直接跳出函数，这样会导致一些集合的缺失
                    if (nums[i] + nums[j] > target && (nums[i] + nums[j] >= 0))
                    {
                        break;
                    }
            
                    //对b去重
                    if (j > i + 1 && nums[j] == nums[j-1])
                    {
                        continue;
                    }
                    
                    int left = j + 1;
                    int right = nums.size() - 1;
                    
                    while (right > left)
                    {
                        if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                        {
                            right--;
                        }
                        else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                        {
                            left++;
                        }
                        else
                        {
                            res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                            //对c去重
                            while (right > left && nums[right] == nums[right - 1])
                            {
                                right--;
                            }
                            //对d去重
                            while (right > left && nums[left] == nums[left + 1])
                            {
                                left++;
                            }

                            right--;
                            left++;
                        }
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
    int num, target;

    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    
    cin >> target;

    result = solution.fourSum(nums, target);
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
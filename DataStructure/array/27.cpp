//移除元素
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int removeElement(vector<int>& nums, int val)
        {
            
            int slow = 0;
            //快慢指针，快指针找到不等于val的值
            for (int fast = 0; fast < nums.size(); fast++)
            {
                //nums中有k个val时，进入if的次数为nums.size()-k，最后返回的数组大小也为nums.size()-k，即为slow
                if (nums[fast] != val)
                {
                    nums[slow++] = nums[fast];
                }
            }
            return slow;
        }
};

int main()
{
    vector<int> nums;
    int num;
    int val;

    cin >> val;

    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
        {
            break;
        }
        
    }
    
    Solution solution;
    int res = solution.removeElement(nums, val);
    cout << res << "\n";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    
}
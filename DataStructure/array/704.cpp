//���ֲ��ң����������������ܹ�ʹ��
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int search(vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;
            
            //��Ҫ���ǵ�����һ��Ԫ�ص����
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
            
            return -1;
        }
};

int main()
{
    vector<int> nums;
    int num, target;

    cin >> target;

    //���뵽nums��
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    
    Solution solution;
    int res = solution.search(nums, target);
    cout << res << endl;
}
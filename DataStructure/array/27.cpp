//�Ƴ�Ԫ��
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int removeElement(vector<int>& nums, int val)
        {
            
            int slow = 0;
            //����ָ�룬��ָ���ҵ�������val��ֵ
            for (int fast = 0; fast < nums.size(); fast++)
            {
                //nums����k��valʱ������if�Ĵ���Ϊnums.size()-k����󷵻ص������СҲΪnums.size()-k����Ϊslow
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
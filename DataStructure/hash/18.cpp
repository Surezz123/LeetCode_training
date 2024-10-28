//����֮��
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
            sort(nums.begin(), nums.end()); //��nums�������򣬷������˫ָ���ƶ�

            //a = nums[i], b = nums[j], c = nums[j+1], d = nums[nums.size()-1]
            for (int i = 0; i < nums.size(); i++)
            {
                //���ﲻ��ֱ��ͨ��nums[i] > target����֦��������Ϊ������ӿ��Ա�ø�С����nums = [-4, -1, 0, 0], target = -5ʱ�����ֱ���жϾͻ�©���������
                //����֮����ֱ���жϣ�����Ϊtarget = 0����������nums[i] > 0ʱ��Ȼ����֮�Ͳ���Ϊ0
                //���������breakҲ������return res����Ϊ���Ѿ��������ѭ��
                if (nums[i] > target && nums[i] >= 0)
                {
                    break;
                }

                //��aȥ��
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                
                
                for (int j = i + 1; j < nums.size(); j++)
                {
                    //������֦�������֦ʱһ��Ҫ��break������return res����Ϊbreak�����������ϲ�ѭ������return res��ֱ�����������������ᵼ��һЩ���ϵ�ȱʧ
                    if (nums[i] + nums[j] > target && (nums[i] + nums[j] >= 0))
                    {
                        break;
                    }
            
                    //��bȥ��
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
                            //��cȥ��
                            while (right > left && nums[right] == nums[right - 1])
                            {
                                right--;
                            }
                            //��dȥ��
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
    //��ӡ��ά����
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
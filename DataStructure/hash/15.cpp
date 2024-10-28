//����֮��
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
            sort(nums.begin(), nums.end());     //��nums�������򣬷������˫ָ���ƶ�

            //a = nums[i], b = nums[i+1], c = nums[nums.size()-1]
            for (int i = 0; i < nums.size(); i++)
            {
                //��Ϊnums����������Ե�nums[i] > 0ʱ���������ܳ���a + b + c = 0�������ֱ��return
                if (nums[i] > 0)
                {
                    return res;
                }
                
                //�����Ƕ�a����ȥ�أ�������nums[i] == nums[i+1]ȥ������Ϊ����ʵ�������ж������������Ƿ�����ͬԪ�أ���Ϊa = nums[i], b = nums[i+1]
                if(i > 0 && nums[i] == nums[i-1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    //����֮�ʹ���0ʱ����ʱright����
                    if (nums[i] + nums[left] + nums[right] > 0)
                    {
                        right--;
                    }
                    //����֮��С��0ʱ����ʱleft����
                    else if (nums[i] + nums[left] + nums[right] < 0)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        
                        //��b����ȥ�أ�
                        while (right > left && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        //��c����ȥ��
                        while (right > left && nums[left] == nums[left + 1])
                        {
                            left++;
                        }

                        //�ҵ����������a,b,c֮����Ҫ�����ƶ�ָ��
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
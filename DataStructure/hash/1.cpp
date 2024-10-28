//����֮��
//��ϣ�������ж�һ��Ԫ���Ƿ�����ڼ�����
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            //���ڴ洢�±��Լ��±��Ӧ��ֵ
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); i++)
            {
                //��map�в���target - nums[i]
                auto iter = map.find(target - nums[i]);

                //˵����map�д���target - nums[i]
                if (iter != map.end())
                {
                    return{iter->second, i};
                }
                
                //û�ҵ��Ͱ�nums[i]�����Ӧ���±���뵽map�У�Ȼ�������һ�β���
                map.insert(pair<int, int>(nums[i], i));
            }
            
            //������֮��û�ҵ�����ʾ����������֮��Ϊtarget
            return {};
        }
};

int main()
{
    Solution solution;
    vector<int> arr;
    vector<int> res;
    int num, target;

    while (cin >> num) {
        arr.push_back(num);  // ����ȡ�������ִ洢�� arr ������
        if (cin.peek() == '\n')
            break; 
    }

    cin >> target;

    res = solution.twoSum(arr, target);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    
    return 0;
}

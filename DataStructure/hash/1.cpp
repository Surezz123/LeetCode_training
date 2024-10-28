//两数之和
//哈希表用来判断一个元素是否出现在集合中
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            //用于存储下标以及下标对应的值
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); i++)
            {
                //在map中查找target - nums[i]
                auto iter = map.find(target - nums[i]);

                //说明在map中存在target - nums[i]
                if (iter != map.end())
                {
                    return{iter->second, i};
                }
                
                //没找到就把nums[i]及其对应的下标插入到map中，然后进行下一次查找
                map.insert(pair<int, int>(nums[i], i));
            }
            
            //遍历完之后还没找到，表示不存在两数之和为target
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
        arr.push_back(num);  // 将读取到的数字存储到 arr 数组中
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

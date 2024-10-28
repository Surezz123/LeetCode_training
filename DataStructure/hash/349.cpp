//两个数组的交集
//哈希表最擅长的就是给你一个元素，判断这个元素是否出现过
#include<iostream>
#include<vector>
#include<string>
//set,multiset底层实现为红黑树，unordered_set底层实现为哈希,其做映射和取值操作时效率最高
#include<unordered_set> 
using namespace std;

class Solution
{
    public:
        vector<int> intersection(vector<int>& num1, vector<int>& num2)
        {
            unordered_set<int> res_set; //用于存放最后结果，由于set本身会去掉重复元素，所以不需要进行降重
            unordered_set<int> num1_set(num1.begin(), num1.end());  //将num1的所有元素放入num1_set中，同时会去重

            for(int num : num2)
            {
                if(num1_set.find(num) != num1_set.end())    //遍历num2中的元素，同时查询是否有值存在于num1_set1中
                {
                    res_set.insert(num);    //存在将值插入到res_set中
                }
            }
            
            return vector<int>(res_set.begin(), res_set.end()); //将res_set转换为vector并返回 
        }
};

int main()
{
    Solution solution;
    vector<int> num1, num2, res;
    int num;
    while (cin >> num)
    {
        num1.push_back(num);
        if(cin.peek() == '\n')
            break;
    }

    while (cin >> num)
    {
        num2.push_back(num);
        if(cin.peek() == '\n')
            break;
    }
    
    res = solution.intersection(num1, num2);
    for(auto num : res)
    {
        cout << num << ' ';
    }
    
    return 0;
}

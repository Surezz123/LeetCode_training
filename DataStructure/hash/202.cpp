//快乐数
#include<iostream>
#include<unordered_set>
#include<cmath>
using namespace std;

class Solution
{
    private:
        //计算n的个位、十位、百位...的平方之和
        int getSum(int n)
        {
            int sum = 0;
            while (n)
            {
                sum += sqrt(n % 10);
                n = n / 10;
            }
            return sum;
        }

    public:
        bool isHappy(int n)
        {
            unordered_set<int> set;
            while (true)
            {
                int sum = getSum(n);
                if (sum == 1)
                {
                    return true;
                }
                //说明set中出现过sum，此时表明陷入重复，返回false
                if (set.find(sum) != set.end()) 
                {
                    return false;
                }

                set.insert(sum);
                n = sum;    //更新n的值
            }
        }
};

int main()
{
    Solution solution;
    int n;
    cin >> n;
    
    cout << boolalpha << solution.isHappy(n) << endl;
}
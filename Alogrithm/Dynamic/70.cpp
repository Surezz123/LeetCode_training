#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int ClimbStair(int n)
        {
            if (n <= 1)
            {
                return n;
            }
            vector<int> dp(2);
            dp[0] = 1;
            dp[1] = 2;
            for (int i = 2; i < n; i++)
            {
                int sum = dp[i-1] + dp[i-2];

            }
            
        }
};

int main()
{
    int n;
    cin >> n;
    Solution solution;
    int res = solution.ClimbStair(n);
    cout << res << endl;
}
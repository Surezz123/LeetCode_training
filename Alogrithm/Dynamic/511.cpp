//ì³²¨ÄÇÆõÊýÁÐ
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int Fibonaccisequence(vector<int>& dp)
        {
            if (dp.size() <= 1)
            {
                return 1;
            }
            
            int n = dp.size();
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 2; i < n; i++)
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n-1];
        }
};

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1);
    Solution solution;
    int res = solution.Fibonaccisequence(dp);
    cout << res << "\n";

    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << ' ';
    }
}
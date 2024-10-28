//组合总和。找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

#include<iostream>
#include<vector>

using namespace std;

class BackTracking {
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(int n, int k, int start, int& sum)
    {
        if(path.size() == k)    //递归当path的长度为3时必须退出递归
        {
            if(sum == n)    //但是只有当path中的成员之和为sum时才push进res中
            {
                res.push_back(path);
            }
            return;
        }

        for(int i=start; i<=n; i++)
        {
            path.push_back(i);
            sum += i;
            backtracking(n, k, i+1, sum);
            int PopValue = path.back();
            path.pop_back();    //假如k=3，n=7时，此时找到1、2、3并不满足1+2+3=7，此时会return到2，此时需要将3pop出去，同时把该值从sum中减去
            sum -= PopValue;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        backtracking(n, k, 1, sum);
        return res;
    }

    void Print()
    {
        cout << '[';
        for (const auto& row : res)
        {
            cout << '[';
            for(size_t j=0; j < row.size(); j++)
            {
                cout << row[j];
                if (j < row.size() - 1)
                {
                    cout << ',';
                }
            }
            cout << ']';
        } 
        cout << ']' << endl;
    }
};

int main()
{
    int k, n;
    cin >> k >> n;
    BackTracking backtracking;
    backtracking.combinationSum3(k, n);
    backtracking.Print();
    return 0;
}
//组合问题：给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合

#include<iostream>
#include<vector>

using namespace std;

class BackTracking
{
    private:
        vector<int> path;
        vector<vector<int>> res;
    public:
        // BackTracking(int rows, int cols)    //构造函数初始化成员变量
        // {   
        //     path.resize(cols);
        //     res.resize(rows, vector<int>(cols));
        // }

        //1.确定参数与返回值
        void backtracking(int n, int k, int start)
        {
            //2.递归结束条件(当取到k个元素的序列时结束递归)
            if (path.size() == k)   
            {
                res.push_back(path);    //把收集到的结果压入res中
                return;
            }   
            
            //3.单层处理逻辑
            for (int i = start; i <= n; i++)
            {
                path.push_back(i);
                backtracking(n, k, i+1);    //把i压入再对i+1开始的序列做相同操作，直到path.size() == k
                path.pop_back();            //这是最关键的一步，以1234举例，找到12后需要把2弹出，才能找到13，不然只会变为123
            }
            
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
    int n, k;
    cin >> n >> k;
    BackTracking bt;
    bt.backtracking(n, k, 1);
    bt.Print();
}
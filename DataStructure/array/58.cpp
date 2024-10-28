//区间和
#include<iostream>
#include<vector>
using namespace std;

//该题用暴力解法面对大数据量会超时，此时用前缀和求区间和
int main()
{
    int n, a, b;
    cin >> n;
    vector<int> arr(n);
    //存放前缀和的数组
    vector<int> presum(n);
    //当前前缀和的值
    int Presum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        Presum += arr[i];
        //在固定数组大小时，不使用pushback，直接使用下标访问
        presum[i] = Presum;
    }

    while (cin >> a >> b)
    {
        int sum;
        if (a == 0)
        {
            sum = presum[b];
        }
        else
        {
            sum = presum[b] - presum[a - 1];
        }
        cout << sum << endl;
    }
}
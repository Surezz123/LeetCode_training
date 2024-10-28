//����ܺ͡��ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�

#include<iostream>
#include<vector>

using namespace std;

class BackTracking {
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(int n, int k, int start, int& sum)
    {
        if(path.size() == k)    //�ݹ鵱path�ĳ���Ϊ3ʱ�����˳��ݹ�
        {
            if(sum == n)    //����ֻ�е�path�еĳ�Ա֮��Ϊsumʱ��push��res��
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
            path.pop_back();    //����k=3��n=7ʱ����ʱ�ҵ�1��2��3��������1+2+3=7����ʱ��return��2����ʱ��Ҫ��3pop��ȥ��ͬʱ�Ѹ�ֵ��sum�м�ȥ
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
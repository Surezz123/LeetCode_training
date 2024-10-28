//������⣺������������ n �� k������ 1 ... n �����п��ܵ� k ���������

#include<iostream>
#include<vector>

using namespace std;

class BackTracking
{
    private:
        vector<int> path;
        vector<vector<int>> res;
    public:
        // BackTracking(int rows, int cols)    //���캯����ʼ����Ա����
        // {   
        //     path.resize(cols);
        //     res.resize(rows, vector<int>(cols));
        // }

        //1.ȷ�������뷵��ֵ
        void backtracking(int n, int k, int start)
        {
            //2.�ݹ��������(��ȡ��k��Ԫ�ص�����ʱ�����ݹ�)
            if (path.size() == k)   
            {
                res.push_back(path);    //���ռ����Ľ��ѹ��res��
                return;
            }   
            
            //3.���㴦���߼�
            for (int i = start; i <= n; i++)
            {
                path.push_back(i);
                backtracking(n, k, i+1);    //��iѹ���ٶ�i+1��ʼ����������ͬ������ֱ��path.size() == k
                path.pop_back();            //������ؼ���һ������1234�������ҵ�12����Ҫ��2�����������ҵ�13����Ȼֻ���Ϊ123
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
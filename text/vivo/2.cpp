//��������
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        vector<int> FindFluctuations(vector<int>& memoryusage, int k)
        {
            int n = memoryusage.size();
            int left = 0;
            int right = k;
            int max = 0, min = 0;
            vector<int> res;

            while (right < n)
            {
                for (int i = left; i < right; i++)  //������������
                {
                    max = (max < memoryusage[i]) ? memoryusage[i] : max;    //��¼���������е����ֵ����Сֵ
                    min = (min > memoryusage[i]) ? memoryusage[i] : min;
                }
                res.push_back(max - min);
            }
            return res;
        }
};

int main()
{
    vector<int> memoryusage;  // ����һ�� vector ���洢���������
    int num;

    // ʹ�� cin �������ȡ���ÿո���������֣�ֱ���������
    while (cin >> num) {
        memoryusage.push_back(num);  // ����ȡ�������ִ洢�� res ������
        if (cin.peek() == '\n')
            break; 
    }

    // int k;
    // cin >> k;

    Solution solution;
    vector<int> res = solution.FindFluctuations(memoryusage, 4);
    for(int num : res)
    {
        cout << num << ' ';
    }

    return 0;
}
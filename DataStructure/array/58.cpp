//�����
#include<iostream>
#include<vector>
using namespace std;

//�����ñ����ⷨ��Դ��������ᳬʱ����ʱ��ǰ׺���������
int main()
{
    int n, a, b;
    cin >> n;
    vector<int> arr(n);
    //���ǰ׺�͵�����
    vector<int> presum(n);
    //��ǰǰ׺�͵�ֵ
    int Presum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        Presum += arr[i];
        //�ڹ̶������Сʱ����ʹ��pushback��ֱ��ʹ���±����
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
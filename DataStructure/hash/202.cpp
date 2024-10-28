//������
#include<iostream>
#include<unordered_set>
#include<cmath>
using namespace std;

class Solution
{
    private:
        //����n�ĸ�λ��ʮλ����λ...��ƽ��֮��
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
                //˵��set�г��ֹ�sum����ʱ���������ظ�������false
                if (set.find(sum) != set.end()) 
                {
                    return false;
                }

                set.insert(sum);
                n = sum;    //����n��ֵ
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
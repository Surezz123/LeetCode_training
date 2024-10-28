//�ж�������������һ��ĵڼ��죬����2019-01-09Ϊ2019��ĵ�9��
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
    private:
        //�����ж��Ƿ�Ϊ����
        bool IsLeapYear(int year)
        {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
    
    public:
        int DayofYear(const string& date)
        {
            vector<int> DayofMouth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int res = 0;

            //substr��һ��������ʾ��ʼλ�ã��ڶ���������ʾ�ַ�����
            int year = stoi(date.substr(0, 4));
            int mouth = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));

            //�ж��Ƿ�Ϊ���꣬Ϊ����ʱ����2�µ�����
            if (IsLeapYear(year))
            {
                DayofMouth[1] = 29;
            }

            for (int i = 0; i < mouth - 1; i++)
            {
                res += DayofMouth[i];
            }
            res += day;

            return res;
        }
};

int main()
{
    Solution solution;
    string date;
    cin >> date;

    int res = solution.DayofYear(date);
    cout << res << endl;
}
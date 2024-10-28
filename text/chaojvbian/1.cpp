//判断所给日期是这一年的第几天，比如2019-01-09为2019年的第9天
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
    private:
        //用于判断是否为闰年
        bool IsLeapYear(int year)
        {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
    
    public:
        int DayofYear(const string& date)
        {
            vector<int> DayofMouth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int res = 0;

            //substr第一个参数表示开始位置，第二个参数表示字符个数
            int year = stoi(date.substr(0, 4));
            int mouth = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));

            //判断是否为闰年，为闰年时更新2月的天数
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
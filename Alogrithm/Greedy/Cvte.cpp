//��һǧ�ſ�Ƭ����ֱ�д��0-999������,�ֱ�����г�ȡ5�ţ��������һ����С����������:
//ѡ��1 10 23 9 41 ���:10123419
//ѡ��4 48 9 40 5 ���:4044859
//�������ʵ��һ��̰���㷨���⣬5��������ȡ2���������ҵ�2������ɵ���Сֵ����Ϊa�����ҵ���������b��a��ɵ���Сֵ���Ӿֲ����ŵ�ȫ������

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    private:
        string res; //��¼���ص���С����
        //�Զ���ȽϺ�����������ת��Ϊ�ַ������Ƚ�a+b��b+a�Ĵ�С��Ȼ��ͨ��sort����
        static bool Strcompare(string& a, string& b)
        {
            return a+b < b+a;
        }

    public:
        string MinNumber(vector<int>& num)
        {
            //���ڴ��num��int����תΪstring���͵�ֵ
            vector<string> str; 
            for(int n : num)
            {
                str.push_back(to_string(n));
            }

            //sort�������Խ����������Ҫ��ıȽϺ�����ֻҪ����ȽϺ����ܹ������������������ز���ֵ����ʾ���������������˳��
            sort(str.begin(), str.end(), Strcompare); 

            for (int i = 0; i < str.size(); i++)
            {
                res += str[i];
            }
            
            //����ȫ0�����
            if (res[0] == '0')
            {
                return "0";
            }
            
            return res;
        }
};

int main()
{
    vector<int> num = {0, 10, 23, 9, 41};
    Solution solution;
    string res = solution.MinNumber(num);
    cout << res << endl;
    return 0;
}
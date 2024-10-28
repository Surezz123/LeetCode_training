//�绰�������ĸ��ϣ�����ⲻͬ��ǰ������������ͬ����֮������
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BackTracking
{
    private:
        //���ֺ���ĸһһ��Ӧ
        const string LetterMap[10]=
        {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        }; 
        string s;
        vector<string> res; //���ڴ�Ž��

        void backtracking(const string& digits, int index)
        {
            if (index == digits.size())    //��ֹ��������������digits�ַ���ʱ��ʱ��sѹ��res�в�����
            {
                res.push_back(s);
                return;
            }
            
            int digit = digits[index] - '0';    //�����index��ʾ���������digits�ַ����еĵڼ�������
            string letters = LetterMap[digit];
            for (int i = 0; i < letters.size(); i++)    //���forѭ���Ǳ���letters�����ĸ�����簴��1ʱ����abc�������
            {
                s.push_back(letters[i]);
                backtracking(digits, index+1);   //����һ�����ֵ���ĸ�������
                s.pop_back();
            }
            
        }
    
    public:
        vector<string> letterCombinations(const string& digits) 
        {
            s.clear();
            res.clear();
            int index = 0;
            if (digits.size() == 0)
            {
                return res;
            }
            
            backtracking(digits, index);
            return res;
        }
};

int main()
{
    string digits;
    getline(cin, digits);
    BackTracking backtracking;
    vector<string> res = backtracking.letterCombinations(digits);

    cout << "[";
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << "\"" << res[i] << "\"";
        if (i < res.size()-1)
        {
            cout << ", ";
        }
        
    }
    cout << "]";
    return 0;
}
//�����
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
    public:
        bool canConstruct(string ransonNote, string magazine)
        {
            //����˵����ֻ����Сд��ĸ����������Ĵ�С��ȷ����
            vector<int> arr(26);

            if (ransonNote.size() > magazine.size())
            {
                return false;
            }
            
            //����ransonNote����¼Ԫ�ظ���
            for (int i = 0; i < ransonNote.size(); i++)
            {
                int index = ransonNote[i] - 'a';
                arr[index]++;
            }
            
            //����magazine����arr��a-z�ĸ���
            for (int i = 0; i < magazine.size(); i++)
            {
                int index = magazine[i] - 'a';
                if (arr[index] == 0)
                {
                    continue;
                }

                arr[index]--;
            }
            
            //����arr�����arr�е�Ԫ���з��㣬�����ransomNote�ܲ�����magazine������ַ�����
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }
};

int main()
{
    string ransonNote, magazine;
    getline(cin, ransonNote);
    getline(cin, magazine);
    Solution solution;

    cout << boolalpha <<solution.canConstruct(ransonNote, magazine);
    
}
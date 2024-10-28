//��Ч����ĸ��λ�ʣ�����˵���������ַ�������ĸ�����Ƿ���ͬ
//������Ҫ�����������Ϊ��ϣ�����������δ洢����Ϊa-z��ĸ�ĸ�����ͬʱ��Ϊ����������a-z�ĸ���һ����26�������Ը������ʹ������
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
    public:
        bool IsAnagram(string s, string t)
        {
            vector<int> arr(26);    //���������ڴ���ַ�����a-z�ĸ���
            //���ַ�����a-z�ĸ�������arr��
            for (int i = 0; i < s.size(); i++)
            {
                int index = s[i] - 'a'; //arr���±�index
                arr[index]++;
            }
            
            //�ٱ����ַ���t������t��a-z������arr�ж�Ӧ��ȥ
            for (int i = 0; i < t.size(); i++)
            {
                int index = t[i] - 'a';
                arr[index]--;
            }
            
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
    string s, t;
    getline(cin, s);
    getline(cin, t);

    Solution solution;
    bool res = solution.IsAnagram(s, t);

    cout << boolalpha << res << endl;   //��true��false�����res
    return 0;
}
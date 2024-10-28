//KMP�㷨�����ַ���ƥ��
//������ͻ��ǰһλ
#include<iostream>
#include<string>
#include<vector>

using namespace std;

 class Solution
 {
    public:
        //�õ�next����
        void GetNext(int* next, const string& s)
        {
            //��ʼ���������next�������ǰ׺��
            int j = 0;
            next[j] = 0;
            for (int i = 1; i < s.size(); i++)
            {
                while (j > 0 && s[i] != s[j])   //���鲻Խ��ͬʱƥ�䷢����ͻʱ����ʱjҪ����
                {
                    j = next[j-1];
                }
                if (s[i] == s[j])   //ǰ��׺ƥ��ɹ�ʱj++
                {
                    j++;
                }
                next[i] = j;    //����ֵ����next[i]
            }
            
        }

        //�ַ���ƥ�䣬��һ��ƥ��ɹ�ʱ�����±꣬ƥ��ʧ���򷵻�0
        int strstr(const string& heystack, const string& needle)
        {
            if (needle.size() == 0)
            {
                return -1;
            }
            
            vector<int> next(needle.size());    //��ȷ����̬����Ĵ�С���ٰ�next[0]�ĵ�ַ��Ϊָ�봫��GetNext��
            GetNext(&next[0], needle);
            int j = 0;

            for (int i = 0; i < heystack.size(); i++)
            {  
                while(needle[j] != heystack[i] && j > 0)
                {
                    j = next[j-1];  //jҪ���˵���λ��
                }

                if (needle[j] == heystack[i])
                {
                    j++;
                }

                if (j == needle.size()) //ģʽ�����ı���ƥ��ʱ��jӦ��ָ��ĩβ����ʱ�����±�
                {
                    return (i-needle.size()+1);
                }
            }
            return -1;   //����ѭ���ͱ����ı�����ģʽ��ƥ�䲻�ϣ�����-1
        }
 };

 int main()
 {
    Solution solution;
    string heystack;   //����ı���
    cout << "Enter heystack:";
    getline(cin, heystack);

    string needle;   //���ģʽ��
    cout << "Enter needle:";
    getline(cin, needle);

    int res = solution.strstr(heystack, needle);
    cout << res << endl;
 }
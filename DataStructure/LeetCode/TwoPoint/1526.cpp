//�ַ���ѹ��
//��Ҫ������˫ָ�룬��θ��¿���ָ���ǹؼ�
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution
{
    public:
        //����ֱ�����ַ����������轫�䵱���ַ����鴦��
        string CompressString(string s)
        {
            string result;
            //strlen() ������Ҫһ���� \0 ��β�� C ����ַ�����Ϊ����
            //int n=strlen(s);
            int n = s.length();
            int i=0,j=1;
            while (i < n)   //����ѭ����ʾ�������
            {
                while (s[i] == s[j] && j<n) //����ѭ��ʱ����j�Ѿ��ƶ�����Ԫ�ز���ͬ��λ��
                {
                    j++;
                }
                result+=s[i];
                result+=to_string(j-i); //��j-iת��Ϊ�ַ�����
                i=j; 
            } 

            if (result.length()>s.length())   //ѹ������ַ������ȴ���δѹ��ǰ
                return s;
            else
                return result;
        }
};


int main()
{
    Solution solution;

    //string���Ϳ���ֱ�Ӹ��ַ�������
    string S1 = "aabccccaaa";
    string S2 = "abbcdd";

    string result1 = solution.CompressString(S1);   
    string result2 = solution.CompressString(S2);

    //string����Ҳ����ֱ�Ӵ�ӡ
    cout << result1 << "\n";
    cout << result2 << endl;
    
}
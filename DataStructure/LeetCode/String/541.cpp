//��ת�ַ�����
#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
        //��д��
        void ReverseString(string& s,int k)
        {
            int len = s.size();
            for (int i = 0,j=k-1; i < k/2; i++,j--) //����ǰk���ַ�
            {
                swap(s[i],s[j]);
            }
            
            if (len-2*k < k)    //���ʣ���ַ�С��k��,ʣ���ַ�ȫ����ת
            {
                for (int i = 2*k,j=len-1; i < (len-2*k)/2; i++)
                {
                    swap(s[i],s[j]);
                } 
            }
            
            if (len-2*k < 2*k && len-2*k >= k)  //ʣ���ַ�С��2k�����ڻ����k��,��תǰk��
            {
                for (int i = 2*k,j=3*k-1; i < 5*k/2; i++,j--)
                {
                    swap(s[i],s[j]);
                } 
            }
        
        }
};

int main()
{
    string s = "abcdefghigklm";
    int x = 2;
    Solution solution;
    solution.ReverseString(s,4);

    cout << s << endl;
}
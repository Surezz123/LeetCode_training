//�ҵ��ַ������е������ǰ׺

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
    public:
        string LongstCommonPrefix(vector<string> & strs)    //����&strs֮����ֱ�Ӷ�strs���������в��������ӵĻ����������ַ����ĸ������в���
        {
            if (strs.empty())   //�ַ���Ϊ��ֱ�ӷ���
                return "";
            
            string prefix=strs[0];  //���ַ������еĵ�һ���ַ�������ǰ׺
            int count = strs.size();    //��¼�ַ������е��ַ�����
            for (int i = 1; i < count; i++)
            {
                prefix=LongstCommonPrefix(prefix,strs[i]);  //��prefix���������ǰ׺
                if (prefix.empty()) //ֻҪ���������ַ�������ǰ׺Ϊ�գ����еĹ���ǰ׺��Ϊ��
                {
                    break;
                }
                
            }
            return prefix;  
        }

        //��ȡ�����ַ����������ǰ׺
        string LongstCommonPrefix(const string& str1,const string& str2)  //�����str2=strs[i],�����ľͿ���ͨ��str2[i]�����ַ����е��ַ�
        {
            int length=min(str1.size(),str2.size());
            int index=0;    //��ʼ�±�Ϊ0

            while (index<length && str1[index]==str2[index])    //���αȽ��ַ����е�Ԫ��
            {
                index++;
            }
            return str1.substr(0,index);    //���������ǰ׺
        }
};


int main()
{
    Solution solution;  //��ջ�ϴ�������
    vector<string> strs={"flower","flow","flight"};
    
    string result=solution.LongstCommonPrefix(strs);    

    cout<< result <<endl;
}
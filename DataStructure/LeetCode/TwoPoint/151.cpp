//��ת�ַ�����ĵ���
//����˼·Ϊ��ȥ������ո��ٷ�ת���ʣ����ת�ַ���
#include<iostream>
#include<string>

using namespace std;

class Solution
{
    private:
        //����һ��ֱ���˵���
        void RemoveExtraSpace1(string &s)
        {
            //����ͷ���ո�
            int fast=0,slow=0,precount=0,postcount=0,incount=0;
            while (s[fast]==' ')   //�����ַ���ͷ���ո�
            {
                fast++;
                precount++;
            }
            
            while (fast<s.size())      
            {
                s[slow]=s[fast];
                slow++;
                fast++;
            }
            s.resize(s.size()-precount);
            
            //����β���ո�
            while (s[fast-1]==' ')  //fastָ��n���Ӻ��濪ʼ�ҿո����
            {
                fast--;
                postcount++;
            }
            s.resize(s.size()-postcount);   

             //�����м����ո�
            fast=0;
            slow=0;
            while (s[fast]!=' ' && fast<s.size())
            {
                fast++;
            }
            while (s[fast]==' ' && fast<s.size())
            {
                fast++;
                incount++;
            }
            if (incount > 1)
            {
                while (fast<s.size())     
                {
                    s[fast-incount+1]=s[fast];
                    fast++;
                }
                s.resize(s.size()-incount);
            }
            
        }
    public:
        //��ת�ַ���
        void ReverseString(string &s,int begin,int end)
        {
            for (int i = begin,j=end; i < j; i++,j--)
            {
                swap(s[i],s[j]);
            }
        }
        
        //�������ո�(ͷβû�пո񣬵����뵥��֮�����һ���ո�)
        //��������˫ָ�뷨(�������Ƴ�Ԫ��)
        void RemoveExtraSpace2(string &s)
        {
            int slow=0;
            for (int i = 0; i < s.size(); i++)  
            {
                if (s[i] != ' ')    //Ѱ�Ҳ��ǿո��Ԫ�ؽ������飬�е�������ɾ��Ԫ�أ��ҵ�����value��Ԫ��
                {
                    if (slow!=0)    //slow��Ϊ0˵�������ڵ�һ������,��ʱ��֤���ʺ͵���֮��һ��Ҫ��һ���ո�
                        s[slow++]=' ';
                    while (s[i]!=' '&& i<s.size())
                    {
                        s[slow++]=s[i++];
                    }
                    
                }
            }
            s.resize(slow); //���slow��ָ�����һ�����ʵ�ĩβ
        }

        //��ת����
        string ReverseWord(string s)    
        {
            RemoveExtraSpace2(s);
            ReverseString(s,0,s.size()-1);
            int slow=0,fast=0;

            while (fast < s.size())
            {
                while (s[fast] != ' ' && fast<s.size())    //����ѭ��ʱ�����Ѿ��ҵ�һ������
                {
                    fast++;
                }

                int temp = fast-1;

                while (slow<temp)   //�ҵ�һ�����ʲ�ԭ�ؽ���
                {
                    swap(s[slow],s[temp]);
                    slow++;
                    temp--;
                }
                
                while (s[fast]==' ' && fast<s.size())  //Ѱ����һ������
                {
                    slow=fast+1;
                    fast++;
                }
                
            }
            return s;
        }
};


int main()
{
    Solution solution;
    string s="  hello   world!  ";

    string res = solution.ReverseWord(s);
    cout << res << endl;
}


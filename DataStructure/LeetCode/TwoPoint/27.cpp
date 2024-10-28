//�Ƴ�Ԫ��
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        //ͨ�����&���ſ���ֱ�Ӷ�����a���в���
        int RemoveElement(vector<int>& a,int value) 
        {   
            int slow=0;
            //˫ָ���е�fastָ�������ҵ���valueֵ����ͬ��Ԫ��
            for (int fast = 0; fast < a.size(); fast++)
            {
                if (a[fast] != value)
                {
                    a[slow]=a[fast];    //�൱��a[slow++]=a[fast]
                    slow++;
                }
            }
            return slow;    //����������
        }
};

int main()
{
    Solution solution;
    vector<int> a= {0,1,2,2,3,0,4,2};

    int num = solution.RemoveElement(a,2);

    for (int i = 0; i < num; i++)
    {
        cout << a[i] << " ";
    }
    
}

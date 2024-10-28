//�Ƴ�Ԫ��
//����ָ�뷨
//��ν�Ŀ���ָ�뷨����fast����ʲô�����++,slow�Ļ�ֻ�з�������ʱ��++

#include<vector>
#include<iostream>
using namespace std;

class Solution{
    public:
        int RemoveElement(vector<int>& nums,int val)    //���Ҫɾ����ֵ�����飬���ص�ֵΪint����
        {
            int n=nums.size();  //���鳤��
            int slow=0,fast=0;  //�������ָ��

            while (fast<n)  //��û�е��߽�ʱ
            {
                if (nums[fast]!=val)    //fast���ҵ���һ����Ϊval��λ�ã�Ϊ��дslow��׼��
                {
                    nums[slow]=nums[fast];  //��д����
                    slow++;
                }
                fast++; //����slowʲô�����fast��++
            }
            
            return slow;    //������ָ��
        }    
};


int main()
{
    Solution* solution=new Solution();
    vector<int> nums={1,2,2,3,4,5};
    
    int num=(*solution).RemoveElement(nums,2);

    for (int i = 0; i < num; i++)
    {
        cout<< nums[i]<< "";
    }

    delete solution;
    free;
    return 0;
}
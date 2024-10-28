//������С��������

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    private:
    /* data */
    public: 
        //�����ⷨ
        int MinSubArrayLen1(vector<int> nums,int s)
        {
            int length=nums.size();
            int result=INT32_MAX;   //���ս��
            int sublength=0;
            for (int i = 0; i < length; i++)
            {
                int sum=0;  //ÿ�ν�iѭ��ʱ�����ʼ��
                for (int j = i; j < length; j++)
                {
                    sum+=nums[j];
                    if (sum>=s)
                    {
                        sublength=(j-i+1);   //�ݴ浽sublength�У�Ϊ��ǰi���ҵ�����С����
                        result=result < sublength ? result : sublength; //����Ԫ�����һֱ�ҵ�������Сֵ
                        break;  //�ҵ�i=0����Сֵ��ֱ��break�������ڲ�ѭ��
                    }
                    
                }
                
            }
            return result==INT32_MAX ? 0 : result;
        }

        //��������
        int MinSubArrayLen2(vector<int> nums,int s)
        {
            int length=nums.size();
            int sublength=0,j=0,sum=0;  //sum������forѭ���г�ʼ��
            int result=INT32_MAX;
            for (int i = 0; i < length; i++)
            {
                sum+=nums[i];
                while (sum>=s)
                {
                    sublength=(i-j+1);    //һ��ʼ��i=j=0��ʼ�ҵ���һ������
                    result=result<sublength? result:sublength;  //�ҳ���Сֵ
                    sum-=nums[j++];      //�ƶ����ڵ�ͬʱ�Ѵ�����С������ֻ����j++��������++j
                }
                
            }
            return result==INT32_MAX ? 0 : result;
        }
};


int main()
{
    vector<int> nums={2,3,1,2,4,3};
    Solution solution;

    int length=solution.MinSubArrayLen2(nums,7);
    cout << length << endl;
}

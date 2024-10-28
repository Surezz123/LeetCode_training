//���������ƽ��

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution{
    public:
        //�����ⷨ:�ȶԸ���Ԫ��ƽ����������
        vector<int> SortedSquares1(vector<int>& nums)    
        {   
            int length=nums.size();
            int max=0;

            for (int i = 0; i < length; i++)
            {
                nums[i]=pow(nums[i],2); //ÿ������ȡƽ��
            }
            sort(nums.begin(),nums.end());
            return nums;
        }

        //˫ָ�뷨:��ʵ����������ģ�ֻ��ƽ��֮��˳����ң��������ֵһ������������������
        vector<int> SortedSquares2(vector<int>& nums)   
        {
            int length=nums.size();
            int k=length-1,i=0,j=length-1;   //i,jΪ˫ָ��
            vector<int> result(length);     //��������ʱû��ֵ����������

            while (k>=0)    
            {
                if ((nums[i]*nums[i])<(nums[j]*nums[j]))  
                {
                    result[k--]=nums[j]*nums[j];    
                    j--;
                }
                else
                {
                    result[k--]=nums[i]*nums[i];    
                    i++;
                }
            }
            return result;
        }
};


int main()
{
    vector<int> nums={-4,-1,0,3,10};
    int num=nums.size();
    Solution* solution=new Solution();

    //vector<int> Sortednums1=solution->SortedSquares1(nums);
    vector<int> Sortednums2=solution->SortedSquares2(nums);

    for (int i = 0; i < num; i++)
    {
        //cout << Sortednums1[i] << " ";
        cout << Sortednums2[i] << " ";
    }
    return 0;
}


//有序数组的平方

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution{
    public:
        //暴力解法:先对各个元素平方，再排序
        vector<int> SortedSquares1(vector<int>& nums)    
        {   
            int length=nums.size();
            int max=0;

            for (int i = 0; i < length; i++)
            {
                nums[i]=pow(nums[i],2); //每个数先取平方
            }
            sort(nums.begin(),nums.end());
            return nums;
        }

        //双指针法:其实数组是排序的，只是平方之后顺序打乱，但是最大值一定会在数组左右两端
        vector<int> SortedSquares2(vector<int>& nums)   
        {
            int length=nums.size();
            int k=length-1,i=0,j=length-1;   //i,j为双指针
            vector<int> result(length);     //定义数组时没初值可以这样做

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


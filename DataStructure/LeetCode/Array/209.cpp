//长度最小的子数组

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    private:
    /* data */
    public: 
        //暴力解法
        int MinSubArrayLen1(vector<int> nums,int s)
        {
            int length=nums.size();
            int result=INT32_MAX;   //最终结果
            int sublength=0;
            for (int i = 0; i < length; i++)
            {
                int sum=0;  //每次进i循环时将其初始化
                for (int j = i; j < length; j++)
                {
                    sum+=nums[j];
                    if (sum>=s)
                    {
                        sublength=(j-i+1);   //暂存到sublength中，为当前i能找到的最小长度
                        result=result < sublength ? result : sublength; //用三元运算符一直找到最后的最小值
                        break;  //找到i=0的最小值后直接break，跳出内部循环
                    }
                    
                }
                
            }
            return result==INT32_MAX ? 0 : result;
        }

        //滑动窗口
        int MinSubArrayLen2(vector<int> nums,int s)
        {
            int length=nums.size();
            int sublength=0,j=0,sum=0;  //sum不能在for循环中初始化
            int result=INT32_MAX;
            for (int i = 0; i < length; i++)
            {
                sum+=nums[i];
                while (sum>=s)
                {
                    sublength=(i-j+1);    //一开始从i=j=0开始找到第一个窗口
                    result=result<sublength? result:sublength;  //找出最小值
                    sum-=nums[j++];      //移动窗口的同时把窗口缩小，这里只能是j++而不能是++j
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

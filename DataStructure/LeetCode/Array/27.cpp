//移除元素
//快慢指针法
//所谓的快慢指针法就是fast无论什么情况都++,slow的话只有符合条件时才++

#include<vector>
#include<iostream>
using namespace std;

class Solution{
    public:
        int RemoveElement(vector<int>& nums,int val)    //输出要删除的值与数组，返回的值为int类型
        {
            int n=nums.size();  //数组长度
            int slow=0,fast=0;  //定义快慢指针

            while (fast<n)  //当没有到边界时
            {
                if (nums[fast]!=val)    //fast先找到下一个不为val的位置，为覆写slow做准备
                {
                    nums[slow]=nums[fast];  //覆写数组
                    slow++;
                }
                fast++; //无论slow什么情况，fast都++
            }
            
            return slow;    //返回慢指针
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
//���ֲ���
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    private:
        /* data */
    public:
        int SearchElement(vector<int> nums,int target)
        {
            int index=0;
            int left=0,right=nums.size()-1;
            while (left<=right)     //�൱������ұ�����
            {         
                int mid=(left+right)/2;
                if (nums[mid]>target)
                {
                    right=mid-1;
                }
                else if(nums[mid]<target)
                {
                    left=mid+1;
                }
                else
                {
                    index=mid;
                    return index;
                    break;
                }
            }
            return -1;  //û�ҵ�ʱ����-1
        }
};


int main()
{
    Solution solution;
    vector<int> nums={-1,0,3,5,9,12};
    int result=0;

    result=solution.SearchElement(nums,12);
    cout<< result << endl;
}


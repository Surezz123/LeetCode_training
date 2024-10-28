//移除元素
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        //通过添加&符号可以直接对数组a进行操作
        int RemoveElement(vector<int>& a,int value) 
        {   
            int slow=0;
            //双指针中的fast指针用于找到与value值不相同的元素
            for (int fast = 0; fast < a.size(); fast++)
            {
                if (a[fast] != value)
                {
                    a[slow]=a[fast];    //相当于a[slow++]=a[fast]
                    slow++;
                }
            }
            return slow;    //返回新数组
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

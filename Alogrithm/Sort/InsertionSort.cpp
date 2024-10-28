#include<iostream>
#include<vector>

using namespace std;

class InsertSort
{
    public:
        //循环实现
        void insertsort(vector<int>& arr)
        {
            for (int i = 1; i < arr.size(); i++)
            {
                int temp = arr[i];  // 取出待插入的元素
                int j = i - 1;
                
                // 向前寻找插入位置，同时将大于 temp 的元素向后移动
                while (j >= 0 && arr[j] > temp)
                {
                    arr[j + 1] = arr[j];  // 移动元素
                    j--;
                }
                
                // 将待插入元素放到合适的位置
                arr[j + 1] = temp;
            }
        }

        //递归实现
        void insertsort2(vector<int>& arr, int n)
        {
            if (n <= 1)
            {
                return;
            }
            
            insertsort2(arr, --n);

            int temp = arr[n-1];  // 取出待插入的元素
            int j = n - 2;
                
            // 向前寻找插入位置，同时将大于 temp 的元素向后移动
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];  // 移动元素
                j--;
            }
                
            // 将待插入元素放到合适的位置
            arr[j + 1] = temp;
        }
};


int main()
{
    InsertSort is;
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    is.insertsort2(arr, arr.size());

    for(int num : arr)  //遍历需使用正确
    {
        cout << num << ' ';
    }
}
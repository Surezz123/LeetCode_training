#include<iostream>
#include<vector>

using namespace std;

class QuickSort
{
    private:
        int partition(vector<int>& arr, int start, int end)
        {
            int pivot = arr[start];
            int left = start + 1, right = end;
            while (left <= right)
            {
                while (left <= right &&arr[left] <= pivot) //在左区间找到第一个比pivot大的值
                {
                    left++;
                }

                while (left <= right && arr[right] > pivot ) //在右区间找到第一个比pivot小的值
                {
                    right--;
                }

                if (left < right)
                {
                    swap(arr[left], arr[right]);
                }
            }
            swap(arr[start], arr[right]);
            return right;
        }

    public:
        void quicksort(vector<int>& arr, int start, int end)
        {
            if (start >= end)
            {
                return;
            }
            
            int pivot = partition(arr, start, end);
            quicksort(arr, start, pivot-1);
            quicksort(arr, pivot+1, end);
        }
};

int main()
{
    QuickSort qs;
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    qs.quicksort(arr, 0, arr.size() - 1);

    for(int num : arr)  //遍历需使用正确
    {
        cout << num << ' ';
    }
}


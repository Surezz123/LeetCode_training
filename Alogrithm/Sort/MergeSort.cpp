#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MergeSort {
public:
    void mergesort(vector<int>& arr, int left, int right) 
    {
        if (left >= right)
        {
            return;
        }
        
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);      //左区间归并
        mergesort(arr, mid + 1, right);     //右区间归并

        merge(arr, left, mid, right);   //左右区间合并
    }

private:
    void merge(vector<int>& arr, int left, int mid, int right) 
    {
        vector<int> temp(right - left + 1); //创建临时数组
        int k = 0;  //temp索引
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right)  //跳出循环时至少左右区间有一边到头
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            } 
        }
            
        while (i <= mid)    //若左区间有剩余元素，将其直接并入arr，剩下元素比temp中元素都大且有序，直接插入temp
        {
            temp[k++] = arr[i++];
        }

        while (j <= right)    //若右区间有剩余元素，将其直接并入arr
        {
            temp[k++] = arr[j++];
        }
        
        for (int p = 0; p < temp.size(); p++)
        {
            arr[left + p] = temp[p];    //这里是从left开始复制，因此后续用到了递归，所以不能只从0开始
        }
        
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    
    MergeSort ms;
    ms.mergesort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
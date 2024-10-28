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
        mergesort(arr, left, mid);      //������鲢
        mergesort(arr, mid + 1, right);     //������鲢

        merge(arr, left, mid, right);   //��������ϲ�
    }

private:
    void merge(vector<int>& arr, int left, int mid, int right) 
    {
        vector<int> temp(right - left + 1); //������ʱ����
        int k = 0;  //temp����
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right)  //����ѭ��ʱ��������������һ�ߵ�ͷ
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
            
        while (i <= mid)    //����������ʣ��Ԫ�أ�����ֱ�Ӳ���arr��ʣ��Ԫ�ر�temp��Ԫ�ض���������ֱ�Ӳ���temp
        {
            temp[k++] = arr[i++];
        }

        while (j <= right)    //����������ʣ��Ԫ�أ�����ֱ�Ӳ���arr
        {
            temp[k++] = arr[j++];
        }
        
        for (int p = 0; p < temp.size(); p++)
        {
            arr[left + p] = temp[p];    //�����Ǵ�left��ʼ���ƣ���˺����õ��˵ݹ飬���Բ���ֻ��0��ʼ
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
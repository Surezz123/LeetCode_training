#include<iostream>
#include<vector>

using namespace std;

class InsertSort
{
    public:
        //ѭ��ʵ��
        void insertsort(vector<int>& arr)
        {
            for (int i = 1; i < arr.size(); i++)
            {
                int temp = arr[i];  // ȡ���������Ԫ��
                int j = i - 1;
                
                // ��ǰѰ�Ҳ���λ�ã�ͬʱ������ temp ��Ԫ������ƶ�
                while (j >= 0 && arr[j] > temp)
                {
                    arr[j + 1] = arr[j];  // �ƶ�Ԫ��
                    j--;
                }
                
                // ��������Ԫ�طŵ����ʵ�λ��
                arr[j + 1] = temp;
            }
        }

        //�ݹ�ʵ��
        void insertsort2(vector<int>& arr, int n)
        {
            if (n <= 1)
            {
                return;
            }
            
            insertsort2(arr, --n);

            int temp = arr[n-1];  // ȡ���������Ԫ��
            int j = n - 2;
                
            // ��ǰѰ�Ҳ���λ�ã�ͬʱ������ temp ��Ԫ������ƶ�
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];  // �ƶ�Ԫ��
                j--;
            }
                
            // ��������Ԫ�طŵ����ʵ�λ��
            arr[j + 1] = temp;
        }
};


int main()
{
    InsertSort is;
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    is.insertsort2(arr, arr.size());

    for(int num : arr)  //������ʹ����ȷ
    {
        cout << num << ' ';
    }
}
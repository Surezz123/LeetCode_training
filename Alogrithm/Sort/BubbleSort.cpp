#include<iostream>
#include<vector>

using namespace std;

class BubbleSort
{
    public:
        void bubblesort1(vector<int>& arr)
        {  
            //i���ڿ��ƽ���Ԫ�ص��ִ�
            for (int i = 0; i < arr.size()-1; i++)
            {   
                //�ڵ�i��ʱ�����i-1��Ԫ���Ѿ����򣬲���Ҫ�ٽ��бȽ�
                for (int j = 0; j < arr.size()-1-i; j++)
                {
                    if (arr[j] > arr[j+1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                } 
            }
        }

        void bubblesort2(vector<int>& arr, int n)
        {
            if (n <= 1)
            {
                return;
            }
            
            for (int i = 0; i < n-1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
            bubblesort2(arr, --n);
        }
};

int main()
{
    BubbleSort bs;
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    bs.bubblesort2(arr, arr.size());

    for(int num : arr)  //������ʹ����ȷ
    {
        cout << num << ' ';
    }
}


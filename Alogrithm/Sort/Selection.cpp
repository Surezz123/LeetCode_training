#include<iostream>
#include<vector>

using namespace std;

class SelectSort
{
    public:
        void selectsort(vector<int>& arr)
        {  
            for (int i = 0; i < arr.size(); i++)
            {
                for (int j = i+1; j < arr.size(); j++)
                {
                    if (arr[i] > arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    } 
                }
            }
        }

        void selectsort2(vector<int>& arr, int start, int n)
        {
            if (start >= n-1)
            {
                return;
            }
            
            int MinIndex = start;
            for (int i = start+1; i < n; i++)
            {
                if (arr[MinIndex] > arr[i])
                {
                    int temp = arr[i];
                    arr[i] = arr[MinIndex];
                    arr[MinIndex] = temp;
                }
            }
            
            selectsort2(arr, start+1, arr.size());
        }
};

int main()
{
    SelectSort ss;
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    ss.selectsort2(arr, 0, arr.size());

    for(int num : arr)  //遍历需使用正确
    {
        cout << num << ' ';
    }
}
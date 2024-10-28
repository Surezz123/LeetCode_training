#include<iostream>
#include<vector>

using namespace std;

class ShellSort
{
    private:
        void insertsort(vector<int> arr)
        {
            
        }
    public:
        void shellsort(vector<int> arr, int n)
        {
            int seg = (n/2) - 1;
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j += seg)
                {
                    
                }
                
            }
            

        }
};

int main()
{
    ShellSort ss;
    vector<int> arr = {12, 11, 13, 5, 6, 10, 14, 2, 1, 7, 8, 3, 9, 4, 15};
    ss.shellsort(arr, arr.size());

    for(int num : arr)  //遍历需使用正确
    {
        cout << num << ' ';
    }
}
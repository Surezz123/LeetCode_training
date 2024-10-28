//�ϲ����飬ʹ�ϲ�������鰴�ǵݼ�˳������
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        vector<int> MergeArray(vector<int>& arr1, vector<int>& arr2)
        {
            int i = 0, j = 0, k = 0;
            int arr1Len = arr1.size();
            int arr2Len = arr2.size();
            vector<int> Merge(arr1Len + arr2Len);

            while (i < arr1Len && j < arr2Len)
            {
                if (arr1[i] <= arr2[j])
                {
                    Merge[k++] = arr1[i++];
                }
                else
                {
                    Merge[k++] = arr2[j++];
                }
            }
            
            //����arr1��ʣ��Ԫ��
            while (i < arr1Len)
            {
                Merge[k++] = arr1[i++];
            }

            //����arr2��ʣ��Ԫ��
            while (j < arr2Len)
            {
                Merge[k++] = arr2[j++];
            }

            return Merge;
        }
};

int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 9, 11};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    Solution solution;

    vector<int> res = solution.MergeArray(arr1, arr2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
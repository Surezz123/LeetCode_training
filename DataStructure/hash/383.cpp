//赎金信
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
    public:
        bool canConstruct(string ransonNote, string magazine)
        {
            //该题说明了只存在小写字母，所以数组的大小是确定的
            vector<int> arr(26);

            if (ransonNote.size() > magazine.size())
            {
                return false;
            }
            
            //遍历ransonNote，记录元素个数
            for (int i = 0; i < ransonNote.size(); i++)
            {
                int index = ransonNote[i] - 'a';
                arr[index]++;
            }
            
            //遍历magazine，把arr中a-z的个数
            for (int i = 0; i < magazine.size(); i++)
            {
                int index = magazine[i] - 'a';
                if (arr[index] == 0)
                {
                    continue;
                }

                arr[index]--;
            }
            
            //遍历arr，如果arr中的元素有非零，则表明ransomNote能不能由magazine里面的字符构成
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }
};

int main()
{
    string ransonNote, magazine;
    getline(cin, ransonNote);
    getline(cin, magazine);
    Solution solution;

    cout << boolalpha <<solution.canConstruct(ransonNote, magazine);
    
}
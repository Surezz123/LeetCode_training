//有效的字母异位词，简单来说就是两个字符串的字母个数是否相同
//该题主要是用数组抽象为哈希表，数组中依次存储的数为a-z字母的个数，同时因为该题限制了a-z的个数一定是26个，所以该题可以使用数组
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
    public:
        bool IsAnagram(string s, string t)
        {
            vector<int> arr(26);    //该数组用于存放字符串中a-z的个数
            //将字符串中a-z的个数存于arr中
            for (int i = 0; i < s.size(); i++)
            {
                int index = s[i] - 'a'; //arr的下标index
                arr[index]++;
            }
            
            //再遍历字符串t，根据t的a-z个数在arr中对应减去
            for (int i = 0; i < t.size(); i++)
            {
                int index = t[i] - 'a';
                arr[index]--;
            }
            
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
    string s, t;
    getline(cin, s);
    getline(cin, t);

    Solution solution;
    bool res = solution.IsAnagram(s, t);

    cout << boolalpha << res << endl;   //以true和false来输出res
    return 0;
}
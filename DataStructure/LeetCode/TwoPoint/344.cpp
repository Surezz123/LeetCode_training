// ?????

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void ReverseString(vector<char> &str)
    {
        for (int slow = 0, fast = str.size() - 1; slow < str.size() / 2; slow++, fast--)
        {
            swap(str[slow], str[fast]);
        }
    }

    string ReverseString(char str[])
    {
        string s(str); // ???????????
        reverse(s.begin(), s.end());

        return s;
    }
};

int main()
{
    Solution solution;
    vector<char> str1 = {'h', 'e', 'l', 'l', 'o'};
    char str2[]={'h', 'e', 'l', 'l', 'o','1','\0'}; //???????????'\0'???
    solution.ReverseString(str1);

    for (int i = 0; i < str1.size(); i++)
    {
        cout << str1[i] << " ";
    }
    cout << "\n";

    string res = solution.ReverseString(str2);
    cout << res << endl;
}

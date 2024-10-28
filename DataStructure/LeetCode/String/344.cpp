//·´×ª×Ö·û´®
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        void ReverseString(vector<char>& s)
        {
            for (int i = 0,j=s.size()-1; i < s.size()/2; i++,j--)
            {
                swap(s[i],s[j]);
            }
            
        }
};

int main()
{
    vector<char> s ={'h','e','l','l','o'};
    Solution solution;
    solution.ReverseString(s);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    
}
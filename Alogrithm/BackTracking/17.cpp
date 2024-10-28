//电话号码的字母组合，这个题不同于前面两道，是求不同数字之间的组合
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BackTracking
{
    private:
        //数字和字母一一对应
        const string LetterMap[10]=
        {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        }; 
        string s;
        vector<string> res; //用于存放结果

        void backtracking(const string& digits, int index)
        {
            if (index == digits.size())    //终止条件，当遍历完digits字符串时此时将s压入res中并返回
            {
                res.push_back(s);
                return;
            }
            
            int digit = digits[index] - '0';    //这里的index表示的是输入的digits字符串中的第几个数字
            string letters = LetterMap[digit];
            for (int i = 0; i < letters.size(); i++)    //这个for循环是遍历letters里的字母，比如按下1时遍历abc进行组合
            {
                s.push_back(letters[i]);
                backtracking(digits, index+1);   //与下一个数字的字母进行组合
                s.pop_back();
            }
            
        }
    
    public:
        vector<string> letterCombinations(const string& digits) 
        {
            s.clear();
            res.clear();
            int index = 0;
            if (digits.size() == 0)
            {
                return res;
            }
            
            backtracking(digits, index);
            return res;
        }
};

int main()
{
    string digits;
    getline(cin, digits);
    BackTracking backtracking;
    vector<string> res = backtracking.letterCombinations(digits);

    cout << "[";
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << "\"" << res[i] << "\"";
        if (i < res.size()-1)
        {
            cout << ", ";
        }
        
    }
    cout << "]";
    return 0;
}
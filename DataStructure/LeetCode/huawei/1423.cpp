//可获得的最大点数

#include<iostream>
#include<numeric>  // 可用std::accumulate
#include<algorithm>  // 可用std::min
#include<vector>
using namespace std;

class Solution
{
    public:
    int maxScore(std::vector<int>& cardPoints,int k)
    {
        int n=cardPoints.size();//数组长度
        int totalSum=std::accumulate(cardPoints.begin(),cardPoints.end(),0);    //起始迭代器,结束迭代器,初始值
        int windowSize=n-k; //窗口大小

        if (windowSize==0)  //k=n,表明把牌全部拿起
        {
            return totalSum;
        }
        
        int minSum=std::accumulate(cardPoints.begin(),cardPoints.begin()+windowSize,0); //初始化窗口
        int currentSum=minSum;

        for (int i = windowSize; i < n; i++)    //循环找到最小值窗口
        {
            currentSum+=cardPoints[i]-cardPoints[i-windowSize]; //向右移动时减去最左边元素加最右边元素
            minSum=std::min(minSum,currentSum);
        }
        return totalSum-minSum;
    }
};

int main()
{
    Solution* solution=new Solution();
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k=3;
    int maxscore=solution->maxScore(cardPoints,k);
    cout<<maxscore<<endl;
    delete solution;
    return 0;

}
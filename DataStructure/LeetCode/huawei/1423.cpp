//�ɻ�õ�������

#include<iostream>
#include<numeric>  // ����std::accumulate
#include<algorithm>  // ����std::min
#include<vector>
using namespace std;

class Solution
{
    public:
    int maxScore(std::vector<int>& cardPoints,int k)
    {
        int n=cardPoints.size();//���鳤��
        int totalSum=std::accumulate(cardPoints.begin(),cardPoints.end(),0);    //��ʼ������,����������,��ʼֵ
        int windowSize=n-k; //���ڴ�С

        if (windowSize==0)  //k=n,��������ȫ������
        {
            return totalSum;
        }
        
        int minSum=std::accumulate(cardPoints.begin(),cardPoints.begin()+windowSize,0); //��ʼ������
        int currentSum=minSum;

        for (int i = windowSize; i < n; i++)    //ѭ���ҵ���Сֵ����
        {
            currentSum+=cardPoints[i]-cardPoints[i-windowSize]; //�����ƶ�ʱ��ȥ�����Ԫ�ؼ����ұ�Ԫ��
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
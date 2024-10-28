//��������Ľ���
//��ϣ�����ó��ľ��Ǹ���һ��Ԫ�أ��ж����Ԫ���Ƿ���ֹ�
#include<iostream>
#include<vector>
#include<string>
//set,multiset�ײ�ʵ��Ϊ�������unordered_set�ײ�ʵ��Ϊ��ϣ,����ӳ���ȡֵ����ʱЧ�����
#include<unordered_set> 
using namespace std;

class Solution
{
    public:
        vector<int> intersection(vector<int>& num1, vector<int>& num2)
        {
            unordered_set<int> res_set; //���ڴ�������������set�����ȥ���ظ�Ԫ�أ����Բ���Ҫ���н���
            unordered_set<int> num1_set(num1.begin(), num1.end());  //��num1������Ԫ�ط���num1_set�У�ͬʱ��ȥ��

            for(int num : num2)
            {
                if(num1_set.find(num) != num1_set.end())    //����num2�е�Ԫ�أ�ͬʱ��ѯ�Ƿ���ֵ������num1_set1��
                {
                    res_set.insert(num);    //���ڽ�ֵ���뵽res_set��
                }
            }
            
            return vector<int>(res_set.begin(), res_set.end()); //��res_setת��Ϊvector������ 
        }
};

int main()
{
    Solution solution;
    vector<int> num1, num2, res;
    int num;
    while (cin >> num)
    {
        num1.push_back(num);
        if(cin.peek() == '\n')
            break;
    }

    while (cin >> num)
    {
        num2.push_back(num);
        if(cin.peek() == '\n')
            break;
    }
    
    res = solution.intersection(num1, num2);
    for(auto num : res)
    {
        cout << num << ' ';
    }
    
    return 0;
}

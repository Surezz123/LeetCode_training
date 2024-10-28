//����ʵ�ֶ���������
#include<iostream>
#include<set>   //�������������Ե�������������
#include<map>   //����������Ҳ���Ե�������������

using namespace std;

struct BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;
};


BSTNode* GetNewNode(int x)  //�����½ڵ�
{
    BSTNode* newNode = new BSTNode(); //�κ��ڶ�̬�ڴ���߶��Ϸ�����ڴ涼ֻ��ͨ��ָ�����
    newNode->value=x;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

BSTNode* Insert(BSTNode* root,int x)   //ʹ�õݹ�ʱ��Ҫ������һ����ָ��
{ 
    if (root == NULL)   //Ϊ����ʱ��ͬʱ��Ϊ�˳��ݹ������
    {
        root=GetNewNode(x);
    }
    else if (x <= root->value)
    {
        root->left = Insert(root->left,x);  //���ж��õݹ�������Ԫ��
    }
    else
    {
        root->right = Insert(root->right,x);
    }
    return root;
    
}

bool Search(BSTNode* root,int x)
{
    if (root == NULL)   //������Ҳ�����ݹ��˳�������
        return false;

    if (x == root->value)
        return true;

    else if (x < root->value)  //x��������ʱ
        return Search(root->left,x);    //������Ҫreturn���������������Ľ��

    else
        return Search(root->right,x);
}

int main()
{
    BSTNode* root=NULL;     //����ɾֲ�����
    int number;
    
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);

    cout<<"Enter number be searched:" ;
    cin>>number;    //cin��cout����һ��

    if(Search(root,number)==true)   
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    
}
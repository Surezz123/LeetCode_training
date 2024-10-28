//链表实现二叉搜索树
#include<iostream>
#include<set>   //有序容器，可以当作二叉搜索树
#include<map>   //有序容器，也可以当作二叉搜索树

using namespace std;

struct BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;
};


BSTNode* GetNewNode(int x)  //创建新节点
{
    BSTNode* newNode = new BSTNode(); //任何在动态内存或者堆上分配的内存都只能通过指针访问
    newNode->value=x;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

BSTNode* Insert(BSTNode* root,int x)   //使用递归时需要返回下一级的指针
{ 
    if (root == NULL)   //为空树时，同时作为退出递归的条件
    {
        root=GetNewNode(x);
    }
    else if (x <= root->value)
    {
        root->left = Insert(root->left,x);  //树中都用递归来插入元素
    }
    else
    {
        root->right = Insert(root->right,x);
    }
    return root;
    
}

bool Search(BSTNode* root,int x)
{
    if (root == NULL)   //空树，也用作递归退出的条件
        return false;

    if (x == root->value)
        return true;

    else if (x < root->value)  //x在左子树时
        return Search(root->left,x);    //这里需要return在左子树上搜索的结果

    else
        return Search(root->right,x);
}

int main()
{
    BSTNode* root=NULL;     //定义成局部变量
    int number;
    
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,8);
    root=Insert(root,12);

    cout<<"Enter number be searched:" ;
    cin>>number;    //cin和cout方向不一样

    if(Search(root,number)==true)   
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    
}
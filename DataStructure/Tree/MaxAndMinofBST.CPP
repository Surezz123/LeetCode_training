#include<iostream>
#include<map>   //

using namespace std;

//使用map的方式解决此问题
// int main()
// {
//     map<int,int>bst;    //用map创建一个空的二叉搜索树

//     bst[10]=100;    //这里二叉搜索树的实现是通过键值对实现的，找的是键最小对应的键值，而不是最小元素
//     bst[5]=50;
//     bst[13]=150;
//     bst[4]=30;
//     bst[7]=70;

//     for(const auto & pair:bst)  //遍历二叉搜索树(不懂，官方说法是map内部使用了红黑树这种自平衡二叉搜索树的数据结构)
//     {
//         cout << "key:" << pair.first << ",value" << pair.second << endl;
//     }

//     auto Min=bst.begin();   //找到最小值并输出
//     cout << "Minimum key: " << Min->first << ", Value: " << Min->second << endl;

//     auto Max=bst.end();     //找到最大值并输出
//     --Max;                  //也不太懂这里为什么要--
//     cout << "Minimum key: " << Max->first << ", Value: " << Max->second << endl;
// }

//使用自定义二叉搜索树解决此问题
struct BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;
};

//BSTNode* root = NULL;

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
    if (root == NULL)   //为空树时
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

//找最小值
BSTNode* FoundMin(BSTNode* root)  
{
    //写法一(递归)
    if (root == NULL)
        return NULL;

    if (root->left==NULL)   //递归退出条件，当root->left为空时表明该节点已经时二叉搜索树最左边的节点，直接返回即可
        return root;

    else
        return FoundMin(root->left);


    // //写法二(直接遍历)
    // BSTNode* current = root;
    // while (current->left != NULL)
    // {
    //     current=current->left;
    // }
    // return current;

}

//找最大值
BSTNode* FoundMax(BSTNode* root)  
{
    //写法一(递归)
    if (root == NULL)   //空树
        return NULL;

    if (root->right==NULL)  //递归退出条件，当root->right为空时表明该节点已经时二叉搜索树最右边的节点，直接返回即可
        return root;

    else
        return FoundMax(root->right);

    // //写法二(直接遍历)
    // BSTNode* current = root;
    // while (current->right != NULL)
    // {
    //     current=current->right;
    // }
    // return current;

}

int main()
{
    BSTNode* root = NULL;
    BSTNode* temp = NULL;

    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    temp=FoundMax(root);
    cout<< temp->value <<"\n";

    temp=FoundMin(root);
    cout<< temp->value <<"\n";
}
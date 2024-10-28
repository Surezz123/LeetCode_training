//深度优先搜索树
#include<iostream>
using namespace std;

struct BSTNode
{
    int value;
    BSTNode* right;
    BSTNode* left;
};

class BSTtraversal
{
    private:
        //创建新节点函数
        BSTNode* GetNewNode(int x)  //创建新节点
        {
            BSTNode* newNode = new BSTNode(); //任何在动态内存或者堆上分配的内存都只能通过指针访问
            newNode->value=x;
            newNode->left=NULL;
            newNode->right=NULL;

            return newNode;
        }

    public:
        //插入节点函数
        BSTNode* Insert(BSTNode* root,int x)   //使用递归时需要返回下一级的指针
        { 
            if (root == NULL)   //为空树时，同时作为退出递归的条件
                root=GetNewNode(x);

            else if (x <= root->value)
                root->left = Insert(root->left,x);  //树中都用递归来插入元素

            else
                root->right = Insert(root->right,x);
            return root;
    
        }

        //二叉树的前序遍历(三种遍历都是通过递归实现的)
        void Preorder(BSTNode* root)
        {
            if(root == NULL)
                return;
            cout << root->value << " ";
            Preorder(root->left);
            Preorder(root->right);
        }

        //二叉树的中序遍历
        void Inorder(BSTNode* root)
        {
            if (root == NULL)
                return;
            Inorder(root->left);
            cout << root->value <<" ";
            Inorder(root->right);
        }

        //二叉树的后序遍历  
        void Postorder(BSTNode* root)
        {
            if (root == NULL)
                return;
            Postorder(root->left);
            Postorder(root->right);
            cout << root->value <<" ";
        }

};


int main()
{
    BSTNode* root = NULL;
    BSTtraversal bst;
    root=bst.Insert(root,10);
    root=bst.Insert(root,20);
    root=bst.Insert(root,8);
    root=bst.Insert(root,9);
    root=bst.Insert(root,25);
    root=bst.Insert(root,15);
    root=bst.Insert(root,7);

    bst.Preorder(root);
    cout << "\n";
    bst.Inorder(root);
    cout << "\n";
    bst.Postorder(root);
    cout << "\n";
}

//检查一棵树是否为二叉搜索树
#include<iostream>
#include<random>    //用于生成随机的二叉树
#include<ctime>
#include<cstdlib>
#include<queue>
using namespace std;

struct BSTNode
{
    int value;
    BSTNode* right;
    BSTNode* left;

    BSTNode(int x) : value(x), left(NULL), right(NULL) {}
};

class BST
{
    private:
        //判断是否左子树的值都小于或等于x，都小于返回true，反之为false
        bool IsSubtreeLesser(BSTNode* root,int x)
        {
            if (root == NULL)
                return true;
            
            //找到左子树上的最大值与x相比
            BSTNode* current=root;
            while (current->right != NULL)
            {
                current=current->right;
            }
            
            if (current->value <= x)
                return true;
            else
                return false; 
            
        }  

        //判断是否右子树的值都大于x，都大于返回true，反之为false
        bool IsSubtreeGreater(BSTNode* root,int x)
        {
            if (root == NULL)   //树为空时也认为其为二叉搜索树
                return true;

            //找到右子树上的最小值与x相比
            BSTNode* current=root;
            while (current->left != NULL)
            {
                current=current->left;
            }
            
            if (current->value > x)
                return true;
            else
                return false; 
            
        } 
        
    public:
        bool IsBST(BSTNode* root)
        {
            if (root == NULL)   //空树也为二叉搜索树，同时也是递归退出的条件
                return true;
            
            //同时满足左子树的最大值小于root，右子树的最小值大于root，左子树和右子树均为二叉搜索树才能确定该树为二叉搜索树
            if (  IsSubtreeLesser(root->left,root->value)
                &&IsSubtreeGreater(root->right,root->value)
                &&IsBST(root->left)
                &&IsBST(root->right))       
                return true;
            
            else
                return false;
            
        }
};

class RandomBST
{
    public:
        PerfectBinaryTree() 
        {
            srand(time(0)); // 使用当前时间作为随机数种子
        }

        BSTNode* GenerateRandomPerfectBinaryTree(int height) 
        {
        if (height < 0) return NULL;

        // 生成根节点的值
        int value = rand() % 100; // 生成0到99之间的随机整数
        BSTNode* root = new BSTNode(value);

        // 如果树的高度大于0，递归生成左右子节点
        if (height > 0) {
            root->left = GenerateRandomPerfectBinaryTree(height - 1);
            root->right = GenerateRandomPerfectBinaryTree(height - 1);
        }

        return root;
        }

        //广度优先搜索函数
        void LevelOrder(BSTNode* root)
        {
            queue<BSTNode*> Q;  //定义一个队列，队列中存放BSTNode型的指针
            Q.push(root);
            BSTNode* current = NULL;

            if (root == NULL)
                cout << "The tree is Empty" <<endl;
            
            while (!Q.empty())  //队列非空时
            {
                current=Q.front();  //每次进入循环时重置current的值指向队列首
                cout << current->value << " ";
                Q.pop();            //打印完值之后需要把节点弹出

                if (current->left != NULL)  //加条件判断是为了不再向队列压入空指针并读值，从而造成异常
                {
                    Q.push(current->left);
                }
                if (current->right != NULL)
                {
                    Q.push(current->right);
                }
      
            }
        }
};


int main()
{

    BSTNode* root = NULL;
    BST bst;
    RandomBST treeproduce;

    root = treeproduce.GenerateRandomPerfectBinaryTree(2);
    treeproduce.LevelOrder(root);
    

    if (bst.IsBST(root))
        cout << "The tree is BST" << endl;
    else
        cout << "The tree is not BST" << endl;
    

    return 0;
}



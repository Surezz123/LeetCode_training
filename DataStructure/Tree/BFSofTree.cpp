//广度优先搜索树
//在对每一层进行搜索时，把该节点的所有子节点都存入队列中，然后按照顺序出队完成遍历
#include<iostream>
#include<queue>
using namespace std;

struct BSTNode
{
    int value;
    BSTNode* right;
    BSTNode* left;
};


class BST
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
    root=bst.Insert(root,10);
    root=bst.Insert(root,20);
    root=bst.Insert(root,8);
    root=bst.Insert(root,9);
    root=bst.Insert(root,25);
    root=bst.Insert(root,15);
    root=bst.Insert(root,7);

    bst.LevelOrder(root);

    return 0;
}



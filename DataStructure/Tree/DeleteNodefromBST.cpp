//从二叉搜索树中删除一个节点
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

        //广度优先搜索
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

        //中序遍历
        void Inorder(BSTNode* root)
        {
            if (root == NULL)
                return;
            Inorder(root->left);
            cout << root->value <<" ";
            Inorder(root->right);
        }
};

class DeleteBST
{
    private:
        //找最小值函数
        BSTNode* FoundMin(BSTNode* root)  
        {
            if (root == NULL)
                return NULL;

            if (root->left==NULL)   //递归退出条件，当root->left为空时表明该节点已经时二叉搜索树最左边的节点，直接返回即可
                return root;

            else
                return FoundMin(root->left);

        }

        //找最大值函数
        BSTNode* FoundMax(BSTNode* root)  
        {
            if (root == NULL)   //空树
                return NULL;

            if (root->right==NULL)  //递归退出条件，当root->right为空时表明该节点已经时二叉搜索树最右边的节点，直接返回即可
                return root;

            else
                return FoundMax(root->right);

        }
    
    public:
        //删除节点函数
        BSTNode* Delete(BSTNode* root,int x)
        {
            //空树,也是递归的退出条件
            if (root == NULL)
                return root;

            else if(x < root->value)
                return Delete(root->left,x);

            else if(x > root->value)
                return Delete(root->right,x);

            else    //找个这个元素，准备删除
            {
                //1.叶子节点(直接删除并释放)
                if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root =  NULL;
                    return root;
                }

                //2.仅有一个节点(让其父节点指向该节点的子节点)
                else if(root->left == NULL)
                {
                    BSTNode* temp = root;
                    root=root->right;
                    delete temp;
                    temp = NULL;
                    return root;
                }

                else if(root->right == NULL)
                {
                    BSTNode* temp = root;
                    root=root->left;
                    delete temp;
                    temp = NULL;
                    return root;
                }

                //3.有两个节点(要找到这个节点左子树的最大值或者右子树的最小值来替代这个节点)
                else
                {
                    BSTNode* temp = FoundMax(root->left); 
                    root->value = temp->value;
                    
                     //直接使用递归更新左子树(最大值对应的节点只能是叶子节点或者只有一个右节点的情况)
                    root->left=Delete(root->left,temp->value); 
                }
            }
        }
};


int main()
{
    BSTNode* root = NULL;
    BST bst;
    DeleteBST delbst;

    root=bst.Insert(root,10);
    root=bst.Insert(root,20);
    root=bst.Insert(root,8);
    root=bst.Insert(root,9);
    root=bst.Insert(root,25);
    root=bst.Insert(root,15);
    root=bst.Insert(root,7);

    delbst.Delete(root,8);
    bst.LevelOrder(root);
    cout<< "\n";
    bst.Inorder(root);
}



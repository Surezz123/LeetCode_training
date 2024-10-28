//���һ�����Ƿ�Ϊ����������
#include<iostream>
#include<random>    //������������Ķ�����
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
        //�ж��Ƿ���������ֵ��С�ڻ����x����С�ڷ���true����֮Ϊfalse
        bool IsSubtreeLesser(BSTNode* root,int x)
        {
            if (root == NULL)
                return true;
            
            //�ҵ��������ϵ����ֵ��x���
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

        //�ж��Ƿ���������ֵ������x�������ڷ���true����֮Ϊfalse
        bool IsSubtreeGreater(BSTNode* root,int x)
        {
            if (root == NULL)   //��Ϊ��ʱҲ��Ϊ��Ϊ����������
                return true;

            //�ҵ��������ϵ���Сֵ��x���
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
            if (root == NULL)   //����ҲΪ������������ͬʱҲ�ǵݹ��˳�������
                return true;
            
            //ͬʱ���������������ֵС��root������������Сֵ����root������������������Ϊ��������������ȷ������Ϊ����������
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
            srand(time(0)); // ʹ�õ�ǰʱ����Ϊ���������
        }

        BSTNode* GenerateRandomPerfectBinaryTree(int height) 
        {
        if (height < 0) return NULL;

        // ���ɸ��ڵ��ֵ
        int value = rand() % 100; // ����0��99֮����������
        BSTNode* root = new BSTNode(value);

        // ������ĸ߶ȴ���0���ݹ����������ӽڵ�
        if (height > 0) {
            root->left = GenerateRandomPerfectBinaryTree(height - 1);
            root->right = GenerateRandomPerfectBinaryTree(height - 1);
        }

        return root;
        }

        //���������������
        void LevelOrder(BSTNode* root)
        {
            queue<BSTNode*> Q;  //����һ�����У������д��BSTNode�͵�ָ��
            Q.push(root);
            BSTNode* current = NULL;

            if (root == NULL)
                cout << "The tree is Empty" <<endl;
            
            while (!Q.empty())  //���зǿ�ʱ
            {
                current=Q.front();  //ÿ�ν���ѭ��ʱ����current��ֵָ�������
                cout << current->value << " ";
                Q.pop();            //��ӡ��ֵ֮����Ҫ�ѽڵ㵯��

                if (current->left != NULL)  //�������ж���Ϊ�˲��������ѹ���ָ�벢��ֵ���Ӷ�����쳣
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



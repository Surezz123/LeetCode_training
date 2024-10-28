//�������������
//�ڶ�ÿһ���������ʱ���Ѹýڵ�������ӽڵ㶼��������У�Ȼ����˳�������ɱ���
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
        //�����½ڵ㺯��
        BSTNode* GetNewNode(int x)  //�����½ڵ�
        {
            BSTNode* newNode = new BSTNode(); //�κ��ڶ�̬�ڴ���߶��Ϸ�����ڴ涼ֻ��ͨ��ָ�����
            newNode->value=x;
            newNode->left=NULL;
            newNode->right=NULL;

            return newNode;
        }

    public:

        //����ڵ㺯��
        BSTNode* Insert(BSTNode* root,int x)   //ʹ�õݹ�ʱ��Ҫ������һ����ָ��
        { 
            if (root == NULL)   //Ϊ����ʱ��ͬʱ��Ϊ�˳��ݹ������
                root=GetNewNode(x);

            else if (x <= root->value)
                root->left = Insert(root->left,x);  //���ж��õݹ�������Ԫ��

            else
                root->right = Insert(root->right,x);
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



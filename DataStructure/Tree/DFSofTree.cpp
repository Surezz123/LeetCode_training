//�������������
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

        //��������ǰ�����(���ֱ�������ͨ���ݹ�ʵ�ֵ�)
        void Preorder(BSTNode* root)
        {
            if(root == NULL)
                return;
            cout << root->value << " ";
            Preorder(root->left);
            Preorder(root->right);
        }

        //���������������
        void Inorder(BSTNode* root)
        {
            if (root == NULL)
                return;
            Inorder(root->left);
            cout << root->value <<" ";
            Inorder(root->right);
        }

        //�������ĺ������  
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

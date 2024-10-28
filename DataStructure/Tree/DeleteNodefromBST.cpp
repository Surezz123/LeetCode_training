//�Ӷ�����������ɾ��һ���ڵ�
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

        //�����������
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

        //�������
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
        //����Сֵ����
        BSTNode* FoundMin(BSTNode* root)  
        {
            if (root == NULL)
                return NULL;

            if (root->left==NULL)   //�ݹ��˳���������root->leftΪ��ʱ�����ýڵ��Ѿ�ʱ��������������ߵĽڵ㣬ֱ�ӷ��ؼ���
                return root;

            else
                return FoundMin(root->left);

        }

        //�����ֵ����
        BSTNode* FoundMax(BSTNode* root)  
        {
            if (root == NULL)   //����
                return NULL;

            if (root->right==NULL)  //�ݹ��˳���������root->rightΪ��ʱ�����ýڵ��Ѿ�ʱ�������������ұߵĽڵ㣬ֱ�ӷ��ؼ���
                return root;

            else
                return FoundMax(root->right);

        }
    
    public:
        //ɾ���ڵ㺯��
        BSTNode* Delete(BSTNode* root,int x)
        {
            //����,Ҳ�ǵݹ���˳�����
            if (root == NULL)
                return root;

            else if(x < root->value)
                return Delete(root->left,x);

            else if(x > root->value)
                return Delete(root->right,x);

            else    //�Ҹ����Ԫ�أ�׼��ɾ��
            {
                //1.Ҷ�ӽڵ�(ֱ��ɾ�����ͷ�)
                if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root =  NULL;
                    return root;
                }

                //2.����һ���ڵ�(���丸�ڵ�ָ��ýڵ���ӽڵ�)
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

                //3.�������ڵ�(Ҫ�ҵ�����ڵ������������ֵ��������������Сֵ���������ڵ�)
                else
                {
                    BSTNode* temp = FoundMax(root->left); 
                    root->value = temp->value;
                    
                     //ֱ��ʹ�õݹ����������(���ֵ��Ӧ�Ľڵ�ֻ����Ҷ�ӽڵ����ֻ��һ���ҽڵ�����)
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



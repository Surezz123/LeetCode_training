//ɾ������ĵ�����N���ڵ�
//����ͷ�ڵ�ʵ������ָ��head��ָ��

#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

class LinkList
{
    public:
        void Insert(int x, Node*& head)	//��ͷ������ڵ�(���&����ֱ�ӶԾֲ�����head�����޸�)
        {
	        Node* temp = new Node();	
	        temp->value = x;
	        temp->next = head;
	        head = temp;
        }

        void Print(Node* head)	
        {
	        Node* temp = head;
	        while (temp != NULL)
	        {
		        cout << temp->value << " ";
		        temp = temp->next;
	        }
	        cout << endl;
        }

        ~LinkList()	//�������������ͷ��ڴ�
        {
            Node* current = head;
            Node* next;
            while (current != nullptr)
            {
                next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }

    private:
        Node* head = nullptr;  
};

class Solution
{
    public:
        Node* DeleteElement(int n,Node*& head)
        {
            Node* dummyhead = new Node(); //��������ͷ�ڵ�
            dummyhead->next=head;

            Node* fast = head;
            Node* slow = head;
            Node* temp = NULL;
            while (fast != NULL)
            {
                for (int i = 0; i < n+1; i++)   //����fast��n+1��
                {
                    fast=fast->next;
                }
                slow=slow->next;    //��ѭ����slow�Ѿ�ָ���˵�����n+1���ڵ�
                fast=fast->next;
            }
            slow->next=(slow->next)->next;
            
            return dummyhead->next; //�������ص���ͷָ�룬ͷָ��Ϊ����ͷ�ڵ��next
        }
};

int main()
{
    Node* head = NULL;
    LinkList linklist;
    Solution solution;

    linklist.Insert(2,head);
    linklist.Insert(4,head);
    linklist.Insert(6,head);
    linklist.Insert(8,head);
    linklist.Print(head);

    solution.DeleteElement(2,head);
    linklist.Print(head);
}
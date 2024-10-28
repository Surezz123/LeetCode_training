//�Ƴ�����Ԫ��
//����������ͷ�ڵ��������ͷ�ڵ���зֶδ���

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
        //˫ָ��͵�ָ�붼����
        Node* RemoveElement(int x,Node*& head)
        {
            Node* dummyhead = new Node();   //��������ͷ�ڵ�
            dummyhead->next=head;

            Node* pre = dummyhead;
            Node* cur = head;
            while (cur != NULL)
            {
                if (cur->value == x)
                {
                    pre->next=cur->next;
                    delete cur;
                    cur = pre->next;    //ɾ���˽ڵ�֮��cur������ǰ��
                }
                else
                {
                    cur=cur->next;
                    pre=pre->next;
                }
            }
            head = dummyhead->next;
            delete dummyhead;       //�ͷ�����ͷ�ڵ㣬��ֹ�ڴ�й©
            return head;
        }
};

int main()
{
    Node* head = NULL;
    LinkList linklist;
    linklist.Insert(6,head);
    linklist.Insert(5,head);
    linklist.Insert(4,head);
    linklist.Insert(3,head);
    linklist.Insert(6,head);
    linklist.Insert(2,head);
    linklist.Insert(1,head);
    linklist.Print(head);

    Solution Solution;
    Solution.RemoveElement(6,head);
    linklist.Print(head);
}
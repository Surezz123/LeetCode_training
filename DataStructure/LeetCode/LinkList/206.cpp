//��ת����(˫ָ�뷨)

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

        void ReverseLinkList(Node*& head)
        {
            Node* fast = head;
            Node* slow = NULL;
            Node* temp = NULL;
            while (fast != NULL)
            {
                temp = fast->next;
                fast->next = slow;
                slow = fast;
                fast = temp;

            }
            head = slow;
            delete temp;
        }
};

int main()
{
    Node* head = NULL;
    LinkList linklist;
    linklist.Insert(2,head);
    linklist.Insert(4,head);
    linklist.Insert(6,head);
    linklist.Insert(8,head);
    linklist.Print(head);

    linklist.ReverseLinkList(head);
    linklist.Print(head);
}
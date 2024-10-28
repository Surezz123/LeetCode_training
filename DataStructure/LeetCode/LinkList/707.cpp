//�������
#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

class LinkList
{
    private:
        int size=0;   //��¼������

        Node* GetNewNode(int x)
        {
            Node* node = new Node();
            node->next=NULL;
            node->value=x;
            return node;
        }

    public:
        void Print(Node* head)	//????
        {
	        Node* temp = head;
	        while (temp != NULL)
	        {
		        cout << temp->value << " ";
		        temp = temp->next;
	        }
	        cout << endl;
        }

        int GetIndexValue(int index,Node* head)
        {
            Node* cur = head;

            if (index > size)
            {
                return -1;
            }
            
            for (int i = 1; i < index; i++)
            {
                cur=cur->next;
            }
            return cur->value;
        }

        void AddatHead(int x,Node*& head)
        {
            Node* node = GetNewNode(x);
            Node* temp = head;
            head = node;
            head->next = temp;

            size++;
            //return head;
        }

        void AddatTail(int x,Node*& head)
        {
            Node* temp = head;
            while (temp->next != NULL)  //����ѭ��ʱtempָ�����һ���ڵ�
            {
                temp=temp->next;
            }
            
            Node* node = GetNewNode(x);
            temp->next = node;
            node->next = NULL;
            
            size++;
            //return head;
        }

        void AddAtIndex(int index,int value,Node*& head)
        {
            Node* cur = head;
            Node* node = GetNewNode(value);
            Node* temp = NULL;
            if (index < 0)
            {
                AddatHead(value,head);
            }
            else if (index > size)
            {
                AddatTail(value,head);
            }
            else
            {
                for (int i = 2; i < index; i++) //�ڵ�index���ڵ�ǰ����ڵ㣬��Ҫ����index-1���ڵ㴦
                {
                    cur = cur->next;
                }
                temp = cur->next;
                cur->next = node;
                node->next = temp;
            }
            size++;
        }

        void DeleteAtIndex(int index,Node*& head)
        {
            Node* dummyhead = new Node();   //��������ͷ�ڵ�
            dummyhead->next = head;
            Node* cur = dummyhead;

            for (int i = 1; i < index ; i++)
            {
                cur = cur->next;
            }
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;

            head = dummyhead->next;
            delete dummyhead;
            size--;
        }
};


int main()
{
    Node* head = NULL;
    LinkList linklist;
    linklist.AddatHead(1,head);
    linklist.AddatTail(3,head);
    linklist.AddAtIndex(1,2,head);
    linklist.Print(head);
    int indexvalue1 = linklist.GetIndexValue(2,head);
    cout << indexvalue1 << "\n";

    linklist.DeleteAtIndex(1,head);
    linklist.Print(head);
    int indexvalue2 = linklist.GetIndexValue(2,head);
    cout << indexvalue2 << "\n";

}
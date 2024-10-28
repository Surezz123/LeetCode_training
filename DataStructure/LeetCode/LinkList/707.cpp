//设计链表
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
        int size=0;   //记录链表长度

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
            while (temp->next != NULL)  //结束循环时temp指向最后一个节点
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
                for (int i = 2; i < index; i++) //在第index个节点前插入节点，就要到第index-1个节点处
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
            Node* dummyhead = new Node();   //创建虚拟头节点
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
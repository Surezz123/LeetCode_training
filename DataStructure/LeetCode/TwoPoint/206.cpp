//????
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
        void Insert(int x, Node*& head)	//?????????????????head??????(???&???head????)
        {
	        Node* temp = new Node();	//??new???????
	        temp->value = x;
	        temp->next = head;
	        head = temp;
        }

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

        ~LinkList()	//??????????????
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
        Node* head = nullptr;  // ?head????????
};

class Solution
{
    public:
        Node* ReverseLinkList(Node* head)   //????
        {
            Node* pre = NULL;   
            Node* cur = head;
            Node* temp = NULL;
            
            while (cur != NULL)
            {
                temp = cur->next;       //???????temp??????????
                cur->next = pre;

                pre = cur;               //?????????
                cur = temp;
            }
            return pre;
        }
};

int main()
{
    LinkList linklist;
    Node* head = nullptr;
    linklist.Insert(2, head);
    linklist.Insert(4, head);
    linklist.Insert(6, head);
    linklist.Insert(8, head);
    linklist.Print(head);

    Solution solution;
    head = solution.ReverseLinkList(head);

    linklist.Print(head);

    return 0;
}


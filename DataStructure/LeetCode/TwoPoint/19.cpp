//删除链表的倒数第N个节点
//虚拟头节点实际上是指向head的指针

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
        void Insert(int x, Node*& head)	//在头部插入节点(添加&可以直接对局部变量head进行修改)
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

        ~LinkList()	//构析函数用于释放内存
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
            Node* dummyhead = new Node(); //创建虚拟头节点
            dummyhead->next=head;

            Node* fast = head;
            Node* slow = head;
            Node* temp = NULL;
            while (fast != NULL)
            {
                for (int i = 0; i < n+1; i++)   //先让fast走n+1次
                {
                    fast=fast->next;
                }
                slow=slow->next;    //出循环后slow已经指向了倒数第n+1个节点
                fast=fast->next;
            }
            slow->next=(slow->next)->next;
            
            return dummyhead->next; //函数返回的是头指针，头指针为虚拟头节点的next
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
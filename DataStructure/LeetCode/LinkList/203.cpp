//移除链表元素
//可以用虚拟头节点来避免对头节点进行分段处理

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
        //双指针和单指针都能做
        Node* RemoveElement(int x,Node*& head)
        {
            Node* dummyhead = new Node();   //创建虚拟头节点
            dummyhead->next=head;

            Node* pre = dummyhead;
            Node* cur = head;
            while (cur != NULL)
            {
                if (cur->value == x)
                {
                    pre->next=cur->next;
                    delete cur;
                    cur = pre->next;    //删除了节点之后cur继续往前走
                }
                else
                {
                    cur=cur->next;
                    pre=pre->next;
                }
            }
            head = dummyhead->next;
            delete dummyhead;       //释放虚拟头节点，防止内存泄漏
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
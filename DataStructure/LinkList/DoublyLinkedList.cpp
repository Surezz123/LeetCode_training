//创建双向链表,并反向打印链表
#include <iostream>
using namespace std;

struct Node		//双向链表
{
	int value;
	Node *next;	
	Node *prev;
};

class LinkList
{
	private:
		Node* head;
		Node* GetNewNode(int x)
		{
			Node* temp1=new Node();
			temp1->value = x;
			temp1->next = NULL;
			temp1->prev = NULL;
			return temp1;
		}
	public:
		LinkList() : head(nullptr) {}

		void InsertAtHead(int x)
		{
			Node* temp = GetNewNode(x);	//用指针指向新创建的节点
			if (head == NULL)	//链表为空时
			{
				head = temp;
			}
			else
			{
				head->prev = temp;	//双向连接
				temp->next = head;
				head = temp;
			}
		}

		void Print()
		{
			struct Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->value << ' ';
				temp = temp->next;
			}
			cout << "\n";
		}

		void ReversePrint()
		{
			struct Node* temp = head;
			if(temp==NULL)  //链表为空时无法输出
			{
				return;
			}
			while(temp->next != NULL)
			{
				temp=temp->next;    //找到最后一个节点
			}
			while (temp != NULL)      //因为双向链表的头节点的pre也是NULL，所有可以这样判断
			{
				cout << temp->value << ' ';
				temp=temp->prev;
			}
			cout << "\n";
		}

};

int main()
{
	LinkList linklist;

	linklist.InsertAtHead(2);
	linklist.InsertAtHead(4);
	linklist.InsertAtHead(6);
	linklist.InsertAtHead(8);

	linklist.Print();
    linklist.ReversePrint();

    return 0;
}
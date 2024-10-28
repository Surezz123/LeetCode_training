//用循环迭代的方法来反转链表
#include <iostream>
using namespace std;

struct Node
{
	int value;
	struct Node* next;
};

class LinkList
{
	private:
		Node* head;
		Node* GetNewNode(int x)
		{
			Node* temp1 = new Node();
			temp1->value = x;
			temp1->next = NULL;
			return temp1;
		}	
		
	public:
		//构造函数
		LinkList() : head(nullptr) {}

		//析构函数，在对象生命周期结束时自动调用
		~LinkList()
		{
			Node* cur = head;
			while (cur != nullptr)
			{
				Node* next = cur->next;
				delete cur;
				cur = next;
			}
			
		}

		void InsertAtHead(int x)
		{
			Node* temp = GetNewNode(x);	//用指针指向新创建的节点
			if (head == NULL)	//链表为空时
			{
				head = temp;
			}
			else
			{
				temp->next = head;	//这里是从head处插入元素
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
			cout << endl;
		}

		void Reverse()
		{
			Node *current, *prev, *next;
			current = head;				//这样初始化可以使头节点也包含在内
			prev = NULL;
			while (current != NULL)
			{
				next = current->next;	//首先保存当前指针指向的下一个节点的地址
				current->next = prev;	//再将当前节点指向前一个节点
				prev = current;			
				current = next;			//双指针向前移动，双指针主要指的是cur和pre
			}
			head = prev;	//跳出循环后此时current指向NULL，prev指向最后一个节点，此时需要让head指向最后一个节点
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

	linklist.Reverse();
	linklist.Print();
}

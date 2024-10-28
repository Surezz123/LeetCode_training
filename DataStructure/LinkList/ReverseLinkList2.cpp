//用递归的方法来反转链表
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

		Node* returnhead()
		{
			Node* p = head;
			return p;
		}

		void Reverse(Node* p) 
		{
			if (p->next == nullptr) 
			{
				head = p;  // 当前节点为新的头节点
				return;
			}

    		Reverse(p->next);  // 递归反转剩余部分

    		// 保存当前节点的下一个节点
    		Node* q = p->next;

    		// 将当前节点的下一个节点的 next 指向当前节点
    		q->next = p;

    		// 将当前节点的 next 指向 nullptr，断开与原链表的连接
    		p->next = nullptr;
		}

};



int main()
{
	LinkList linklist;
	Node* p = linklist.returnhead();
	linklist.InsertAtHead(2);
	linklist.InsertAtHead(4);
	linklist.InsertAtHead(6);
	linklist.InsertAtHead(8);
	linklist.Print();

	linklist.Reverse(p);
	linklist.Print();
}
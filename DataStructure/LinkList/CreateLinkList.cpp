#include <iostream>
using namespace std;

// 链表节点的结构体定义
struct Node {
	int value;
	Node* next;
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
};

 
int main() {
	LinkList linklist;
	linklist.InsertAtHead(2);
	linklist.InsertAtHead(4);
	linklist.InsertAtHead(6);

	linklist.Print();
	return 0;
}
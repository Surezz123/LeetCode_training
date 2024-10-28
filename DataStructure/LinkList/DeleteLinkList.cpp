#include <iostream>
using namespace std;

struct Node
{
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

		void Delete(int n)
		{
			Node* temp1 = head;
			if (n == 1)
			{
				head = temp1->next;	//head直接指向第二个节点
				delete temp1;
			} 
			else
			{
				Node* temp2;
				for (int i=1; i<n-1; i++)	//删除第n个节点先找到第n-1个节点
				{
					temp1 = temp1->next;
				}
				temp2 = temp1->next;	//temp2指向第n个节点
				temp1->next = temp2->next;	//temp1指向第n+1个节点
				delete temp2;
			}
		}
};



int main()
{
	int n;
	cin >> n;
	LinkList linklist;
	linklist.InsertAtHead(2);
	linklist.InsertAtHead(3);
	linklist.InsertAtHead(4);
	linklist.InsertAtHead(5);	
	linklist.Print();

	linklist.Delete(n);
	linklist.Print();
}
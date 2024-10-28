#include <iostream>
using namespace std;

// ����ڵ�Ľṹ�嶨��
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
		//���캯��
		LinkList() : head(nullptr) {}

		//�����������ڶ����������ڽ���ʱ�Զ�����
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
			Node* temp = GetNewNode(x);	//��ָ��ָ���´����Ľڵ�
			if (head == NULL)	//����Ϊ��ʱ
			{
				head = temp;
			}
			else
			{
				temp->next = head;	//�����Ǵ�head������Ԫ��
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
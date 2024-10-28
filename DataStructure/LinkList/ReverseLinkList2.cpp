//�õݹ�ķ�������ת����
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

		Node* returnhead()
		{
			Node* p = head;
			return p;
		}

		void Reverse(Node* p) 
		{
			if (p->next == nullptr) 
			{
				head = p;  // ��ǰ�ڵ�Ϊ�µ�ͷ�ڵ�
				return;
			}

    		Reverse(p->next);  // �ݹ鷴תʣ�ಿ��

    		// ���浱ǰ�ڵ����һ���ڵ�
    		Node* q = p->next;

    		// ����ǰ�ڵ����һ���ڵ�� next ָ��ǰ�ڵ�
    		q->next = p;

    		// ����ǰ�ڵ�� next ָ�� nullptr���Ͽ���ԭ���������
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
//��ѭ�������ķ�������ת����
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

		void Reverse()
		{
			Node *current, *prev, *next;
			current = head;				//������ʼ������ʹͷ�ڵ�Ҳ��������
			prev = NULL;
			while (current != NULL)
			{
				next = current->next;	//���ȱ��浱ǰָ��ָ�����һ���ڵ�ĵ�ַ
				current->next = prev;	//�ٽ���ǰ�ڵ�ָ��ǰһ���ڵ�
				prev = current;			
				current = next;			//˫ָ����ǰ�ƶ���˫ָ����Ҫָ����cur��pre
			}
			head = prev;	//����ѭ�����ʱcurrentָ��NULL��prevָ�����һ���ڵ㣬��ʱ��Ҫ��headָ�����һ���ڵ�
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

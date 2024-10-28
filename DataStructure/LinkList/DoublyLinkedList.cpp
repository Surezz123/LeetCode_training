//����˫������,�������ӡ����
#include <iostream>
using namespace std;

struct Node		//˫������
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
			Node* temp = GetNewNode(x);	//��ָ��ָ���´����Ľڵ�
			if (head == NULL)	//����Ϊ��ʱ
			{
				head = temp;
			}
			else
			{
				head->prev = temp;	//˫������
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
			if(temp==NULL)  //����Ϊ��ʱ�޷����
			{
				return;
			}
			while(temp->next != NULL)
			{
				temp=temp->next;    //�ҵ����һ���ڵ�
			}
			while (temp != NULL)      //��Ϊ˫�������ͷ�ڵ��preҲ��NULL�����п��������ж�
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
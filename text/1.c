#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct Node {
    int data;
    struct Node* next;
};

// �����������½ڵ�
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��������ӡ����
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ������ɾ�������е��ظ��ڵ�
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;
    
    if (current == NULL) {
        return;
    }
    // ��������
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

int main() {
    // �������� 1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);
    
    printList(head);
    // ɾ���ظ��ڵ�
    removeDuplicates(head);
    printList(head);
    
    return 0;
}


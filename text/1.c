#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node {
    int data;
    struct Node* next;
};

// 函数：创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 函数：打印链表
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 函数：删除链表中的重复节点
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;
    
    if (current == NULL) {
        return;
    }
    // 遍历链表
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
    // 创建链表 1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);
    
    printList(head);
    // 删除重复节点
    removeDuplicates(head);
    printList(head);
    
    return 0;
}


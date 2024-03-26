#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* rotateList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return *head;
    }

    struct Node* newHead = (*head)->next;
    struct Node* temp = newHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head;

    (*head)->next = NULL;

    return newHead;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    struct Node* li = NULL;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        addNode(&li, temp);
    }
    for (int i = 0; i < k; i++) {
        li=rotateList(&li);
    }
    printList(li);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

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
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            if (current == NULL) {
                mergedList = current = list1;
            } else {
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (current == NULL) {
                mergedList = current = list2;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        }
    }
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* J = NULL;
    struct Node* A = NULL;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        addNode(&J, num);
    }

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        addNode(&A, num);
    }

    struct Node* answer = mergeLists(J, A);
    printList(answer);

    // Free the allocated memory for the linked list nodes
    struct Node* temp;
    while (answer != NULL) {
        temp = answer;
        answer = answer->next;
        free(temp);
    }

    return 0;
}

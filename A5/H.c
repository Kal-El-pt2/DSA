#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertLast(struct Node** head, int data) {
    struct Node* newNode = create(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertFirst(struct Node** head, int data) {
    struct Node* newNode = create(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void deleteFront(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

void deleteLast(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(temp);
    }
}

void printForward(struct Node* head) {
    if (head == NULL) {
        printf("-1\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printLast(struct Node* head) {
    if (head == NULL) {
        printf("-1\n");
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    struct Node* li = NULL;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        insertLast(&li, temp);
    }
    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int b;
            scanf("%d", &b);
            insertFirst(&li, b);
        } else if (a == 2) {
            int b;
            scanf("%d", &b);
            insertLast(&li, b);
        } else if (a == 3) {
            deleteFront(&li);
        } else if (a == 4) {
            deleteLast(&li);
        } else if (a == 5) {
            printForward(li);
        } else {
            printLast(li);
        }
    }

    return 0;
}

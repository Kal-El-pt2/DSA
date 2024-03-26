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

int solve(struct Node** head, int n, int k) {
    struct Node* temp = *head;

    // Find the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the last node to the head to form a circular linked list
    temp->next = *head;

    struct Node* prev = NULL;
    temp = *head;

    // Josephus problem simulation
    while (temp->next != temp) {
        for (int i = 1; i < k; i++) {
            prev = temp;
            temp = temp->next;
        }

        // Remove the k-th person
        prev->next = temp->next;
        struct Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    // Return the remaining person
    int result = temp->data;

    // Disconnect the last node
    prev->next = NULL;

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    struct Node* li = NULL;
    
    // Populate the linked list
    for (int i = 1; i <= n; i++) {
        addNode(&li, i);
    }

    // Solve the Josephus problem
    int result = solve(&li, n, k);

    // Print the result
    printf("%d\n", result);

    return 0;
}

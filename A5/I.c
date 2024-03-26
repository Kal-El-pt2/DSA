#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNode(struct Node** head, char data) {
    struct Node* newNode = create(data);
    if ((*head) == NULL) {
        (*head) = newNode;
    } else {
        struct Node* temp = (*head);
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void solve(struct Node* head) {
    int check = 1;
    struct Node* t1 = head;
    struct Node* t2 = head;
    while (t2->next != NULL) {
        t2 = t2->next;
    }
    while (t1->next != NULL) {
        if (t1->data != t2->data) {
            check = 0;
            break;
        } else {
            t1 = t1->next;
            t2 = t2->prev;
        }
    }
    if (check == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Consume the newline character after reading n
    getchar();

    struct Node* li = NULL;
    for (int i = 0; i < n; i++) {
        char temp;
        scanf(" %c", &temp);  // Added space before %c to consume whitespace characters
        addNode(&li, temp);
    }

    solve(li);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

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

void addNode(struct Node** head, int data) {
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

void printNowSong(struct Node* now, int* results, int* count) {
    if (now == NULL) {
        results[(*count)++] = 0;
    } else {
        results[(*count)++] = now->data;
    }
}

void addtoNextSong(struct Node* now, struct Node* toadd) {
    if (now != NULL) {
        toadd->prev = now;
        toadd->next = now->next;
        if (now->next != NULL) {
            now->next->prev = toadd;
        }
        now->next = toadd;
    }
}

int main() {

    int n, q;
    scanf("%d %d", &n, &q);
    struct Node* li = NULL;
    int* results = (int*)malloc(q * sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        addNode(&li, temp);
    }

    struct Node* now = li;

    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            printNowSong(now, results, &count);
        } else if (a == 2) {
            int b;
            scanf("%d", &b);
            struct Node* toadd = create(b);
            addtoNextSong(now, toadd);
        } else if (a == 3) {
            int b;
            scanf("%d", &b);
            addNode(&li, b);
        } else if (a == 4) {
            if (now != NULL && now->next != NULL) {
                now = now->next;
            }
        } else if (a == 5) {
            if (now != NULL && now->prev != NULL) {
                now = now->prev;
            }
        } else {
            if (now != NULL && now->next != NULL) {
                now = now->next;
                free(now->prev);
                now->prev = NULL;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", results[i]);
    }

    free(results);

    return 0;
}

#include<stdlib.h>
#include<stdio.h>

struct Node{
    float data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(float val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void addNode(struct Node** head, float data) {
    struct Node* newNode = createNode(data);
    if ((*head) == NULL) {
        (*head) = newNode;
    } else {
        struct Node* temp = (*head);
        struct Node* prev = NULL; 

        while ((temp) != NULL && temp->data <= data) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            newNode->next = (*head);
            if ((*head) != NULL) {
                (*head)->prev = newNode;
            }
            (*head) = newNode;
        } else {
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = temp;

            if (temp != NULL) {
                temp->prev = newNode;
            }
        }
    }
}
void CountNodes(struct Node* head){
    int count = 0;
    struct Node* temp = head;  // Use a temporary pointer to traverse the list

    while (temp != NULL) {
        count++;
        temp = temp->next;  // Move to the next node
    }

        printf("%d ",count);
    
}


void printList(struct Node* head){
    struct Node* temp=head;
    while(temp != NULL){
        printf("%f ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    float arr[n];
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    struct Node* barr[n];
    for (int i = 0; i < n; i++){
        barr[i] = NULL;  
    }
    for(int i=0;i<n;i++){
        addNode(&barr[(int)(arr[i]*n)],arr[i]);
    }
    for(int i=0;i<n;i++){
        printList(barr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        CountNodes(barr[i]);
    }

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct map {
    int val;
    int freq;
};
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void addNode(struct Node** head,int data){
    struct Node* newNode=createNode(data);
    if((*head)=NULL){
        (*head)=newNode;
    }else{
        struct Node* temp=(*head);
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void printList(struct Node* head){
    if(head ==NULL)return;
    while(head->next!= NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    int max = 0;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        max = max > a[i] ? max : a[i];
    }
    struct Node* arr[max];
    

    return 0;
}

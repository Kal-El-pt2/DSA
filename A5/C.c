#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node * createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void addNode(struct Node** head,int data){
    struct Node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
    }else{
        struct Node* temp =*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct Node* reverseList(struct Node* head){
    struct Node* prev=NULL;
    struct Node* current=head;
    struct Node* next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;          
}

int main(){
    int n;
    scanf("%d",&n);
    struct Node* li=NULL;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        addNode(&li,temp);
    }
    struct Node* answer=reverseList(li);
    printList(answer);
    return 0;
}
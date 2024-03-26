#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}
void addNode(struct Node** head,int data){
    struct Node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
    }else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void solve(struct Node* head){
    if(head->next==NULL){
        printf("%d",head->data);
        return;
    }else{
        printf("%d ",head->data);
        int storage=head->data;
        while(head->next!=NULL){
            if(head->next->data==storage){
                head=head->next;
            }else{
                head=head->next;
                storage=head->data;
                printf("%d ",head->data);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    struct Node* li=NULL;
    while(n--){
        int temp;
        scanf("%d",&temp);
        addNode(&li,temp);
    }
    solve(li);
    return 0;
}
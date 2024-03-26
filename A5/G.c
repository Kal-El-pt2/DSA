#include<stdio.h>
#include<stdlib.h>

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
    struct Node* new=createNode(data);
    if(*head==NULL){
        *head=new;
    }else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}
void solve(struct Node* head,int n,int a,int b){
    struct Node* d=head;
    a--;
    while(a--){
        if(d->data==n){
            d=head;
            continue;
        }
        d=d->next;
    }
    int stepstoMove=0;
    while(d->data!=b){
        if(d->data==n){
            d=head;
            stepstoMove++;
            continue;
        }
        d=d->next;
        stepstoMove++;
    }
    int answer=(b+stepstoMove)%n;
    if(answer==0){
        answer=n;
    }
    printf("%d",answer);

}



int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    struct Node* headMarker=createNode(1);
    for(int i=2;i<=n;i++){
        addNode(&headMarker,i);
    }
    solve(headMarker,n,a,b);
    return 0;
}
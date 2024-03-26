#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void justGreater(int *a,int n){
    for(int i=0;i<n-1;i++){
        int j=i+1;
        bool printed=false;
        for(j=i+1;j<n;j++){
            if(a[j]>a[i]){
                printf("%d ",j-i);
                printed=true;
                break;
            } 
        }
        if(printed==false)printf("0 ");
    }
    printf("0");
}
void justLesser(int * a,int n){
    for(int i=0;i<n-1;i++){
        int j=i+1;
        bool printed=false;
        for(j=i+1;j<n;j++){
            if(a[j]<a[i]){
                printf("%d ",j-i);
                printed=true;
                break;
            } 
        }
        if(printed==false)printf("0 ");
    }
    printf("0");
}


int main(){ 
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    justGreater(a,n);
    printf("\n");
    justLesser(a,n);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *xp,int * yp){
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}
void AASort(int * arr,int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false) break;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    AASort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
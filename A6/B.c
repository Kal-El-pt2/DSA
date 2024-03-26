#include<stdio.h>
#include<stdlib.h>

void quickSort(int * a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quickSort(a,n);

    return 0;
}
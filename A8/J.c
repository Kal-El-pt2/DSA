#include<stdio.h>
#include<stdlib.h>

int partition(int *a ,int low,int high){
    int pivot = a[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++){
        if(a[j]>pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}

int quickSelect(int *a,int low,int high,int k){
    if(low<=high){
        int pivot=partition(a,low,high);

        if(pivot==k)return a[pivot];
        else if(pivot>k){
            return quickSelect(a,low,pivot-1,k);
        }
        else return quickSelect(a,pivot+1,high,k);
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int result=quickSelect(a,0,n-1,k-1);
    printf("%d",result);
    return 0;
}
#include<stdio.h>
#include<math.h>

void swap(int * a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}


void merge(int* a,int left,int mid,int right){
    int i,j,k;
    int n1=mid-left-1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[i];
    }
    for(int i=0;i<n2;i++){
        R[i]=a[i];
    }
    i=0;
    j=0;k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
        }
    }
    while(i<n1){
        a[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int* a,int left,int right){
    if(left<right){
        int mid=left + (right-left)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}


int partition(int * a,int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}
void sort(int a[],int low,int high,int curr,int sortDepth){
    if(low<high && curr<2*sortDepth){
            int pi=partition(a,low,high);
            sort(a,low,pi-1,++curr,sortDepth);
            sort(a,pi+1,high,++curr,sortDepth);   
    }
    else{
        mergeSort(a,low,high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int sortDepth=log(n)/log(2);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int curr=0;
    sort(a,0,n-1,curr,sortDepth);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
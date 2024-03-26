#include<stdio.h>
#include<stdlib.h>

void CountingSort(int n, int* arr,int k){
    int frequency[n];
    for(int i=0;i<n;i++)frequency[i]=0;

    for(int i=0;i<n;i++){
        frequency[arr[i]-1]++;
    }
    int a=0;
    int b=n-1;
    while(a<b){
        if(frequency[a]==0 && frequency[b]==0 && a+b+2==k){
            printf("yes");
            return;
        }
        else if(frequency[a]==0 && frequency[b]==0 && a+b+2>k){
            b--;
            continue;
        }
        else if(frequency[a]==0 && frequency[b]==0 && a+b+2<k){
            a++;
            continue;
        }else if(frequency[a]!=0 && frequency[b]==0){
            a++;
            continue;
        }
        else if(frequency[a]==0 && frequency[b]!=0){
            b--;
            continue;
        }
        else if(frequency[a]!=0 && frequency[b]!=0){
            a++;
            b--;
            continue;
        }
    }
    printf("no");
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
    } 
    CountingSort(n,arr,k);

    return 0;
}

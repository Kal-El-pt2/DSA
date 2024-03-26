#include<stdio.h>
#include<stdlib.h>


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int c[n];
    for(int i=0;i<n;i++){
        c[i]=a[i]+b[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(c[j]<c[j+1]){
                int temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
    int sum=0;
    for(int i=0;i<k;i++){
        if(c[i]<=0)break;

        sum+=c[i];
    }
    printf("%d",sum);

    return 0;
}
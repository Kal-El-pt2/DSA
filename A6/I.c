#include<stdio.h>
#include<stdlib.h>

int main(){
    int q;
    scanf("%d",&q);
    int counter=0;
    int filled=counter;
    int matrix[q];
    int array[q-1];
    for(int i=0;i<q-1;i++){
        array[i]=-1;
    }
    for(int i=0;i<q;i++){
        scanf("%d",&matrix[i]);
        
    }
    
    return 0;
}
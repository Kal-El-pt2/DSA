#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int start;
    int end;
}TimeSlot;

int compareTimeSlots(const void *a,const void *b){
    return ((TimeSlot *)a)->start - ((TimeSlot *)b)->start;
}

void mergeSlots(TimeSlot *slots,int n){
    if(n<=1)return;

    TimeSlot* result=(TimeSlot*)malloc(n*sizeof(TimeSlot));
    int resultIndex=0;
    qsort(slots,n,sizeof(TimeSlot),compareTimeSlots);
    TimeSlot currentSlot=slots[0];

    for(int i=1;i<n;++i){
        if(currentSlot.end >= slots[i].start){
            currentSlot.end=(currentSlot.end > slots[i].end)?currentSlot.end : slots[i].end;
        }else{
            result[resultIndex++]=currentSlot;
            currentSlot=slots[i];
        }
    }
    result[resultIndex++]=currentSlot;
    printf("%d\n",resultIndex);
    for(int i=0;i<resultIndex;i++){
        printf("%d %d\n",result[i].start,result[i].end);
    }
    free(result);
}

int main(){
    int n;
    scanf("%d",&n);
     TimeSlot *slots = (TimeSlot *)malloc(n * sizeof(TimeSlot));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &slots[i].start, &slots[i].end);
    }

    mergeSlots(slots, n);
    free(slots);

    return 0;
}
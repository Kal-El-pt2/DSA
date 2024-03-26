#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int value;
    int arrIndex;
    int elementIndex;
}heapNode;

typedef struct {
    heapNode *heapArr;
    int size;
    int capacity; 
}minHeap;

minHeap* createMinHeap(int capacity){
    minHeap *minheap= (minHeap *)malloc(sizeof(minHeap));
    minheap->heapArr=(heapNode *)malloc(capacity*sizeof(heapNode));
    minheap->size=0;
    minheap->capacity=capacity;
    return minheap;
}
void swap(heapNode *a, heapNode *b){
    heapNode temp=*a;
    *a=*b;
    *b=temp;
}
void minHeapify(minHeap* minHeap,int idx){
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(right<minHeap->size && minHeap->heapArr[left].value<minHeap->heapArr[smallest].value)smallest=left;
    if(right<minHeap->size && minHeap->heapArr[right].value<minHeap->heapArr[smallest].value)smallest=right;

    if(smallest != idx){
        swap(&minHeap->heapArr[idx],&minHeap->heapArr[smallest]);
        minHeapify(minHeap,smallest);
    }
}
void insertMinHeap(minHeap* minHeap,int value,int arrayIndex,int elementIndex){
    if(minHeap->size == minHeap->capacity){
        if(value>minHeap->heapArr[0].value)return;

        minHeap->heapArr[0].value=value;
        minHeap->heapArr[0].arrIndex=arrayIndex;
        minHeap->heapArr[0].elementIndex=elementIndex;
        minHeapify(minHeap,0);
    }else{
        minHeap->heapArr[minHeap->size].value=value;
        minHeap->heapArr[minHeap->size].arrIndex=arrayIndex;
        minHeap->heapArr[minHeap->size].elementIndex=elementIndex;
        minHeap->size++;
        int i=minHeap->size-1;
        while(i>0 && minHeap->heapArr[(i-1)/2].value>minHeap->heapArr[i].value){
            swap(&minHeap->heapArr[i],&minHeap->heapArr[(i-1)/2]);
            i=(i-1)/2;
        }
    }
}
int *mergeKSortedArrays(int k,int **arrays,int *sizes,int *resultSize){
    minHeap *minHeap=createMinHeap(k);
    for(int i=0;i<k;++i){
        if(sizes[i]>0){
            insertMinHeap(minHeap,arrays[i][0],i,0);
        }
    }
    int *result=(int *)malloc((k*sizes[0])*sizeof(int));
    *resultSize=0;

    while(minHeap->size >0){
        heapNode minNode=minHeap->heapArr[0];
        result[(*resultSize)++]=minNode.value;

        if(minNode.elementIndex+1 < sizes[minNode.arrIndex]){
            insertMinHeap(minHeap,arrays[minNode.arrIndex][minNode.elementIndex+1],minNode.arrIndex,minNode.elementIndex+1);
        }
        if(minHeap->size>1){
            minHeap->heapArr[0] = minHeap->heapArr[minHeap->size -1];
            minHeap->size--;
            minHeapify(minHeap,0);
        }else{
            minHeap->size=0;
        }
    }
    return result;
}


int main(){
    int k;
    scanf("%d",&k);
     int **arrays = (int **)malloc(k * sizeof(int *));
    int *sizes = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &sizes[i]);
        arrays[i] = (int *)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; ++j)
        {
            scanf("%d", &arrays[i][j]);
        }
    }

    // Output
    int resultSize;
    int *result = mergeKSortedArrays(k, arrays, sizes, &resultSize);

    // Print the merged and sorted array
    for (int i = 0; i < resultSize; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < k; ++i)
    {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);
    return 0;
}

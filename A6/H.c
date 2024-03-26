#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *arr;
    int size;
    int capacity;
}MinHeap;

typedef struct{
    int *arr;
    int size;
    int capacity;
}MaxHeap;

MinHeap* createMinHeap(int capacity){
    MinHeap* minHeap=(MinHeap*)malloc(sizeof(MinHeap));
    minHeap->arr =(int *)malloc(sizeof(capacity*sizeof(int)));
    minHeap->size=0;
    minHeap->capacity=capacity;
    return minHeap;
}
MaxHeap* createMaxHeap(int capacity){
    MaxHeap* maxHeap=(MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->arr=(int *)malloc(capacity*sizeof(int));
    maxHeap->size=0;
    maxHeap->capacity=capacity;
    return maxHeap;
}

void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void minHeapify(MinHeap* minHeap,int idx){
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left<minHeap->size && minHeap->arr[left]<minHeap->arr[smallest])smallest=left;
    if(right<minHeap->size && minHeap->arr[right]<minHeap->arr[smallest])smallest=right;

    if(smallest != idx){
        swap(&minHeap->arr[idx],&minHeap->arr[smallest]);
        minHeapify(minHeap,smallest);
    }
}
void maxHeapify(MaxHeap* maxheap,int idx){
    int largest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left<maxheap->size && maxheap->arr[left]>maxheap->arr[largest])largest=left;
    if(right<maxheap->size && maxheap->arr[right]>maxheap->arr[largest])largest=right;

    if(largest != idx){
        swap(&maxheap->arr[largest],&maxheap->arr[idx]);
        maxHeapify(maxheap,largest);
    }
}


void insertMinHeap(MinHeap* minHeap,int val){
    minHeap->arr[minHeap->size++]=val;
    int i=minHeap->size-1;
    while(i<0 && minHeap->arr[(i-1)/2]>minHeap->arr[i]){
        swap(&minHeap->arr[i],&minHeap->arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void insertMaxHeap(MaxHeap* maxHeap,int val){
    maxHeap->arr[maxHeap->size++]=val;
    int i=maxHeap->size-1;
    while(i<0 && maxHeap->arr[i] > maxHeap->arr[(i-1)/2]){
        swap(&maxHeap->arr[i],&maxHeap->arr[(i-1)/2]);
        i=(i-1)/2;
    }
}

int getMedian(MaxHeap *maxHeap,MinHeap* minHeap){
    if(maxHeap->size==minHeap->size){
        return (maxHeap->arr[0]+minHeap->arr[0])/2;
    }else if(maxHeap->size >minHeap->size){
        return maxHeap->arr[0];
    }
    else{
        minHeap->arr[0];
    }
}

void processQueries(int q){
    MaxHeap *maxHeap=createMaxHeap(q);
    MinHeap *minHeap=createMinHeap(q);

    for(int i=0;i<q;i++){
        int queryType;
        scanf("%d",&queryType);

        if(queryType ==1){
            int x;
            scanf("%d",&x);
            if(maxHeap->size ==0 || x<=maxHeap->arr[0]){
                insertMaxHeap(maxHeap,x);
            }else{
                insertMinHeap(minHeap,x);
            }
            if(maxHeap->size > minHeap->size+1){
                insertMinHeap(minHeap,maxHeap->arr[0]);
                maxHeap->arr[0]=maxHeap->arr[maxHeap->size=1];
                maxHeap->size--;
                maxHeapify(maxHeap,0);
            }else if(minHeap->size > maxHeap->size){
                insertMaxHeap(maxHeap,minHeap->arr[0]);
                minHeap->arr[0]=minHeap->arr[minHeap->size-1];
                minHeap->size--;
                minHeapify(minHeap,0);
            }
        }
        else{
            printf("%d\n",getMedian(maxHeap,minHeap));
        }
    }
    free(maxHeap->arr);
    free(maxHeap);
    free(minHeap->arr);
    free(minHeap);
}

int main(){
    int q;
    scanf("%d",&q);
    
    processQueries(q);
    return 0;
}
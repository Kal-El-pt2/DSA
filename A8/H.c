#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000000

typedef struct{
    int heap[MAX_SIZE];
    int size;
}MinHeap;

MinHeap* createMinHeap(){
    MinHeap* minheap=(MinHeap*)malloc(sizeof(MinHeap));
    minheap->size=0;
    return minheap;
}
void minHeapify(int * arr,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]<arr[smallest])smallest=left;
    if(right<n && arr[right]<arr[smallest])smallest=right;

    if(smallest !=i){
        int temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
        minHeapify(arr,n,smallest);
    }
}
int extractMin(MinHeap* minheap){
    if(minheap->size==0){
        return -1;
    }
    int min=minheap->heap[0];
    minheap->heap[0]=minheap->heap[minheap->size -1];
    minheap->size--;
    minHeapify(minheap->heap,minheap->size,0);
    return min;
}
void insert(MinHeap* minHeap, int value) {
    if (minHeap->size == MAX_SIZE) {
        return; // Heap is full
    }

    minHeap->heap[minHeap->size] = value;
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i != 0 && minHeap->heap[(i - 1) / 2] > minHeap->heap[i]) {
        int temp = minHeap->heap[(i - 1) / 2];
        minHeap->heap[(i - 1) / 2] = minHeap->heap[i];
        minHeap->heap[i] = temp;
        i = (i - 1) / 2;
    }
}

typedef struct{
    int queue[MAX_SIZE];
    int size;
    int sum;
}AvgQueue;

AvgQueue* createAvgQueue() {
    AvgQueue* avgQueue = (AvgQueue*)malloc(sizeof(AvgQueue));
    avgQueue->size = 0;
    avgQueue->sum = 0;
    return avgQueue;
}

void enqueue(AvgQueue* avgQueue, int value) {
    if (avgQueue->size == MAX_SIZE) {
        return; // Queue is full
    }

    avgQueue->queue[avgQueue->size] = value;
    avgQueue->size++;
    avgQueue->sum += value;
}
void dequeue(AvgQueue* avgQueue) {
    if (avgQueue->size == 0) {
        return; // Queue is empty
    }

    avgQueue->sum -= avgQueue->queue[0];
    for (int i = 0; i < avgQueue->size - 1; i++) {
        avgQueue->queue[i] = avgQueue->queue[i + 1];
    }
    avgQueue->size--;
}

int getAverage(AvgQueue* avgQueue) {
    if (avgQueue->size == 0) {
        return 0; // Queue is empty, return 0 as average
    }
    return avgQueue->sum / avgQueue->size;
}


int main(){
    int q;
    scanf("%d", &q);

    MinHeap* minHeap = createMinHeap();
    AvgQueue* avgQueue = createAvgQueue();

    for (int i = 0; i < q; i++) {
        int query;
        scanf("%d", &query);

        if (query == 1) {
            int x;
            scanf("%d", &x);
            insert(minHeap, x);
            enqueue(avgQueue, x);
        } else if (query == 2) {
            extractMin(minHeap);
            dequeue(avgQueue);
        } else if (query == 3) {
            int min = minHeap->size > 0 ? minHeap->heap[0] : -1;
            int avg = getAverage(avgQueue);
            printf("%d %d\n", min, avg);
        }
    }

    free(minHeap);
    free(avgQueue);

    return 0;
}
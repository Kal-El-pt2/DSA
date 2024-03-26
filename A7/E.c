#include<stdio.h>
#include<stdlib.h>

struct pair{
    int first;
    int second;
};

void countingSort(struct pair* arr, int n, int k) {

    int count[k + 1] ;
    for(int i=0;i<=k;i++){
        count[i]=0;
    }
    struct pair output[n];

    for (int i = 0; i < n; i++) {
        count[arr[i].first]++;
    }


    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i].first]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    for(int i=0;i<n-1;i++){
        if(arr[i].first==arr[i+1].first && arr[i].second>arr[i+1].second){
            int temp=arr[i].second;
            arr[i].second=arr[i+1].second;
            arr[i+1].second=temp;
        }
    }
}

int main(){
   int n;
    scanf("%d", &n);

    struct pair arr[n];
    int maxFirstElement = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].first);
        if (arr[i].first > maxFirstElement) {
            maxFirstElement = arr[i].first;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].second);
    }

  countingSort(arr, n, maxFirstElement);


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].first);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].second);
    }

    return 0;
}

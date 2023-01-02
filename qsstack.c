#include <stdio.h>
#include<stdlib.h>

struct Task {int low, high;};

struct stack {
    struct Task t;
    struct stack* down;
};

struct Task Pop(struct stack* s){
    struct Task ans=s->t;
    return ans;
}

void swap(int* arr, int i, int j){
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

int partition(int* arr, struct Task t) {
    struct Task lrind=t;
    int pivot = arr[t.low + (t.high - t.low) / 2];
    while (lrind.low <= lrind.high) {

        while (arr[lrind.low] < pivot) {
            lrind.low++;
        }

        while (arr[lrind.high] > pivot) {
            lrind.high--;
        }

        if (lrind.low <= lrind.high) {
            swap(arr, lrind.high, lrind.low);
            lrind.low++;
            lrind.high--;
        }
    }
    return lrind.low;
}

void qsstack(int* arr, int n){
    struct stack* s=calloc(1,sizeof (struct stack));
    struct Task t;
    t.high=n-1;
    t.low=0;
    s->down=NULL;
    s->t=t;
    while(s != NULL){
        t=Pop(s);
        struct stack* sm=s;
        s=s->down;
        free(sm);
        if(t.low<t.high) {
            int pivo = partition(arr, t);
            struct stack* s1= calloc(1,sizeof (struct stack));
            int k = t.high;
            t.high = pivo - 1;
            s1->down = s;
            s1->t = t;
            s = s1;
            struct stack* s2=calloc(1,sizeof (struct stack));
            t.low = pivo;
            t.high = k;
            s2->down = s;
            s2->t = t;
            s = s2;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    qsstack(arr,n);
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}

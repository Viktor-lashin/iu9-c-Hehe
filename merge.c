#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *arr;
    int size;
    int start;
};

void swap(struct Array *a, struct Array *b){
    struct Array t = *a;
    (*a) = (*b);
    (*b) = t;
}



int main(){
    int k, count = 0;
    scanf("%d", &k);
    struct Array arr[k];
    for(int i = 0 ; i < k ; i++){
        scanf("%d", &arr[i].size);
        arr[i].arr = calloc(arr[i].size, sizeof(int));
        count += arr[i].size;
    }

    struct Array Queue[k];
    int end = 0;

    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < arr[i].size ; j++){
            scanf("%d", &arr[i].arr[j]);
        }
        Queue[end] = arr[i];
        Queue[end].start = 0;
        end++;
        int step = end-1;
        while(Queue[step].arr[0] < Queue[step >> 1].arr[0]){
            swap(&Queue[step], &Queue[step >> 1]);
            if(step == 0) break;
            step = (step>>1);
        }
    }
    for(int i = 0 ; i < count ; i++){
        printf("%d ", Queue[0].arr[Queue[0].start]);
        Queue[0].start++;
        if(Queue[0].start == Queue[0].size){
            swap(&Queue[0], &Queue[end-1]);
            end--;
        }
        int step = 0;
        while(((step<<1) < end) 
              && (Queue[step<<1].arr[Queue[step<<1].start] 
                  < Queue[step].arr[Queue[step].start] 
              || (((step<<1) + 1 < end)
              && (Queue[(step<<1) + 1].arr[Queue[(step<<1) + 1].start] 
                  < Queue[step].arr[Queue[step].start])))){
            if(((step<<1) + 1 < end)
              && (Queue[(step<<1) + 1].arr[Queue[(step<<1) + 1].start]
                  < Queue[step<<1].arr[Queue[step<<1].start])){
                swap(&Queue[(step<<1) + 1], &Queue[step]);
                step = (step<<1) + 1;
            }else{
                swap(&Queue[(step<<1)], &Queue[step]);
                step = (step<<1);
            }
        }
    }
    for(int i = 0 ; i < k ; i++) free(arr[i].arr);
}

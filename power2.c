#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int res=0;

void nice(int sum, int* arr, int n, int start ){
    if((sum&(sum-1))==0&&sum>=1) res++;
    if (start>=n-1)return;
    for (int i=1+start;i<n;i++){
        nice(sum+arr[i],arr,n,i);
    }
}

int main(int argc, char **argv) {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        nice(arr[i],arr,n,i);
    }
    printf("%d",res);
    return 0;
}

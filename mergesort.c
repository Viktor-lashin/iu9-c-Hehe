#include<stdio.h>

int abs(int a){
    return a>=0?a:-a;
}

void mikrosort(int* arr, int l, int r){
    int x,j;
    for (int i = l;i<=r;i++) {
        x = arr[i];
        j = i;
        while (j > l && abs(arr[j - 1]) > abs(x)) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = x;
    }
}

void swap(int* arr, int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void mergesort(int* arr, int l, int r){
    if(r-l+1<=5) mikrosort(arr,l,r);
    else{
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1, r);
        while(mid<r&&abs(arr[mid])>abs(arr[mid+1])){
            for(int i=mid+1;i>l&&abs(arr[i])<abs(arr[i-1]);i--){
                swap(arr, i,i-1);
            }
            mid++;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    mergesort(arr, 0, n-1);
    for(int i=0;i<n;i++) printf("%d " ,arr[i]);
    return 0;
}

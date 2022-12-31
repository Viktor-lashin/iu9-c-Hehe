#include<stdio.h>

void swap(int* arr, int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void prisort(int* arr, int n){
    for(int i=0;i<n;i++){
        int minind=i;
        for(int j=i+1;j<n;j++)if(arr[j]<arr[minind])minind=j;
        swap(arr,i,minind);
    }
}
void QuickSort(int* arr, int n,int  m){
    if(n<m) prisort(arr, n);
    else {
        int arr1[n], arr2[n], df = 0, ds = 0, ma = arr[n - 1];
        for (int i = 0; i < n - 1; i++)
            if (arr[i] <= ma) {
                arr1[df] = arr[i];
                df++;
            } else {
                arr2[ds] = arr[i];
                ds++;
            }
        QuickSort(arr1, df, m);
        QuickSort(arr2, ds, m);
        int k = 0;
        for (int i = 0; i < df; i++, k++)arr[k] = arr1[i];
        arr[k] = ma;
        k++;
        for (int i = 0; i < ds; i++, k++)arr[k] = arr2[i];
    }
}

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    QuickSort(arr, n, m);
    for(int i=0;i<n;i++) printf("%d " ,arr[i]);
    return 0;
}

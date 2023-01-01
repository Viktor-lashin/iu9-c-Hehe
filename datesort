#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date { int Day, Month, Year; };

void zh(int* arr, int len){
    int k=0;
    for(int i=0;i<len;i++){
        int temp=arr[i];
        arr[i]=k;
        k+=temp;
    }
}

void sort_rasp(struct Date* arr, int* mesto, int n, int plus, int fl){
    struct Date res[n];
    if(fl==0) {
        for (int i = 0; i < n; i++) {
            res[mesto[arr[i].Day - plus]] = arr[i];
            mesto[arr[i].Day - plus]++;
        }
        for (int i = 0; i < n; i++)arr[i] = res[i];
    }
    if(fl==1) {
        for (int i = 0; i < n; i++) {
            res[mesto[arr[i].Month - plus]] = arr[i];
            mesto[arr[i].Month - plus]++;
        }
        for (int i = 0; i < n; i++)arr[i] = res[i];
    }
    if(fl==2) {
        for (int i = 0; i < n; i++) {
            res[mesto[arr[i].Year - plus]] = arr[i];
            mesto[arr[i].Year - plus]++;
        }
        for (int i = 0; i < n; i++)arr[i] = res[i];
    }
}

int main() {
    int n;
    scanf("%d",&n);
    struct Date arr[n];
    int year[61]={0};
    int month[12]={0};
    int day[31]={0};
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].Year,&arr[i].Month,&arr[i].Day);
        year[arr[i].Year-1970]++;
        month[arr[i].Month-1]++;
        day[arr[i].Day-1]++;
    }

    zh(year,61);
    zh(month,12);
    zh(day,31);

    sort_rasp(arr,day,n,1,0);
    sort_rasp(arr,month,n,1,1);
    sort_rasp(arr,year,n,1970,2);
    for(int i=0;i<n;i++)printf("%04d %02d %02d ", arr[i].Year, arr[i].Month, arr[i].Day);
    return 0;
}

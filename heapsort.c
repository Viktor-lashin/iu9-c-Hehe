#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//компейр и свап нагло скопированы, но алгоритм самой сортировки мой

int compare_a(const void *first, const void *second) {
    char *a = *((char**)first);
    char *b = *((char**)second);
    int cnt_a = 0, cnt_b = 0;
    int n_a = (int)strlen(a), n_b = (int)strlen(b);

    if (n_a >= n_b) {
        for (int i = 0; i < n_b; i++) {
            if (a[i] == 'a') cnt_a++;
            if (b[i] == 'a') cnt_b++;
        }
        for (int i = n_b; i < n_a; i++) {
            if (a[i] == 'a') cnt_a++;
        }
    } else {
        for (int i = 0; i < n_a; i++) {
            if (a[i] == 'a') cnt_a++;
            if (b[i] == 'a') cnt_b++;
        }
        for (int i = n_a; i < n_b; i++) {
            if (b[i] == 'a') cnt_b++;
        }
    }

    return cnt_a - cnt_b;

}
void swap(void *a, void *b, size_t size) {
    char tmp;
    size_t i;
    for (i = 0; i < size; i++) {
        tmp = *((char*) b + i);
        *((char*) b + i) = *((char*) a + i);
        *((char*) a + i) = tmp;
    }
}

void hl(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b),int start){
    for(int j=start;j>=0;j--){
        int i=j;
        while((i<<1)+1<=start&&(compare((char*)base+(i<<1)*width,(char*)base+(i)*width)>0||compare((char*)base+((i<<1)+1)*width,(char*)base+(i)*width)>0)){
            if(compare((char*)base+(i<<1)*width,(char*)base+((i<<1)+1)*width)>0){
                swap((char*)base+(i<<1)*width,(char*)base+(i)*width,width);
                i=i<<1;
            }else{
                swap((char*)base+((i<<1)+1)*width,(char*)base+(i)*width,width);
                i=(i<<1)+1;
            }
        }
        if(i<<1<=start&&compare((char*)base+(i<<1)*width,(char*)base+(i)*width)>0){
            swap((char*)base+(i<<1)*width,(char*)base+(i)*width,width);
        }
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)) {
    int l=0,  r=nel-1;
    while(r!=l){
        hl(base,nel,width,compare,r);
        swap((char*)base+l*width, (char*)base+r*width,width);
        r--;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    char* arr[n];
    for(int i=0;i<n;i++){
        arr[i]=calloc(1001,sizeof (char));
        scanf("%s",arr[i]);
    }


    hsort(arr,n,sizeof (char*),compare_a);

    for(int i=0;i<n;i++) printf("%s " ,arr[i]);
    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem { struct Elem *prev, *next; int v; };

struct Elem* sort(struct Elem* start, int i, int n,struct Elem* step){
    if(i==n)return start;
    struct Elem* stepz=step->next;
    struct Elem* st=start;
    for(int j=0;j<i;j++){
        if(step->v<st->v){
            step->prev->next=step->next;
            step->next->prev=step->prev;
            step->prev=st->prev;
            st->prev->next=step;
            st->prev=step;
            step->next=st;
            if(j==0){
                start=start->prev;
            }
            return sort(start, i+1, n,stepz);
        }
        st=st->next;
    }
    return sort(start, i+1, n, stepz);
}
int main() {
    int n;
    struct Elem* start=NULL;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    if(n!=0){
        start= calloc(1, sizeof (struct Elem));
        start->v=arr[0];
    }
    struct Elem* step=start;
    for(int i=1;i<n;i++){
        step->next= calloc(1, sizeof (struct Elem));
        step->next->prev=step;
        step=step->next;
        step->v=arr[i];
    }
    start->prev=step;
    step->next=start;
    start=sort(start, 1, n, start->next);
    for(int i=0;i<n;i++){
        printf("%d ",start->v);
        struct Elem* temp=start;
        start=start->next;
        free(temp);
    }
    return 0;
}

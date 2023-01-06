#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem { struct Elem *prev, *next; int v; };

struct Elem* FREE[100000];
int i_free=0;

struct Elem* new(struct Elem* start, int x){

    if(start==NULL){
        start= calloc(1, sizeof(struct Elem));
        FREE[i_free]=start;
        i_free++;
        start->v=x;
        start->prev=start;
        start->next=start;
    }else{
        struct Elem* newElem= calloc(1,sizeof (struct Elem));
        FREE[i_free]=newElem;
        i_free++;
        newElem->v=x;
        start->prev->next=newElem;
        newElem->prev=start->prev;
        start->prev=newElem;
        newElem->next=start;
    }
    return start;
}

void vst(struct Elem* step, struct Elem* st){
    step->prev->next=step->next;
    step->next->prev=step->prev;
    step->prev=st->prev;
    st->prev->next=step;
    st->prev=step;
    step->next=st;
}

struct Elem* sort(struct Elem* start, int i, int n){
    if(i==n)return start;
    struct Elem* step=start;
    for(int j=0;j<i;j++){
        step=step->next;
    }
    struct Elem* st=start;
    for(int j=0;j<i;j++){
        if(step->v<st->v){
            vst(step, st);
            if(j==0){
                start=start->prev;
            }
            return sort(start, i+1, n);
        }
        st=st->next;
    }
    return sort(start, i+1, n);
}
int main() {
    int n;
    struct Elem* start=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        start=new(start, x);
    }

    start=sort(start, 1, n);
    for(int i=0;i<n;i++){
        printf("%d ",start->v);
        start=start->next;
    }
    for(int i=0;i<i_free;i++) free(FREE[i]);
    return 0;
}

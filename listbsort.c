#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem { struct Elem *next; char *word; };

void swap(struct Elem* a, struct Elem* b){
    char* temp=a->word;
    a->word=b->word;
    b->word=temp;
}

int comp(char* a, char* b) {
    return strlen(a)> strlen(b);
}

struct Elem *bsort(struct Elem *list) {
    int flag=1;
    if(list==NULL)return list;
    while(flag){
        flag=0;
        struct Elem* el=list;
        while(el->next!=NULL){
            if(comp(el->word, el->next->word)){
                swap(el, el->next);
                flag=1;
            }
            el=el->next;
        }
    }
    return list;
}
int main() {
    char* a= calloc(1001,sizeof (char));
    struct Elem* list=NULL;
    struct Elem* t=list;
    int k=0;
    gets(a);
    char* str;
    int flag=1;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==' ' && flag)continue;
        if(a[i]==' ' && flag==0){
            struct Elem* el= calloc(1,sizeof (struct Elem));
            el->word=str;
            el->next=NULL;
            if(list==NULL){
                list=el;
                t=list;
            }else {
                t->next = el;
                t = t->next;
            }
            flag=1;
            continue;
        }
        if(a[i]!=' ' && flag){
            flag=0;
            str= calloc(1001, sizeof(char));
            k=0;
        }
        if(a[i]!=' '){
            str[k]=a[i];
            k++;
        }
    }
    if(flag==0){
        struct Elem* el= calloc(1,sizeof (struct Elem));
        el->word=str;
        el->next=NULL;
        if(list==NULL){
            list=el;
        }else {
            t->next = el;
        }
    }
    bsort(list);
    t=list;
    while(list!=NULL){
        printf("%s ",list->word);
        list=list->next;
    }
    while (t!=NULL){
        list=t->next;
        free(t->word);
        free(t);
        t=list;
    }
    free(a);
    return 0;
}

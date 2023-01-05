#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem { struct Elem *next; char *word; };

struct Elem *bsort(struct Elem *list) {
    if(list==NULL)return list;
    size_t f=0;
    for(struct Elem* el=list;el->next!=NULL;el=el->next){
        if(strlen(el->word)>strlen(el->next->word)){
            char* temp=el->word;
            el->word=el->next->word;
            el->next->word=temp;
            f=1;
        }
    }
    if(f)return bsort(list);
    return list;
}
int main() {
    struct Elem *list=NULL, *step=NULL, *newElem;
    char c;
    char* nowstr;
    int flag=1,ind=0;
    scanf("%c",&c);
    while(c!='\n'){
        if(c==' '&&flag==0){
            flag=!flag;
            newElem = calloc(1, sizeof(struct Elem));
            newElem->word=nowstr;
            newElem->next=NULL;
            if(list==NULL){
                list=newElem;
                step=list;
            }else{
                step->next=newElem;
                step=step->next;
            }
            ind=0;
        }
        else{
            if(c!=' '){
                if(flag){
                    nowstr= calloc(1001,sizeof (char));
                    flag=!flag;
                }
                nowstr[ind++]=c;
            }
        }
        scanf("%c",&c);
    }
    if(ind){
        newElem= calloc(1,sizeof (struct Elem));
        newElem->word=nowstr;
        newElem->next=NULL;
        if(list==NULL)list=newElem;
        else step->next=newElem;
    }
    for(struct Elem *el=bsort(list);el!=NULL;){
        printf("%s ", el->word);
        list=el;
        el=el->next;
        free(list->word);
        free(list);
    }
    return 0;
}

#include <stddef.h>
#include "elem.h"

struct Elem *searchlist(struct Elem *list, int k) {
    while(list!=NULL){
        if(list->value.i==k&&list->tag==INTEGER)break;
        list=list->tail;
    }
    return list;
}

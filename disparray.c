#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Elem{
    int val;
    int ind;
    struct Elem *next_elem;
};

int main(){
    int m, j, v;
    scanf("%d", &m);
    struct Elem **table = calloc(m, sizeof(struct Elem*));
    char instruction[10];
    scanf("%s", instruction);
    while(strcmp(instruction, "END") != 0){
        if(strcmp(instruction, "ASSIGN") == 0){
            scanf("%d%d", &j, &v);
            struct Elem *step = table[j % m];
            struct Elem *step_pred = NULL;
            while(step != NULL && step->ind != j){
                step_pred = step;
                step = step->next_elem;
            }
            if(step != NULL){
                step->val = v;
                if(v == 0){
                    if(step_pred != NULL){
                        step_pred->next_elem = step->next_elem;
                        free(step);
                    }else{
                        table[j % m] = step->next_elem;
                        free(step);
                    }
                }
            }else
                if(v != 0){
                    struct Elem *newElem = calloc(1, sizeof(struct Elem));
                    newElem->ind = j;
                    newElem->val = v;
                    newElem->next_elem = table[j % m];
                    table[j % m] = newElem;
                }
        }
        if(strcmp(instruction, "AT") == 0){
            scanf("%d", &j);
            struct Elem *step = table[j % m];
            while(step != NULL && step->ind != j)
                step = step->next_elem;
            printf("%d\n", step == NULL ? 0 : step->val);
        }
        scanf("%s", instruction);
    }
    for(int i = 0 ; i < m ; i++){
        struct Elem *step = table[i];
        while(step != NULL){
            struct Elem *temp = step->next_elem;
            free(step);
            step = temp;
        }
    }
    free(table);
}

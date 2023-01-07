#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//наговнокидил, факт. НО это работает
struct bor{
    struct bor* next;
    char val;
    int size;
    int Znach;
    int end;
};

struct del{
    struct bor* kill;
    struct del* next;
};

struct del cal;
struct del* calI=&cal;

struct del* Free(struct del* g){

    free(g->kill);
    if(g->next!=NULL) {
        Free(g->next);
        free(g->next);
    }
    return g;
}

void newcal(struct bor*a){
    struct del *b= calloc(1,sizeof (struct del));
    b->kill=a;
    b->next=NULL;
    calI->next=b;
    calI=b;
}

struct bor* INSERT(struct bor* now,char a){
    for(int i=0;i<now->size;i++){
        if(now->next[i].val==a) {
            now->next[i].Znach++;
            return &now->next[i];
        }
    }
    now->next[now->size].val=a;
    now->next[now->size].size=0;
    now->next[now->size].Znach=1;
    now->next[now->size].end=0;
    now->next[now->size].next= calloc(27, sizeof (struct bor));
    newcal(now->next[now->size].next);
    now->size++;
    return &now->next[now->size-1];
}
struct bor* DELETE(struct bor* now,char a){
    for(int i=0;i<now->size;i++){
        if(now->next[i].val==a){
            if(now->next[i].Znach>0)now->next[i].Znach--;
            return &now->next[i];
        }
    }
    now->next[now->size].val=a;
    now->next[now->size].size=0;
    now->next[now->size].Znach=0;
    now->next[now->size].end=0;
    now->next[now->size].next= calloc(27, sizeof (struct bor));
    newcal(now->next[now->size].next);
    now->size++;
    return &now->next[now->size-1];
}
struct bor* PREFIX(struct bor* now,char a){
    for(int i=0;i<now->size;i++){
        if(now->next[i].val==a) return &now->next[i];
    }
    now->next[now->size].val=a;
    now->next[now->size].size=0;
    now->next[now->size].Znach=0;
    now->next[now->size].end=0;
    now->next[now->size].next= calloc(27, sizeof (struct bor));
    newcal(now->next[now->size].next);
    now->size++;
    return &now->next[now->size-1];
}
int equel(char* a, char* b){return strcmp(a,b)==0;}

int main() {
    struct del* g=&calI;
    struct bor *kor = calloc(1, sizeof(struct bor));
    calI->next=NULL;
    calI->kill=kor;
    kor->val = '&';
    kor->next = calloc(27, sizeof(struct bor));
    newcal(kor->next);
    kor->size = 0;
    kor->Znach = 0;
    char command[100];
    scanf("%s", command);
    while (!equel(command, "END")) {
        if (equel(command, "INSERT")) {
            char* x=calloc(100001,sizeof(char));
            scanf("%s", x);
            struct bor* step=kor;
            for(int i=0;x[i]!='\0';i++){
                step=PREFIX(step,x[i]);
            }
            if(step->end==0) {
                step=kor;
                for (int i = 0; x[i] != '\0'; i++) {
                    step = INSERT(step, x[i]);
                }
                step->end = 1;
            }
            free(x);
        }
        if (equel(command, "DELETE")) {
            char* x=calloc(100001,sizeof(char));
            scanf("%s", x);
            struct bor* step=kor;
            for(int i=0;x[i]!='\0';i++){
                step=DELETE(step,x[i]);
            }
            step->end=0;
            free(x);
        }
        if (equel(command, "PREFIX")) {
            char* x=calloc(100001,sizeof(char));
            scanf("%s", x);
            struct bor* step=kor;
            for(int i=0;x[i]!='\0';i++){
                step=PREFIX(step,x[i]);
            }
            printf("%d ",step->Znach);
            free(x);
        }
        scanf("%s", command);
    }
    Free(g);
    return 0;
}

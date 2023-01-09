#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

struct stack {
    int* el;
    int ind;
};

int equel(char* a, char* b){return strcmp(a,b)==0;}

void CONST(struct stack *Stack, int x){
    Stack->el[Stack->ind]=x;
    Stack->ind++;
}

int POP(struct stack* Stack){
    Stack->ind--;
    return Stack->el[Stack->ind];
}

void ADD(struct stack* Stack){CONST(Stack,POP(Stack)+POP(Stack));}
void SUB(struct stack* Stack){CONST(Stack,POP(Stack)-POP(Stack));}
void MUL(struct stack* Stack){CONST(Stack,POP(Stack)*POP(Stack));}
void DIV(struct stack* Stack){CONST(Stack,POP(Stack)/POP(Stack));}
void MAX(struct stack* Stack){CONST(Stack,fmax(POP(Stack),POP(Stack)));}
void MIN(struct stack* Stack){CONST(Stack,fmin(POP(Stack),POP(Stack)));}
void NEG(struct stack* Stack){CONST(Stack,-POP(Stack));}
void DUP(struct stack* Stack){CONST(Stack,Stack->el[Stack->ind-1]);}
void SWAP(struct stack* Stack){
    int a=POP(Stack);
    int b=POP(Stack);
    CONST(Stack,a);
    CONST(Stack,b);
}

int main() {
    struct stack Stack;
    Stack.el= calloc(100000, sizeof (int));
    Stack.ind=0;
    char command[100];
    scanf("%s",command);

    while(!equel(command,"END")){
        if(equel(command,"CONST")){
            int x;
            scanf("%d",&x);
            CONST(&Stack,x);
        }
        if(equel(command,"ADD")) ADD(&Stack);
        if(equel(command,"SUB")) SUB(&Stack);
        if(equel(command,"MUL")) MUL(&Stack);
        if(equel(command,"DIV")) DIV(&Stack);
        if(equel(command,"MAX")) MAX(&Stack);
        if(equel(command,"MIN")) MIN(&Stack);
        if(equel(command,"NEG")) NEG(&Stack);
        if(equel(command,"DUP")) DUP(&Stack);
        if(equel(command,"SWAP")) SWAP(&Stack);
        scanf("%s",command);
    }
    printf("%d", Stack.el[Stack.ind-1]);
    free(Stack.el);
    return 0;
}

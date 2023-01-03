#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//по приколу сделал максмально коротко(не стал уж в 1 строчку через запятую, старался всё же соблюдать некоторые правила)
struct stack {
    int* el;
    int ind;
};

struct stack Stack;

void CONST(int x){Stack.el[Stack.ind++]=x;}

int POP(){return Stack.el[--Stack.ind];}

void ADD(){CONST(POP()+POP());}
void SUB(){CONST(POP()-POP());}
void MUL(){CONST(POP()*POP());}
void DIV(){CONST(POP()/POP());}
void MAX(){CONST(fmax(POP(),POP()));}
void MIN(){CONST(fmin(POP(),POP()));}
void NEG(){CONST(-POP());}
void DUP(){CONST(Stack.el[Stack.ind-1]);}

int equel(char* a, char* b){return !strcmp(a,b);}

void SWAP(){
    int a=POP();
    int b=POP();
    CONST(a);
    CONST(b);
}

int main() {
    Stack.el= calloc(100000, sizeof (int));
    char command[100];
    scanf("%s",command);
    while(!equel(command,"END")){
        if(equel(command,"CONST")){
            int x;
            scanf("%d",&x);
            CONST(x);
        }
        if(equel(command,"ADD")) ADD();
        if(equel(command,"SUB")) SUB();
        if(equel(command,"MUL")) MUL();
        if(equel(command,"DIV")) DIV();
        if(equel(command,"MAX")) MAX();
        if(equel(command,"MIN")) MIN();
        if(equel(command,"NEG")) NEG();
        if(equel(command,"DUP")) DUP();
        if(equel(command,"SWAP")) SWAP();
        scanf("%s",command);
    }
    printf("%d", Stack.el[Stack.ind-1]);
    free(Stack.el);
    return 0;
}

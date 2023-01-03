#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct queue {
    int* el;
    int ind;
    int size;
};

struct queue Queue;

void ENQ(int x){
    Queue.el[Queue.ind]=x;
    Queue.ind++;
}

void SWAP(int i, int j){
    int a=Queue.el[i];
    Queue.el[i]=Queue.el[j];
    Queue.el[j]=a;
}

int DEQ(){
    for(int i=1;i<Queue.ind;i++) SWAP(i,i-1);
    Queue.ind--;
    return Queue.el[Queue.ind];
}

int EMPTY(){
    return Queue.ind==0;
}

int equel(char* a, char* b){return !strcmp(a,b);}

int main() {
    Queue.el= calloc(4, sizeof (int));
    Queue.size=4;
    Queue.ind=0;
    char command[100];
    scanf("%s",command);
    while(!equel(command,"END")){
        if(equel(command,"ENQ")){
            if(Queue.size==Queue.ind+1){
                Queue.size*=2;
                Queue.el= realloc(Queue.el, Queue.size*sizeof (int));
            }
            int x;
            scanf("%d",&x);
            ENQ(x);
        }
        if(equel(command,"DEQ"))printf("%d\n",DEQ());
        if(equel(command,"EMPTY")){
            if(EMPTY()){
                printf("true\n");
            }else{
                printf("false\n");
            }
        }
        scanf("%s",command);
    }
    free(Queue.el);
    return 0;
}

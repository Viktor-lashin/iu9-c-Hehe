#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bor{
    struct bor* next;
    struct bor* pred;
    char val;
    int size;
    int h;
    int Znach;
};

struct bor* calI[100000];
int III=0;

struct bor* poisk(struct bor* now,char a){
    for(int i=0;i<now->size;i++){
        if(now->next[i].val==a) return &now->next[i];
    }
    now->next[now->size].val=a;
    now->next[now->size].pred=now;
    now->next[now->size].size=0;
    now->next[now->size].h=now->h+1;
    now->next[now->size].Znach=-1;
    now->next[now->size].next= calloc(100, sizeof (struct bor));
    calI[III]=now->next[now->size].next;
    III++;
    now->size++;
    return &now->next[now->size-1];
}

int main() {
    struct bor* kor= calloc(1,sizeof (struct bor));
    calI[III]=kor;
    III++;
    struct bor* step= kor;
    kor->val=' ';
    kor->h=0;
    kor->next= calloc(100, sizeof (struct bor));
    calI[III]=kor->next;
    III++;
    kor->pred=NULL;
    kor->size=0;
    kor->Znach=-1;
    char c;
    int n;
    scanf("%d",&n);
    int I=0, flag=0, num=0;
    char*sp="+-*/()";
    c=getc(stdin);
    for(int i=0;i<n;i++){
        c=getc(stdin);
        if(flag==1&&!((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))){
            flag=0;
            if(step->Znach==-1){
                step->Znach=I;
                I++;
                printf("IDENT %d\n",I-1);
            }else{
                printf("IDENT %d\n",step->Znach);
            }
        }
        if(c>='0'&&c<='9'&&(flag==0||flag==2)){
            flag=2;
            num=num*10+(int)(c-'0');
            continue;
        }

        if(flag==2){
            flag=0;
            printf("CONST %d\n", num);
            num=0;
        }

        if(((c>='a'&&c<='z')||(c>='A'&&c<='Z')||((c>='0'&&c<='9')&&flag==1))){
            if(flag==0)step=kor;
            flag=1;
            step=poisk(step,c);
        }

        for(int i=0;i<6;i++){
            if(sp[i]==c){
                printf("SPEC %d\n", i);
            }
        }
    }

    if(flag==1){
        flag=0;
        if(step->Znach==-1){
            step->Znach=I;
            I++;
            printf("IDENT %d\n",I-1);
        }else{
            printf("IDENT %d\n",step->Znach);
        }
    }
    if(flag==2){
        flag=0;
        printf("CONST %d\n", num);
        num=0;
    }
    for(int i=0;i<III;i++){
        free(calI[i]);
    }
    return 0;
}

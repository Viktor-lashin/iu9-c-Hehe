#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//код возможно не рабочий, серв упал проверить нельзя
struct node{
    struct node* letter;
    char c;
    int size;
    int val;
};

int letter(char c){
    return (c>='a'&&c<='z'||c>='A'&&c<='Z');
}

int number(char c){
    return c>='0'&&c<='9';
}

struct node* next(struct node* now,char a){
    for(int i=0;i<now->size;i++)
        if(now->letter[i].c==a)
            return &now->letter[i];
    now->letter= realloc(now->letter, (now->size+1)*sizeof(struct node) );
    now->letter[now->size].c=a;
    now->letter[now->size].size=0;
    now->letter[now->size].val=-1;
    now->letter[now->size].letter= calloc(0, sizeof (struct node));
    now->size++;
    return &now->letter[now->size-1];
}

struct node* Free(struct node* root){
    for(int i=0;i<root->size;i++){
        free(Free(&root->letter[i]));
    }
    return root;
}

int main() {
    struct node* root= calloc(1,sizeof (struct node));
    root->c=' ';
    root->letter= calloc(0, sizeof (struct node));
    root->size=0;
    root->val=-1;
    char c;
    int n, k=0;
    scanf("%d",&n);
    char pred;
    char *special="+-*/()";
    struct node* step;
    c=getc(stdin);
    for(int i=0;i<n;i++){
        c=getc(stdin);
        if(number(c)){
            int num=0;
            while (number(c)&&i<n){
                num=num*10+(int)(c-'0');
                if(i+1!=n)c=getc(stdin);

                i++;
            }
            printf("CONST %d\n", num);
        }
        if(letter(c)){
            step=root;
            while ( (number(c)|| letter(c)) && i<n){
                step = next(step,c);
                if(i+1!=n)c=getc(stdin);
                i++;
            }
            if(step->val==-1)step->val=k++;
            printf("IDENT %d\n",step->val);
        }
        for(int i=0;i<6;i++){
            if(special[i]==c){
                printf("SPEC %d\n", i);
            }
        }
    }
    free(Free(root));
    return 0;
}

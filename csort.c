#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int comp(char *a, char *b){
    if (strlen(a)!=strlen(b))
        if (strlen(a)>strlen(b))
            return 1;
        else return -1;
    return 0;
}

void csort(char *src, char *dest) {
    char** b = calloc(10000,sizeof(char*));
    char** d = calloc(10000,sizeof(char*));
    int j=-1,n=strlen(src),flag=1,s=0;
    for(int i=0;i<n;i++){
        if(src[i]==' '){
            flag=1;
            continue;
        }
        if(flag){
            j++;
            b[j]=calloc(10000,sizeof(char));
            s=0;
            flag=0;
        }
        b[j][s]=src[i];

        s++;
    }

    int c[j+1];
    int N=j+1,i=0;
    for (i = 0; i < N ; i ++)
        c[i]=0;
    for (i=N-1; i>=1;i--)
        for(j=i-1; j>=0; j--)
            if (comp(b[i],b[j])==-1)
                c[j]++;
            else
                c[i]++;
    for (i=0; i < N ; i ++){
        d[c[i]] = b[i];
    }
    int k=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<strlen(d[i]);j++){
            dest[k]=d[i][j];
            k++;
        }
        dest[k]=' ';
        k++;
    }
    dest[k-1]='\0';
    for(int i=0;i<N;i++){
        free(d[i]);
    }
    free(b);
    free(d);
}

int main(){
    char* res=calloc(10000,sizeof(char));
    char* vvod=calloc(10000,sizeof(char));
    gets(vvod);
    csort(vvod,res);
    printf("%s\n",res);
    free(res);
    free(vvod);
    return 0;
}

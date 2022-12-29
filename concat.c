#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ss;
char *concat(char **s, int n) {
    int len=0;
    for (int i=0;i<n;i++) len+=strlen(s[i]);
    ss= calloc(len+1,sizeof (char*));
    for (int i=0,k=0;i<n;i++){
        for(int j=0;s[i][j]!='\0';j++,k++){
            ss[k]=s[i][j];
        }
    }
    ss[strlen(ss)]='\0';
    return ss;
}
int main() {
    int n;
    scanf("%d",&n);
    if (n<=0)return 0;
    char** s=calloc(n,sizeof(char*));
    for (int i=0;i<n;i++){
        s[i]=calloc(1001,sizeof(char));
        scanf("%s",s[i]);
    }
    char* res = concat(s,n);
    printf("%s", res);
    for(int i=0;i<n;i++) free(s[i]);
    free(s);
    free(res);
    return 0;
}


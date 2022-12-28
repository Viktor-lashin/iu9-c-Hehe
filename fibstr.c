#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n) {
    char* s = calloc(2, sizeof(char));
    char* ss = calloc(2, sizeof(char));
    strcpy(s, "a");
    if(n==1){
        free(ss);
        return s;
    }
    strcpy(ss, "b");
    char* t=calloc(1, sizeof(char));
    for (int j=2;j<n;j++){
        s = realloc(s, strlen(s)+strlen(ss)+1);
        strcat(s, ss);
        t=realloc(t,strlen(s)+1);
        strcpy(t,s);
        strcpy(s,ss);
        ss = realloc(ss, strlen(t)+1);
        strcpy(ss,t);
    }
    free(t);
    free(s);
    return ss;
}
int main() {
    int n;
    scanf("%d",&n);
    char* res = fibstr(n);
    printf("%s ",res);
    free(res);
    return 0;
}

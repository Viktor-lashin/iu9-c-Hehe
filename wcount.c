#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) {
    int flag=0,ans=0;
    for (int i=0;i<strlen(s);i++){
        if(flag==0 && s[i]!=' '){
            ans+=1;
        }
        flag=(s[i]!=' ');
    }
    return ans;
}
int main() {
    char* s;
    s=calloc(1000,sizeof(char));
    gets(s);
    int res = wcount(s);
    printf("%d", res);
    free(s);
    return 0;
}

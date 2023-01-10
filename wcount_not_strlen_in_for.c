#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) {
    int ans=0, LenS=strlen(s);
    for (int i=0;i<LenS;i++)
        if((!i || s[i-1]==' ') && s[i]!=' ')
            ans++;
    return ans;
}

int main() {
    char* s=calloc(1000,sizeof(char));
    gets(s);
    int res = wcount(s);
    printf("%d", res);
    free(s);
    return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int strdiff(char *a, char *b) {
    int k=0;
    for (int i=0;i<=strlen(a)&&i<=strlen(b);i++){
        int sdvig=1;
        for (int j=0;j<8;j++){
            if((int)(a[i]&sdvig) != (int)(b[i]&sdvig))return k;
            k++;
            sdvig<<=1;
        }
    }
    if (strlen(a)==strlen(b)) return -1;
    return k+1;
}
int main() {
    char *a=calloc(1001,sizeof(char));
    char *b=calloc(1001,sizeof(char));
    scanf("%s%s",a,b);
    printf("%d",strdiff(a,b));
    free(a);
    free(b);
    return 0;
}

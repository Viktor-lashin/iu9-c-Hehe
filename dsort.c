#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int arr[27]={0};
    char c='a';
    while(c<='z'&&c>='a'){
        arr[(int)c-(int)'a']++;
        scanf("%c",&c);
    }
    arr[0]--;
    for(int i=0;i<27;i++)
        for(int j=0;j<arr[i];j++)
            printf("%c", i+'a');
    return 0;
}

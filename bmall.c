#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* S=argv[1];
    char* T=argv[2];
    int arr[127], lenT = strlen(T), lenS = strlen(S);
    for(int i=33;i<=126;i++)arr[i]=lenS;
    for(int i=0;i<lenS;i++)arr[(int)S[i]]=lenS-i;
    int j = lenS-1, k=lenS-1, i=lenS-1;
    while (i < lenT ) {
        j = lenS - 1;
        k = i;
        while (j >= 0 && S[j] == T[k]) {
            k--;
            j--;
        }
        if(j<0){
            printf("%d ",k+1);
            i += arr[(int)T[k+1]];
        }
        else i += arr[(int)S[j]];
    }
    return 0;
}

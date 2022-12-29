#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* S=argv[1] ;
    char* T=argv[2];
    int lenT= strlen(T),lenS= strlen(S);
    int arr[lenS];
    arr[0]=0;
    int i=1,j=0;
    while(i!=lenS&&j!=lenS){
        if(S[i]==S[j]){
            arr[i]=j+1;
            i++;
            j++;
        }else{
            if(j){
                j=arr[j-1];
            }else{
                arr[i]=0;
                i++;
            }
        }
    }

    int k=0,l=0;
    while(k<lenT){
        if(T[k]==S[l]){
            k++;
            l++;
            if(l==lenS){
                printf("%d ",k-l);
                if(l==0)k++;
                else{
                    l=arr[l-1];
                }
            }
        }else{
            if(l==0)k++;
            else{
                l=arr[l-1];
            }
        }
    }
    return 0;
}

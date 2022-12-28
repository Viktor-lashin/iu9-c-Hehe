#include <stdio.h>
#include <math.h>

int main()
{
    int A[8], b , l=0;
    for (int i=0;i<8;i++)
        scanf("%d",&A[i]);
    for (int i=0;i<8;i++){
        scanf("%d",&b);
        for (int j=0;j<8;j++){
            if((A[j]==b) && (!(l & (1<<j)))){
                l |= (1<<j);
                break;
            }
        }
    }
    if (l==255)
        printf("yes");
    else
        printf("no");
    return 0;
}

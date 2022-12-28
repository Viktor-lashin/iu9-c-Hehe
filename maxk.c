#include <stdio.h>
#include <math.h>

int main()
{
    int N,l=0,r;
    scanf("%d",&N);
    long long A[N], sum=0, maxsum=0;
    for (int i=0;i<N;i++){
        scanf("%lld",&A[i]);
    }
    scanf("%d",&r);
    for (int i=0;i<r;i++)
        sum+=A[i];
    maxsum=sum;
    for (;r!=N;r++,l++){
        sum=sum-A[l]+A[r];
        maxsum=fmax(sum, maxsum);
    }
    printf("%lld", maxsum);
    return 0;
}

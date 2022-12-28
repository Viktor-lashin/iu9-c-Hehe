#include <stdio.h>
#include <math.h>
#define inf 10000
int main()
{
    int N,M,a;
    scanf("%d%d",&N,&M);
    int MaxStr[N];
    int MinStb[M];
    for (int i=0; i<N;i++)
        MaxStr[i]=-inf;
    for (int i=0; i<M;i++)
        MinStb[i]=inf;
    
    for (int i=0; i<N;i++)
        for (int j=0 ; j<M ; j++){
            scanf("%d", &a);
            MaxStr[i]=fmax(a,MaxStr[i]);
            MinStb[j]=fmin(a,MinStb[j]);
        }
    for (int i=0; i<N;i++)
        for (int j=0 ; j<M ; j++)
            if (MaxStr[i]==MinStb[j])
            {
                printf("%d %d",i,j);
                return 0;
            }
    printf("none");
    return 0;
}

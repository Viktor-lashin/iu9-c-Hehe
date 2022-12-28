#include <stdio.h>
#include <math.h>

int main()
{
    long long int N, P=0, P_p=0, a,x;
    scanf("%lli%lli",&N,&x);
    for (long long int i=0;i<=N;i++){
        scanf("%lli",&a);
        P=P*x+a;
        if(i!=N)P_p= P_p*x+a*(N-i);
    }
    printf("%lli %lli", P,P_p);
    return 0;
}

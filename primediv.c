#include <stdio.h>
#include <math.h>
#include <stdlib.h>
\\Строго не судить, главное, что зашло!!!(он не проверил ещё, но решето тут использовано)
int main()
{
    unsigned long long x;
    long long r;
    scanf("%lld",&r);
    if (r<0) x=-r;
    else x=r;
    unsigned long long s=sqrt(x)+2;
    short A[100000]={0};
    A[0]=1;
    A[1]=1;
    unsigned long long prime[10000]={0},k=0;
    for (unsigned  long long i=2;i<s;i++){
        if (A[i])continue;
        prime[k]=i;
        k++;
        for (unsigned long long j=i*2;j<s;j+=i)
            A[j]=1;
    }

    unsigned long long i=0;
    for (unsigned long long l=2;l<=sqrt(x)+1;l++){
        if (x%l==0)
            i=x/l;
            if (i>s-1){
                int flag=1;
                for (unsigned long long j=0;j<k;j++){
                    if (i%prime[j]==0){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    printf("%llu", i);
                    return 0;
                }
            }else{
                if (A[i]==0){
                    printf("%llu",i);
                    return 0;
                }
            }
    }
    for (unsigned long long l=sqrt(x)+1;l>=2;l--){
        if (x%l==0)
            i=l;
            if (i>s-1){
                int flag=1;
                for (unsigned long long j=0;j<k;j++){
                    if (i%prime[j]==0){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    printf("%llu", i);
                    return 0;
                }
            }else{
                if (A[i]==0){
                    printf("%llu",i);
                    return 0;
                }
            }
    }
    printf("%llu",x);
    return 0;
}

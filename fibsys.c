#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long int a;
    scanf("%llu",&a);
    unsigned long long int A[1000];
    A[0]=1;
    A[1]=2;
    int i=2;
    for (; A[i-1]<=a && A[i-1]>A[i-2];i++)
        if (i!=1)
            A[i]=A[i-1]+A[i-2];
    for (i-=2;i>=0;i--){
        if(a>=A[i]){
            a-=A[i];
            printf("1");
        }
        else
            printf("0");
    }
    return 0;
}

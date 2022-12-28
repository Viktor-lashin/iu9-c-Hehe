#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned long long int a, b , m , res=0;
    scanf("%llu%llu%llu",&a,&b,&m);
    for (unsigned long long int i=pow(2,63);i>0;i/=2){
        res=(res*2)%m;
        if (a&i) res=(res+b%m)%m;
    }
    printf("%llu", res%m);
    return 0;
}

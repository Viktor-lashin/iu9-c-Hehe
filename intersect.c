#include <stdio.h>
#include <math.h>

int main()
{
    int A=0, B=0, a, b , t ,res;
    scanf("%d",&a);
    for (int i=0; i<a ; i++ ){
        scanf("%d",&t);
        A |= (1<<(t+1));
    }
    scanf("%d",&b);
    for (int i=0; i<b ; i++ ){
        scanf("%d",&t);
        B |= (1<<(t+1));
    }
    res=A&B;
    for (int i=1;i<=32;i++){
        if( res & (1<<i))
            printf("%i ", i-1);
    }
    return 0;
}

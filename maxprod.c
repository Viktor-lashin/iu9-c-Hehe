#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

//вначале делал через структуру с 2мя интами, но видимо чиселки слишком большие были, так что поменял

struct num{
    long double a;
};

struct num max(struct num a, struct num b){
    if (a.a>b.a) return a;
    return b;
}


int main() {
    double l,r,u,j,aa,bb;
    int n;
    scanf("%d", &n);
    struct num arr[n];
    char c;
    for(int i=0;i<n;i++){
        scanf("%lf%c%lf",&aa,&c,&bb);
        arr[i].a=log2(aa/bb);
    }
    struct num nol;
    nol.a=0;
    struct num ans = arr[0], sum = nol;
    int  ans_l = 0,ans_r = 0,minus_pos = 0;
    for (int r=0; r<n;) {
        sum.a +=arr[r].a ;
        if (sum.a > ans.a) {
            ans = sum;
            ans_l = minus_pos;
            ans_r = r;
        }
        r++;
        if (sum.a < 0) {
            sum = nol;
            minus_pos = r;
        }
    }
    printf("%d %d",ans_l,ans_r);
    return 0;
}

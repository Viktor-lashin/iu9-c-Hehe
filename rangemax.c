#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define INF 1000000000


int t[10000000];

int combine (int a, int b) {
    if (a > b)
        return a;
    if (b > a)
        return b;
    return a;
}

void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = combine (t[v*2], t[v*2+1]);
    }
}

int max (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine (
            max (v*2, tl, tm, l, fmin(r,tm)),
            max (v*2+1, tm+1, tr, fmax(l,tm+1), r)
    );
}

void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = new_val, 1;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine (t[v*2], t[v*2+1]);
    }
}

int main() {
    int n,l,r,u,j;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    build(arr,1,0,n-1);
    char sl[4];
    while(1) {
        scanf("%s", sl);
        if(sl[0]=='E') return 0;
        if (sl[0] == 'M') {
            scanf("%d%d", &l, &r);
            printf("%d\n", max(1, 0, n - 1, l, r));
        }else{
            scanf("%d%d",&j,&u);
            update(1,0,n-1,j,u);
        }
    }
    return 0;
}

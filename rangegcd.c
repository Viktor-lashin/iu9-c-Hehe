#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long gcd(long num1, long num2){
    if(num1 == -1000000000) return num2;
    if(num2 == -1000000000) return num1;
    num1 = abs(num1);
    num2 = abs(num2);
    if (num1 * num2 == 0)
        return num1 + num2;
    if (num1 > num2)
        return gcd(num1 % num2, num2);
    return gcd(num1, num2 % num1);
}


long GCD(long *tree, int l, int r){
    if(l==r) return tree[l];
    if(l > r && l - r == 1) return gcd(tree[l], tree[r]);
    long max = -1000000000;
    if(l < r) return max;
    if(l % 2 == 1){
        max = gcd(tree[l], max);
        l--;
    }
    if(r % 2 == 0){
        max = gcd(tree[r], max);
        r++;
    }
    l = (l - 1)>>1;
    r = (r - 1)>>1;
    return gcd(max, GCD(tree, l , r));
}

void swap(long *a, long *b){
    int t = (*a);
    (*a) = (*b);
    (*b) = t;
}

void reverse(long *tree, int len)
{
    for(int i = 0 ; i < len/2 ; i++)
        swap(&tree[i], &tree[len - i - 1]);
}

int main() {
    long n, len = 1;
    scanf("%ld", &n);
    while(n - len > 0){
        len = len<<1;
    }
    long st = len;
    len = len<<1;
    len--;
    long *tree = calloc(len, sizeof(long));
    for(int i = 0 ; i < n ; i++ )
        scanf("%ld", &tree[i]);
    for(int i = n ; i < st ; i++)
        tree[i] = -1000000000;
    for(int i = st, ind = 0 ; i < len ; i++, ind += 2)
        tree[i] = gcd(tree[ind], tree[ind + 1]);
    reverse(tree, len);
    long m;
    scanf("%ld", &m);
    for(int i = 0 ; i < m ; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        l = len - l - 1;
        r = len - r - 1;
        printf("%ld\n", abs(GCD(tree, l, r)));

//        for(int i = 0 ; i < len ; i++)
//            printf("%d ", tree[i]);
//        printf("\n")
    }
    free(tree);
}

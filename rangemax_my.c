#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long MAX(long *tree, int l, int r){
    if(l==r) return tree[l];
    if(l > r && l - r == 1) return fmax(tree[l], tree[r]);
    long max = -1000000000;
    if(l < r) return max;
    if(l % 2 == 1){
        max = fmax(tree[l], max);
        l--;
    }
    if(r % 2 == 0){
        max = fmax(tree[r], max);
        r++;
    }
    l = (l - 1)>>1;
    r = (r - 1)>>1;
    return fmax(max, MAX(tree, l , r));
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
        tree[i] = fmax(tree[ind], tree[ind + 1]);
    reverse(tree, len);
    char instruction[10];
    scanf("%s", instruction);
    while(strcmp(instruction, "END") != 0){
        if(strcmp(instruction, "MAX") == 0){
            int l, r;
            scanf("%d%d", &l, &r);
            l = len - l - 1;
            r = len - r - 1;
            printf("%ld\n", MAX(tree, l, r));
        }
        if(strcmp(instruction, "UPD") == 0){
            long i, v;
            scanf("%ld%ld", &i, &v);
            i = len - i - 1;
            tree[i] = v;
            for(int j = (i-1)>>1 ; j > 0 ; j = (j-1)>>1){
                tree[j] = (i % 2 == 1) ? fmax(tree[i], tree[i + 1]) : fmax(tree[i], tree[i - 1]);
                i=j;
            }
            if(len > 2)
                tree[0] = fmax(tree[1], tree[2]);
        }
//        for(int i = 0 ; i < len ; i++)
//            printf("%d ", tree[i]);
//        printf("\n")
        scanf("%s", instruction);
    }
    free(tree);
}

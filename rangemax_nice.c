#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node{
    long val;
    int ind_child;
};

long gcd(long a, long b){
    if(a == 1000000000) return b;
    if(b == 1000000000) return a;
    if (a * b == 0)
        return fmax(a, b);
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

int deg(int n){
    int ans = 1;
    while(n - ans > 0)
        ans *=2;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int count_parents = deg(n);
    int count_node = count_parents * 2 - 1;
    struct Node *tree = calloc(count_node, sizeof(struct Node));
    for(int i = count_node - 1 ; i >= 0 ; i--){
        if(i >= count_node - n){
                scanf("%ld", &tree[i].val);
        }else{
            if (i >= count_node - count_parents){
                tree[i].val = -1000000000;
            }
        }
        tree[i].ind_child = (i - 1)/2;
        if(i % 2 == 0){
            tree[tree[i].ind_child].val = tree[i].val;
        }else{
            tree[tree[i].ind_child].val = gcd(abs(tree[i].val), abs(tree[tree[i].ind_child].val));
        }
    }
    char op[4];
    int m;
    scanf("%d", &m);
    while(m){
        m--;
        int l, r;
        scanf("%d%d", &l, &r);
        l = count_node - l - 1;
        r = count_node - r - 1;
        long max = -1000000000;
        while(1){
            if(l == r) {
                max = gcd(abs(tree[l].val), abs(max));
                break;
            }
            if(l > r && l - r == 1) {
                max = gcd(abs(max), gcd(abs(tree[l].val), abs(tree[r].val)));
                break;
            }
            if(l < r) break;
            if(l % 2 == 1){
                max = gcd(abs(tree[l].val), abs(max));
                l--;
            }
            if(r % 2 == 0){
                max = gcd(abs(tree[r].val), abs(max));
                r++;
            }
            l = tree[l].ind_child;
            r = tree[r].ind_child;
        }
        printf("%ld\n", max);
    }
    free(tree);
    return 0;
}

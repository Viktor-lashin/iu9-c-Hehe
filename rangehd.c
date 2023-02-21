#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct elem{
    int count[26];
};

struct elem sum(struct elem first, struct elem second){
    struct elem s;
    for(int i = 0 ; i < 26 ; i++){
        s.count[i] = first.count[i] + second.count[i];
    }
    return s;
}

struct elem SUM(struct elem *tree, int l, int r, struct elem *null){
    if(l==r) return tree[l];
    if(l > r && l - r == 1) return sum(tree[l], tree[r]);
    struct elem s = (*null);
    if(l < r) return s;
    if(l % 2 == 1){
        s = sum(tree[l], s);
        l--;
    }
    if(r % 2 == 0){
        s = sum(tree[r], s);
        r++;
    }
    l = (l - 1)>>1;
    r = (r - 1)>>1;
    return sum(s, SUM(tree, l , r, null));
}

void swap(struct elem *a, struct elem *b){
    struct elem t = (*a);
    (*a) = (*b);
    (*b) = t;
}

void reverse(struct elem *tree, int len)
{
    for(int i = 0 ; i < len/2 ; i++)
        swap(&tree[i], &tree[len - i - 1]);
}

void HD(struct elem *tree, int l, int r, struct elem *null){
    struct elem s = SUM(tree, l, r, null);
    int len = l - r + 1, honest = 0, odd = 0;
    for(int i = 0 ; i < 26 ; i++){
        honest += (s.count[i]%2 == 0 && s.count[i] != 0);
        odd += (s.count[i]%2 != 0 && s.count[i] != 0);
    }
    //printf("%d::%d::", honest, odd);
    if(len%2 == 1){
        if(odd == 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }else{
        if(odd == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}

int main() {
    char *str = calloc(1000001, 1);
    long n, len = 1;
    scanf("%s", str);
    n = strlen(str);
    while(n - len > 0){
        len = len<<1;
    }
    long st = len;
    len = len<<1;
    len--;
    struct elem null;
    for(int i = 0 ; i < 26 ; i++){
        null.count[i] = 0;
    }
    struct elem *tree = calloc(len, sizeof(struct elem));
    for(int i = 0 ; i < n ; i++ ){
        for(int j =0 ; j < 26 ; j++)
            tree[i].count[j] = 0;
        tree[i].count[str[i] - 'a']++;
    }
    for(int i = n ; i < st ; i++)
        tree[i] = null;
    for(int i = st, ind = 0 ; i < len ; i++, ind += 2)
        tree[i] = sum(tree[ind], tree[ind + 1]);
    reverse(tree, len);
    char instruction[10];
    scanf("%s", instruction);

    while(strcmp(instruction, "END") != 0){
        if(strcmp(instruction, "HD") == 0){
            int l, r;
            scanf("%d%d", &l, &r);
            l = len - l - 1;
            r = len - r - 1;
            HD(tree, l, r, &null);
        }
        if(strcmp(instruction, "UPD") == 0){
            long i;
            char *v = calloc(1000001, 1);
            scanf("%ld%s", &i, v);
            i = len - i - 1;
            int f = 0;
            while(i >= len - n - 1 && v[f] != '\0'){
                int save = i;
                tree[i] = null;
                tree[i].count[v[f] - 'a']++;
                for(int j = (i-1)>>1 ; j > 0 ; j = (j-1)>>1){
                    tree[j] = (i % 2 == 1) ? sum(tree[i], tree[i + 1]) : sum(tree[i], tree[i - 1]);
                    i=j;
                }
                if(len > 2)
                    tree[0] = sum(tree[1], tree[2]);
                i = save;
                i--;
                f++;
            }
            free(v);
        }
        //for(int i = 0 ; i < len ; i++){
        //    for(int j = 0 ; j < 26 ; j++)
        //        if(tree[i].count[j]!=0)
        //            printf("%c ", (char)('a'+j));
        //    printf("::\n");
        //}
        //printf("\n");
        scanf("%s", instruction);
    }
    free(tree);
    free(str);
}

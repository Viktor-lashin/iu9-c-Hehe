#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int peak(long *nums, int i, long n){
    if(i == 0){
        if(n>1)
            return nums[i] >= nums[i+1];
        return 1;
    }
    if(n - 1 == i)
        return nums[i] >= nums[i-1];
    return (nums[i] >= nums[i-1]) && (nums[i] >= nums[i+1]);
}

long PEAK(long *tree, int l, int r){
    if(l==r) return tree[l];
    if(l > r && l - r == 1) return (tree[l] + tree[r]);
    long max = 0;
    if(l < r) return max;
    if(l % 2 == 1){
        max = tree[l] + max;
        l--;
    }
    if(r % 2 == 0){
        max = tree[r] + max;
        r++;
    }
    l = (l - 1)>>1;
    r = (r - 1)>>1;
    return max + PEAK(tree, l , r);
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
    long *nums = calloc(n, sizeof(long));
    for(int i = 0 ; i < n ; i++ )
        scanf("%ld", &nums[i]);
    for(int i = 0 ; i < n ; i++ )
        tree[i] = peak(nums, i, n);
    for(int i = n ; i < st ; i++)
        tree[i] = 0;
    for(int i = st, ind = 0 ; i < len ; i++, ind += 2)
        tree[i] = tree[ind] + tree[ind + 1];
    reverse(tree, len);
    char instruction[10];
    scanf("%s", instruction);
    while(strcmp(instruction, "END") != 0){
        if(strcmp(instruction, "PEAK") == 0){
            int l, r;
            scanf("%d%d", &l, &r);
            l = len - l - 1;
            r = len - r - 1;
            printf("%ld\n", PEAK(tree, l, r));
        }
        if(strcmp(instruction, "UPD") == 0){
            long h, v;
            scanf("%ld%ld", &h, &v);
            nums[h] = v;
            int i = len - h - 1, a=0, b=0 ,c=0;
            tree[i] = peak(nums, h, n);
            if(h == 0){
                if(n > 1){
                    a = 1;
                    tree[i - 1] = peak(nums, h + 1, n);
                }
            }else{
                if(h == n - 1){
                    if(n > 1){
                        b = 1;
                        tree[i + 1] = peak(nums, h - 1, n);
                    }
                }else{
                    c = 1;
                    tree[i + 1] = peak(nums, h - 1, n);
                    tree[i - 1] = peak(nums, h + 1, n);
                }
            }
            int save = i;
            for(int j = (i-1)>>1 ; j > 0 ; j = (j-1)>>1){
                tree[j] = (i % 2 == 1) ? (tree[i] + tree[i + 1]) : (tree[i] + tree[i - 1]);
                i=j;
            }
            if(len > 2)
                tree[0] = (tree[1] + tree[2]);
            if(c || b){
                i = save + 1;
                for(int j = (i-1)>>1 ; j > 0 ; j = (j-1)>>1){
                    tree[j] = (i % 2 == 1) ? (tree[i] + tree[i + 1]) : (tree[i] + tree[i - 1]);
                    i=j;
                }
                if(len > 2)
                    tree[0] = (tree[1] + tree[2]);
            }
            if(c || a){
                i = save - 1;
                for(int j = (i-1)>>1 ; j > 0 ; j = (j-1)>>1){
                    tree[j] = (i % 2 == 1) ? (tree[i] + tree[i + 1]) : (tree[i] + tree[i - 1]);
                    i=j;
                }
                if(len > 2)
                    tree[0] = (tree[1] + tree[2]);
            }

        }
        scanf("%s", instruction);
    }
    free(tree);
    free(nums);
}

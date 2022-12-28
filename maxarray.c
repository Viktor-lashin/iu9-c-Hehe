#include <stdio.h>
#include <stdint.h>
#include <math.h>
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    uint8_t* max=base;
    uint8_t* p=base;
    int ind=0;
    for (;p<=(uint8_t*)base+(nel-1)*width;p+=width)
        if (compare(max,p)<0){
            ind=(p-(uint8_t*)base)/width;
            max=p;
        }
    return ind;
}

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int iq(unsigned long i, unsigned long j,int (*less)(unsigned long i, unsigned long j)){
    return less(i,j)==less(j,i) || less(j,i);
}
unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    unsigned long s=0;
    if (nel>1){
        if (iq(s,s+1,less)) return 0;
        if (iq(nel-1,nel-2,less)) return nel-1;
    }
    for (s=1;s<nel-1;s++){
        if (iq(s,s+1,less) && iq(s,s-1,less)){
            return s;
        }
    }
}

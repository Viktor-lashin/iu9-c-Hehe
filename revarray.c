#include <stdio.h>
#include <stdint.h>

void revarray(void* base, size_t nel, size_t width) {
    uint8_t* l = base;
    for (int i=0;i<nel/2;i++){
        for (int k=0;k<width;k++){
            uint8_t temp=*(l+k+i*width);
            *(l+k+i*width)=*(l+(nel-1-i)*width+k);
            *(l+(nel-1-i)*width+k)=temp;
        }
    }
}

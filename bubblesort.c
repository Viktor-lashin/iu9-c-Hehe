#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void bubblesort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j),void (*swap)(unsigned long i, unsigned long j))
{
    int flag=0;
    for(int i=1;i<nel;i++)if(compare(i-1,i)==1) swap(i-1,i);
    for(int i=nel-1;i>=1;i--)if(compare(i-1,i)==1) {swap(i-1,i),flag=1;}
    if(flag) bubblesort(nel,compare,swap);
}

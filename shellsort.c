void shellsort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j),void (*swap)(unsigned long i, unsigned long j))
{
    long count=1;
    long one=1,two=1;
    while(one+two<nel){
        long sum=one+two;
        two=one;
        one=sum;
        count++;
    }
    long res[count+1];
    one=1;
    two=1;
    res[0]=0;
    res[1]=1;
    long s=2;
    while(one+two<nel){
        long sum=one+two;
        two=one;
        one=sum;
        res[s]=sum;
        s++;
    }

    for(long k=count; k >= 0; k--) {
        long gap = res[k];
        for(long i=gap; i < nel; i++) {
            for(long j=i-gap; (j >= 0)&&(compare(j+gap,j)<0)  ; j-=gap)
                swap(j+gap,j);
        }
      }
}

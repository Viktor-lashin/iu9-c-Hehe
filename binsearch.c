unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) { 
    unsigned long l=0,r=nel-1;
    int flag = 0;
    int mid;
    while ((l <= r) && (flag!=1)) {
        mid = (l + r) / 2;
        if (compare(mid)==0) flag = 1;
        if (compare(mid)==1) r = mid - 1;
        else l = mid + 1;
   }
   if(flag) return mid; 
   else return nel;
}

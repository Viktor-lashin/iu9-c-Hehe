\\решение на 2 балла из 1
void bubblesort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j),void (*swap)(unsigned long i, unsigned long j))
{
    int found=0;
    for(int i=1;i<nel;i++)
        if(compare(i-1,i)==1)
            swap(i-1,i);
    nel--;
    for(int i=nel-1;i>=1;i--)
        if(compare(i-1,i)==1){
            swap(i-1,i);
            found=1;
        }
    if(found) bubblesort(nel,compare,swap);
}

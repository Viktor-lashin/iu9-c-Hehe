#include <stdio.h>

struct Date {
    int Day, Month, Year;
};

int *Tracker_Number(int ind, int tracker, struct Date* date){
    switch (tracker){
        case 0:
            return &date[ind].Year;
        case 1:
            return &date[ind].Month;
        default:
            return &date[ind].Day;
    }
}

int Tracker_Count(int tracker){
    switch (tracker){
        case 0:
            return 61;
        case 1:
            return 12;
        default:
            return 31;
    }
}

int Tracker_Min(int tracker){
    return tracker == 0 ? 1970 : 1;
}

void New_Date(int ind, struct Date* date){
    for(int tracker = 0 ; tracker < 3 ; tracker++)
        scanf("%d", Tracker_Number(ind, tracker, date));
}

void Look_Date(int ind, struct Date* date){
    for(int tracker = 0 ; tracker < 3 ; tracker++)
        if(Tracker_Min(tracker) > 1)
            printf("%04d ", *Tracker_Number(ind, tracker, date));
        else
            printf("%02d ", *Tracker_Number(ind, tracker, date));
    printf("\n");
}

void Array_in_Zero(int n, int* arr){
    for(int i = 0 ; i < n ; i++)
        arr[i] = 0;
}

void Distribution(int n, int tracker, int* Array_Distribution, struct Date* date){
    for(int i = 0 ; i < n ; i++)
        Array_Distribution[*Tracker_Number(i, tracker, date) - Tracker_Min(tracker)]++;
}

int* Decoding_Starts(int tracker, int* Starts, int* Array_Distribution){
    Starts[0]=0;
    for(int i = 1 ; i < Tracker_Count(tracker); i++)
        Starts[i] = Array_Distribution[i-1] + Starts[i-1];
    return Starts;
}

void Decoding(int n, int tracker, int* Array_Distribution, struct Date* date){
    int Starts[Tracker_Count(tracker)];
    Decoding_Starts(tracker, Starts, Array_Distribution);
    struct Date ans[n];
    for(int i = 0 ; i < n ; i++){
        int ind_start = *Tracker_Number(i, tracker, date) - Tracker_Min(tracker);
        ans[Starts[ind_start]] = date[i];
        Starts[ind_start]++;
    }
    for(int i = 0 ; i < n ; i++)
        date[i] = ans[i];
}

void Sort_Distribution(int n, int tracker, struct Date* date){
    int Array_Distribution[Tracker_Count(tracker)];
    Array_in_Zero(Tracker_Count(tracker), Array_Distribution);
    Distribution(n, tracker, Array_Distribution, date);
    Decoding(n, tracker, Array_Distribution, date);
}

void Radix_Sort(int n, struct Date* date){
    for(int tracker = 2 ; tracker >= 0 ; tracker--)
        Sort_Distribution(n, tracker, date);
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Date date[n];

    for(int i = 0 ; i < n ; i++)
        New_Date(i, date);

    Radix_Sort(n, date);

    for(int i = 0 ; i < n ; i++)
        Look_Date(i, date);
    return 0;
}

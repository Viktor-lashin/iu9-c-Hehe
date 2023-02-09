#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Next_Word(char **Words, char *src, int *start, int *ind_end){
    if(src[*start] == ' '){
        (*ind_end)--;
        return 1;
    }
    if(src[*start] == '/0'){
        (*ind_end)--;
        return 0;
    }
    int ind_c = 0;
    Words[*ind_end] = calloc(10000, 1);
    while(src[*start] != ' ' && src[*start] != '\0' && src[*start] != '\n'){
        Words[*ind_end][ind_c] = src[*start];
        (*start)++;
        ind_c++;
    }
    return src[*start] != '\0' && src[*start] != '\n' ? (*ind_end) + 1 : 0;
}

int compare(char **Words, int first_ind, int second_ind){
    return strlen(Words[first_ind]) >= strlen(Words[second_ind]) ? first_ind : second_ind;
}

void Counting (int ind_end, char **Words, int *count){
    for (int first_ind = ind_end ; first_ind >= 1 ; first_ind--)
        for(int second_ind = first_ind - 1 ; second_ind >= 0; second_ind--)
            count[compare(Words, first_ind, second_ind)]++;
}

void Decoding(char **Words_sort, char **Words, int *count, int ind_end){
    Words_sort[count[ind_end]] = Words[ind_end];
    if(ind_end != 0)
        Decoding(Words_sort, Words, count, ind_end - 1);
}

void copy(char *dest, char *word, int *pointer_dest){
    for(int ind = 0; ind < strlen(word); ind++){
        dest[*pointer_dest] = word[ind];
        (*pointer_dest)++;
    }
    dest[*pointer_dest] = ' ';
    (*pointer_dest)++;
}

void Result_Word(char *dest, char **Words_sort, int ind_end){
    int pointer_dest = 0, pointer_words = 0;
    for(; pointer_words <= ind_end ; pointer_words++){
        copy(dest, Words_sort[pointer_words], &pointer_dest);
    }
    dest[pointer_dest - 1] = '\0';
}

void Free(char **Words, int ind_end){
    for(int ind_free = 0 ; ind_free <= ind_end ; ind_free++)
        free(Words[ind_free]);
    free(Words);
}

void csort(char* src, char* dest){
    int start = 0, ind_end = 0;
    char **Words = calloc(10000, sizeof(char*));

    while(Next_Word(Words, src, &start, &ind_end)){
        ind_end++;
        start++;
    }

    int count[10000] = {0};
    Counting(ind_end, Words, count);

    char **Words_sort = calloc(10000, sizeof(char*));

    Decoding(Words_sort, Words, count, ind_end);

    Result_Word(dest, Words_sort, ind_end);

    Free(Words, ind_end);
    free(Words_sort);
}

int main(){
    char* src = calloc(10000, 1);
    gets(src);
    char* dest = calloc(10000, 1);
    csort(src, dest);
    printf("%s\n", dest);
    free(dest);
    free(src);
    return 0;
}

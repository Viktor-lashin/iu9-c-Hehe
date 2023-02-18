#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem_Bor{
    struct Elem_Bor *next[200];
    int count_prefix;
    int word_end;
};

void New_Elem(char c, struct Elem_Bor **head){
    (*head) = calloc(1, sizeof(struct Elem_Bor));
    (*head)->count_prefix = 1;
    (*head)->word_end = 0;
}

int contains(char* word, struct Elem_Bor *head){
    for(int i = 0 ; word[i] != '\0' ; i++){
        if(head == NULL) break;
        head = head->next[(int) word[i]];
    }
    if(head == NULL) return 0;
    return head->word_end;
}

void New_Word(char* word, struct Elem_Bor **head){
    for(int i = 0 ; word[i] != '\0' ; i++){
        if((*head) == NULL)
            New_Elem(word[i], head);
        else{
            head = (&((*head)->next[(int)word[i]]));
            if((*head) == NULL)
                New_Elem(word[i], head);
            else
                (*head)->count_prefix++;
        }
    }
    (*head)->word_end=1;
}
void PREFIX(char* word, struct Elem_Bor *head){
    for(int i = 0 ; word[i] != '\0' ; i++){
        if(head == NULL) break;
        head = head->next[(int) word[i]];
    }
    if(head == NULL)
        printf("0 ");
    else
        printf("%d ", head->count_prefix);
}

void DELETE(char* word, struct Elem_Bor *head){
    for(int i = 0 ; word[i] != '\0' ; i++){
        head = head->next[(int) word[i]];
        head->count_prefix--;
    }
    head->word_end=0;
}

void free_all(struct Elem_Bor *head){
    for(int i = 0 ; i < 200 ; i++){
        if(head->next[i] != NULL)
            free_all(head->next[i]);
    }
    free(head);
}

int main(){
    struct Elem_Bor *head = calloc(1, sizeof(struct Elem_Bor));
    head->count_prefix=1000000;
    char instruction[10];
    scanf("%s", instruction);
    while(strcmp(instruction, "END") != 0){
        if(strcmp(instruction, "INSERT") == 0){
            char* word = calloc(100000, 1);
            scanf("%s", word);
            if(!contains(word, head))
                New_Word(word, &head);
            free(word);
        }
        if(strcmp(instruction, "PREFIX") == 0){
            char* word = calloc(100000, 1);
            scanf("%s", word);
            PREFIX(word, head);
            free(word);
        }
        if(strcmp(instruction, "DELETE") == 0){
            char* word = calloc(100000, 1);
            scanf("%s", word);
            if(contains(word, head))
                DELETE(word, head);
            free(word);
        }
        scanf("%s", instruction);
    }
    free_all(head);
}

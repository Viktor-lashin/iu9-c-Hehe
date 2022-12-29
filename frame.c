#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ss;
int len=0;
char *concat(char **s, int n) {
    for (int i=0;i<n;i++) len+=strlen(s[i])+1;
    ss= calloc(len,sizeof (char*));
    for (int i=0,k=0;i<n;i++){
        for(int j=0;s[i][j]!='\0';j++,k++){
            ss[k]=s[i][j];
        }
        ss[k]=' ';
        k++;
    }
    ss[strlen(ss)-1]='\0';
    return ss;
}

void Ia_durashka(int n, char c){for(int i=0;i<n;i++)printf("%c",c);}

int main(int argc, char** argv) {
    if (argc<4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    char* s[argc-3];
    for(int i=3;i<argc;i++){
        s[i-3] = argv[i];
    }
    char* res= concat(s,argc-3);
    int h = strtol(argv[1],NULL,10);
    int w = strtol(argv[2],NULL,10);
    if((w-len+1<2)||(h<=2)){
        printf("Error");
        return 0;
    }
    Ia_durashka(w,'*');
    printf("\n");
    for(int i=1;i<=h-2;i++){
        if(i==(h-2)/2+(h-2)%2) {
            int tiki = w - 2 - strlen(res);
            Ia_durashka(1, '*');
            Ia_durashka(tiki / 2, ' ');
            printf("%s", res);
            Ia_durashka(tiki / 2 + tiki % 2, ' ');
            Ia_durashka(1, '*');
            printf("\n");
            continue;
        }
        Ia_durashka(1,'*');
        Ia_durashka(w-2,' ');
        Ia_durashka(1,'*');
        printf("\n");
    }
    Ia_durashka(w,'*');
    free(res);
    return 0;
}

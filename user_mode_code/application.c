#include <stdio.h>

#define MAXCHAR 100
int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "read.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}

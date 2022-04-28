#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Actors{
    char *name;
    int age;
    char* country;
    int profit;
    int num_oscars;
}actor;

void add(actor*, int*);
void bigger_profit(actor*, int, int);
void write_to_file(actor*, FILE*, int);
void read_from_file(FILE*);

int main() {
    actor *actp;
    int count=0, n=0, pr=0;
    actp = (actor*) calloc(2,sizeof(actor));
    if(actp == NULL) exit(1);
    printf("Enter how many actors you will add:");
    scanf("%d", &n);
    actp = (actor*) realloc(actp, n*sizeof(actor));
    for (int i = 0; i < n; ++i) add(actp, &count);
    printf("Enter profit:");
    scanf(" %d", &pr);
    printf("\n---------------\n");
    printf("Actors with bigger annual profit than %d:\n", pr);
    bigger_profit(actp, pr, count);
    printf("---------------\n");
    FILE *file;
    file = fopen("C:\\Users\\User\\Desktop\\c c++\\actors.txt", "w");
    if(file == NULL){
        perror(NULL);
        exit(errno);
    }
    write_to_file(actp, file, count);
    fclose(file);
    file = fopen("C:\\Users\\User\\Desktop\\c c++\\actors.txt", "r");
    if(file == NULL){
        perror(NULL);
        exit(errno);
    }
    read_from_file(file);
    fclose(file);
    free(actp);
}

void add(actor *actp, int* count){
    actor act;
    printf("Enter name:");
    act.name = (char*)malloc(50*sizeof(char));
    if(act.name == NULL) exit(1);
    scanf(" %s", act.name);
    act.name = (char *) realloc(act.name, strlen(act.name)*sizeof(char));
    printf("Enter age:");
    scanf(" %d", &act.age);
    printf("Enter nationality:");
    act.country = (char*) calloc(50, sizeof(char));
    if(act.country == NULL) exit(1);
    scanf(" %s", act.country);
    act.country = (char*) realloc(act.country, strlen(act.country)*sizeof(char));
    printf("Enter profit:");
    scanf(" %d", &act.profit);
    printf("Enter number of oscars:");
    scanf(" %d", &act.num_oscars);
    *(actp + (*count)) = act;
    ++(*count);
}

void bigger_profit(actor *actp, int pr, int count){
    char** arr;
    int c=0;
    arr = (char**) malloc(count*sizeof(char*));
    for (int i = 0; i < count; ++i) {
        if(actp[i].profit > pr) {
            arr[c] = actp[i].name;
            ++c;
        }
    }
    arr = (char**) realloc(arr, c*sizeof(char*));
    for (int i = 0; i < c; ++i) {
        printf(" %s\n", arr[i]);
    }
}

void write_to_file(actor *actp, FILE *file, int count){
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%s;", actp[i].name);
        free(actp[i].name);
        fprintf(file, "%d;", actp[i].age);
        fprintf(file, "%s;", actp[i].country);
        free(actp[i].country);
        fprintf(file, "%d;", actp[i].profit);
        fprintf(file, "%d\n", actp[i].num_oscars);
    }
}

void read_from_file(FILE *file){
    char ch;
    do {
        ch = fgetc(file);
        printf("%c", ch);
    } while (ch != EOF);
}
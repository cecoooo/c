#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();

int main() {
    int ex=0, *exp;
    exp= &ex;
    do {
        printf("Enter exercise:");
        scanf("%d", exp);
        switch (*exp) {
            case 1: printf("------1ex------\n"); ex1(); break;
            case 2: printf("------2ex------\n"); ex2(); break;
            case 3: printf("------3ex------\n"); ex3(); break;
            case 4: printf("------4ex------\n"); ex4(); break;
            case 5: printf("------5ex------\n"); ex5(); break;
            case 6: printf("------6ex------\n"); ex6(); break;
        }
    }while(*exp!=0);
}

int len(char arr[]){
    int count=0;
    for (int i = 0; i < strlen(arr); ++i) {
        ++count;
    }
    return count;
}

void ex1(){
    char arr[100];
    printf("Enter text:");
    scanf("%s", arr);
    int count=0;
    while(arr[count]!=NULL){
        count++;
    }
    printf("Length of the text: %d", count);
    free(arr);
    printf("\n");
}

void ex2() {
    char *arr;
    arr = (char*)calloc(100, sizeof(char));
    printf("Enter text:");
    while (getchar() != '\n');
    //gets(arr);
    fgets(arr, 100, stdin);
    arr = realloc(arr, len(arr)*sizeof(char));
    //scanf("%[^\n]%*c", arr);
    //scanf("%[^\n]s", arr);
    int counter = 1;
    for (int i = 0; i < len(arr); ++i) {
        if (*(arr+i) == ' ') {
            counter++;
        }
    }
    printf("Number of words: %d", counter);
    free(arr);
    printf("\n");
}


void ex3(){
    char *p, *pp;
    int *ascii, count=0;
    p = (char*)malloc(100*sizeof(char));
    printf("Enter text:");
    while (getchar() != '\n');
    fgets(p, 100, stdin);
    pp = (char*) calloc(strlen(p), sizeof(char));
    for (int i = 0; i < strlen(p)-1; ++i) {
        int t=1;
        for (int j = 0; j < strlen(pp); ++j) {
            if(*(p+i) == *(pp+j)){
                t=0;
            }
        }
        if(t){
            *(pp+count) = *(p+i);
            ++count;
        }
    }
    ascii = (int*) malloc(strlen(pp)*sizeof(int));
    for (int i = 0; i < strlen(pp); ++i) {
        int n=0;
        for (int j = 0; j < strlen(p); ++j) {
            if(*(pp+i)==*(p+j)){
                ++n;
            }
        }
        *(ascii+i) = n;
    }
    free(p);
    for (int i = 0; i < strlen(pp); ++i) {
        printf("%c -> %d\n", *(pp+i), *(ascii+i));
    }
    free(pp);
    free(ascii);
}

void ex4(){
    char *arr1, *arr2;
    arr1 = (char*)calloc(25, sizeof(char));
    arr2 = (char*)calloc(25, sizeof(char));
    printf("Enter first string:");
    while (getchar() != '\n');
    scanf("%[^\n]s", arr1);
    printf("Enter second string:");
    while (getchar() != '\n');
    scanf("%[^\n]s", arr2);
    arr1 = realloc(arr1, strlen(arr1)*sizeof(char));
    arr2 = realloc(arr2, strlen(arr2)*sizeof(char));
    if(strlen(arr1)!= strlen(arr2)) {
        printf("Strings are not equal.\n");
        free(arr1);
        free(arr2);
        return;}
    int t=1;
    for (int i = 0; i < strlen(arr1); ++i) {
        if(*(arr1+i)!=*(arr2+i)) t=0;
    }
    switch (t) {
        case 1: printf("Strings are equal.\n"); break;
        case 0: printf("Strings are not equal.\n"); break;
    }
}

void ex5(){
    char *arr;
    arr = (char*)calloc(100, sizeof(char));
    printf("Enter text:");
    while (getchar() != '\n');
    scanf("%[^\n]s", arr);
    arr = realloc(arr, len(arr)*sizeof(char));
    int count=0;
    for (int i = 0; i < len(arr); ++i) {
        switch (*(arr+i)) {
            case 'a': ++count; break;
            case 'e': ++count; break;
            case 'o': ++count; break;
            case 'u': ++count; break;
            case 'i': ++count; break;
        }
    }
    free(arr);
    printf("Number of vowels: %d\n", count);
}

void ex6(){
    char *arr;
    arr = (char*)calloc(100, sizeof(char));
    printf("Enter text:");
    while (getchar() != '\n');
    scanf("%[^\n]s", arr);
    if(arr==NULL || len(arr)==0) exit(1);
    arr = realloc(arr, len(arr)*sizeof(char));
    for (int i = 0; i < len(arr); ++i) {
        if(!isalpha(*(arr+i))) {printf("\nERROR: No alpha symbol..."); exit(1);}
        int c = *(arr+i) -32;
        printf("%c", c);
    }
    free(arr);
    printf("\n");
}
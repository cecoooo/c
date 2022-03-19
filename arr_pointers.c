#include <stdio.h>

void string();
void array_of_strings();

int main() {
    int arr[3]={1,2,3};
    int *p = arr;
    for (int i = 0; i < 3; ++i) {
        printf("%d ", *p);
        p++;
    }
    printf("\n---------------\n");
    string();
    printf("---------------\n");
    array_of_strings();
    return 0;
}
// *(a+i) = a[i]

void string() {
    char *str;
    int c = 5;
    str = "Hello";
    printf("%s\n", str);
    puts(str);
    // function 'puts()' prints string. It requires pointer to char array.
}

void array_of_strings(){
    char *name[3]={
        "Ivan",
        "Niki",
        "Dimo"
    };
    for (int i = 0; i < 3; ++i) {
        printf("%s\n", name[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        puts(name[i]);
    }
}



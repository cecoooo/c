#include <stdio.h>

int main() {
    // storing adresses
    int z = 0;
    printf("z = %d\n", z);
    printf("&z = %p\n", &z);
    printf("--------------------\n");

    // declaring pointers
    int *p; // similar: int* p, int * p
    int* m1, m2, m3; // a pointer m1 and a variable m2
    m2 = 5;
    m3 = m2;
    m1 = &m2;
    printf("*m1 = %d\nm2 = %d\nm3 = %d\n", *m1, m2, m3);
    m2 = 1;
    printf("new *m1 = %d\nnew m2 = %d\nnew m3 = %d\n", *m1, m2, m3);
    printf("--------------------\n");

    // what we did is that we changed the value of m2 and although *m1 is declared earlier, it changes its value, because *m1 is a pointer of m2
    // the pointer stores current value of a variable because it works not with variable's value but its location in the memory
    // if you give value of a variable to another variable (e.g: m = m1) and later you change the first variable, the second one will not change
    // meanwhile if you are using pointers (e.g: m = *m1), later you change variable's value (m), the pointer (*m1) also will change itself

    // change pointer's value
    int *ac, a=1, c=-15;
    ac = &a;
    printf("*ac = %d\n", *ac);
    ac = &c;
    printf("*ac = %d\n", *ac);
    printf("--------------------\n");


    // short example
    int * ptr,r;
    r = 5;
    *ptr = r;
    ptr = &r;
    // accessing value of 'r'
    printf("r = %d\n", r);
    printf("r = %d\n", *ptr);
    // accessing address of 'r'
    printf("address of r = %p\n", &r);
    printf("address of r = %p\n", ptr);
    printf("--------------------\n");

    // '*ptr = &r' is incorrect!
    // but why 'int *ptr = &r' is correct?
    // because it's equivalent to: 'int *prt, r;
    //                              prt = &r;  for address
    //                         or   *prt = r;'  for value

    // creating an empty pointer
    int * n = NULL;
    printf("empty pointer: %p\n", n);
}

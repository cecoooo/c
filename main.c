#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct Point{
    int x;
    int y;
};
typedef struct Point point;

typedef struct Car{
  char model[50];
  int year;
  char color[50];
  int hp;
}Car;

typedef struct Boat{
    int year;
    int price;
    char name[50];
    char color[50];
}Boat;

typedef struct Moto{
    int year;
    int engine;
    char* color;
}Moto;

typedef struct Plane{
    char size[50];
    int num_pass;
    int year;
}Plane;

typedef struct Vehicle{
    char* type;
    Car car;
    Boat boat;
    Moto moto;
    Plane plane;
}Vehicle;

void ex1();
void ex2();
void ex3();
// 4ex is extra
void ex4();

int main() {
    int ex=0;
    do {
        printf("Enter exercise:");
        scanf("%d", &ex);
        switch (ex) {
            case 1: printf("------ex1------\n"); ex1(); break;
            case 2: printf("------ex2------\n"); ex2(); break;
            case 3: printf("------ex3------\n"); ex3(); break;
            case 4: printf("------ex4------\n"); ex4(); break;
        }
    }while(ex!=FALSE);
}

void ex1(){
    point *a;
    a = (point*)malloc(3*sizeof(point));
    for (int i = 0; i < 3; ++i) {
        printf("Enter %c coordinates:", i+65);
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    double area=0., ab=0., ac=0., bc=0.;
    area = abs(0.5*(a[0].x*(a[1].y - a[2].y) + a[1].x*(a[2].y - a[0].y) + a[2].x*(a[0].y - a[1].y)));
    ab = sqrt(pow(a[0].x-a[1].x, 2) + pow(a[0].y-a[1].y, 2));
    ac = sqrt(pow(a[0].x-a[2].x, 2) + pow(a[0].y-a[2].y, 2));
    bc = sqrt(pow(a[2].x-a[1].x, 2) + pow(a[2].y-a[1].y, 2));
    printf("\nArea: %g\nAB = %g\nAC = %g\nBC = %g\n", area, ab, ac, bc);
    free(a);
}

void car(Vehicle *vehicle,Vehicle vehcl, int *count){
    printf("Enter model:");
    scanf(" %s", vehcl.car.model);
    printf("Enter year:");
    scanf(" %d", &vehcl.car.year);
    printf("Enter color:");
    scanf(" %s", vehcl.car.color);
    printf("Enter horsepower:");
    scanf(" %d", &vehcl.car.hp);
    *(vehicle+*count) = vehcl;
    ++(*count);
}

void boat(Vehicle* vehicle, Vehicle vehcl, int *count){
    printf("Enter boat's name:");
    scanf(" %s", vehcl.boat.name);
    printf("Enter year:");
    scanf(" %d", &vehcl.boat.year);
    printf("Enter price:");
    scanf(" %d", &vehcl.boat.price);
    printf("Enter color:");
    scanf(" %s", vehcl.boat.color);
    *(vehicle+*count) = vehcl;
    ++(*count);
}

void plane(Vehicle* vehicle, Vehicle vehcl, int *count){
    printf("Enter plane's size:");
    scanf(" %s", vehcl.plane.size);
    printf("Enter number of passengers:");
    scanf(" %d", &vehcl.plane.num_pass);
    printf("Enter year:");
    scanf(" %d", &vehcl.plane.year);
    *(vehicle+*count) = vehcl;
    ++(*count);
}

void moto(Vehicle* vehicle, Vehicle vehcl, int *count){
    printf("Enter year:");
    scanf(" %d", &vehcl.moto.year);
    printf("Enter cubature:");
    scanf(" %d", &vehcl.moto.engine);
    printf("Enter color:");
    scanf(" %s", vehcl.moto.color);
    *(vehicle+*count) = vehcl;
    ++(*count);
}

void ex2(){
    Vehicle* vehicle, vehcl;
    vehicle = (Vehicle*)calloc(50, sizeof(Vehicle));
    int count=0;
    do {
        printf("Enter vehicle:");
        vehcl.type = (char*)calloc(50, sizeof(char));
        scanf("%s", vehcl.type);
        if(!strcmp(vehcl.type, "stop")) break;
        else if(!strcmp(vehcl.type, "car")){
            car(vehicle, vehcl, &count);
        }
        else if(!strcmp(vehcl.type, "boat")){
            boat(vehicle, vehcl, &count);
        }
        else if(!strcmp(vehcl.type, "plane")){
            plane(vehicle, vehcl, &count);
        }
        else if(!strcmp(vehcl.type, "motorcycle")){
            moto(vehicle, vehcl, &count);
        }
    }while(TRUE);
    printf("\n");
    for (int i = 0; i < count; ++i) {
        printf("%s\n", vehicle[i].type);
        if(!strcmp(vehicle[i].type, "car")){
            printf("model: %s\n", vehicle[i].car.model);
            printf("year: %d\n", vehicle[i].car.year);
            printf("color: %s\n", vehicle[i].car.color);
            printf("horsepower: %d\n\n", vehicle[i].car.hp);
        }
        else if(!strcmp(vehicle[i].type, "boat")){
            printf("boat's name: %s\n", vehicle[i].boat.name);
            printf("year: %d\n", vehicle[i].boat.year);
            printf("price: %d$\n",vehicle[i].boat.price);
            printf("color: %s\n\n", vehicle[i].boat.color);
        }
        else if(!strcmp(vehicle[i].type, "motorcycle")){
            printf("year: %d\n", vehicle[i].moto.year);
            printf("cubature: %d\n", vehicle[i].moto.engine);
            printf("color: %s\n\n",vehicle[i].moto.color);
        }
        else if(!strcmp(vehicle[i].type, "plane")){
            printf("size: %s\n", vehicle[i].plane.size);
            printf("number of passengers: %d\n", vehicle[i].plane.num_pass);
            printf("year: %d\n\n",vehicle[i].plane.year);
        }
    }
    free(vehicle);
}

void ex3(){

}

void ex4(){
    Car car, *carr;
    carr = (Car*)calloc(50, sizeof(Car));
    int count=0;
    do {
        printf("Enter model:");
        scanf(" %s", car.model);
        if(!strcmp("stop", car.model)) break;
        printf("Enter year:");
        scanf(" %d", &car.year);
        while (getchar() != '\n');
        printf("Enter color:");
        scanf(" %s", car.color);
        if(!strcmp("stop", car.color)) break;
        printf("Enter horsepower:");
        scanf(" %d", &car.hp);
        if(car.hp==0) break;
        carr[count] = car;
        ++count;
    }while(TRUE);
    carr = (Car*)realloc(carr, count*sizeof(Car));
    printf("-----------------\n");
    for (int i = 0; i < count; ++i) {
        printf("car %d", i);
        printf("model: %s\n", carr[i].model);
        printf("year: %d\n", carr[i].year);
        printf("color: %s\n", carr[i].color);
        printf("horsepower: %d\n\n", carr[i].hp);
    }
    free(carr);
}
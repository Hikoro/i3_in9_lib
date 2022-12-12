#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"
#include "random.c"

int main(int argc, char*argv[]){
    //3.1 : A
    srand(time(NULL));
    double valRandomDouble = random_double(1.0,3.0);
    printf("%lf\n",valRandomDouble);
    valRandomDouble = random_double(10.0,1.0);
    printf("%lf\n",valRandomDouble);
    valRandomDouble = random_double(1.00,1.00);
    printf("%lf\n",valRandomDouble);

    printf("\n");

    //3.1 : B
    float valRandomFloat = random_float(1.0f,3.0f);
    printf("%f\n",valRandomFloat);
    valRandomFloat = random_float(10.0f,3.0f);
    printf("%f\n",valRandomFloat);
    valRandomFloat = random_float(10.0f,10.0f);
    printf("%f\n",valRandomFloat);
    valRandomFloat = random_float(-10.0f,10.0f);
    printf("%f\n",valRandomFloat);

    printf("\n");

    //3.1 : C
    size_t valRandomSize_t = random_size_t(1,40);
    printf("%lu\n",valRandomSize_t);
    valRandomSize_t = random_size_t(10,3.0);
    printf("%lu\n",valRandomSize_t);
    valRandomSize_t = random_size_t(10,10);
    printf("%lu\n",valRandomSize_t);
    valRandomSize_t = random_size_t(-10,10);
    printf("%lu\n",valRandomSize_t);

    printf("\n");

    //3.1 : D
    int valRandomInt = random_int(1,40);
    printf("%d\n",valRandomInt);
    valRandomInt = random_int(1,3.0);
    printf("%d\n",valRandomInt);
    valRandomInt = random_int(10,10);
    printf("%d\n",valRandomInt);
    valRandomInt = random_int(-10,10);
    printf("%d\n",valRandomInt);

    printf("\n");

    char valRandomChar = random_char('a','b');
    printf("%c\n",valRandomChar);
    valRandomChar = random_char('a','a');
    printf("%c\n",valRandomChar);
    valRandomChar = random_char('!','(');
    printf("%c\n",valRandomChar);
    valRandomChar = random_char('9','1');
    printf("%c\n",valRandomChar);

    printf("\n");

    char* c = malloc(sizeof(char)*10);
    random_init_string(c, 1);
    printf("%s\n",c);
    random_init_string(c, 5);
    printf("%s\n",c);
    random_init_string(c, 10);
    printf("%s\n",c);
    free(c);

    return 0;
}

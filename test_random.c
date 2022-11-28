#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

int main(int argc, char*argv[]){
    //3.1 : A
    srand(time(NULL));
    double valRandomDouble = random_double(1.0,3.0);
    printf("%lf\n",valRandomDouble);
    valRandomDouble = random_double(10.0,1.0);
    printf("%lf\n",valRandomDouble);
    valRandomDouble = random_double(1.00,1.00);
    printf("%lf\n",valRandomDouble);

    //3.1 : B
    float valRandomFloat = random_float(1.0f,3.0f);
    printf("%f\n",valRandomFloat);
    valRandomFloat = random_float(10.0f,3.0f);
    printf("%f\n",valRandomFloat);
    valRandomFloat = random_float(10.0f,10.0f);
    printf("%f\n",valRandomFloat);
    
    //3.1 : B
    size_t valRandomSize_t = random_size_t(1,3);
    printf("%lu\n",valRandomSize_t);
    valRandomSize_t = random_size_t(10,3.0);
    printf("%lu\n",valRandomSize_t);
    valRandomSize_t = random_size_t(10,10);
    printf("%lu\n",valRandomSize_t);
    valRandomSize_t = random_size_t(-10,10);
    printf("%lu\n",valRandomSize_t);
    return 0;
}

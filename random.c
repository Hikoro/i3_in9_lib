#include "random.h"
#include <stdlib.h>

/*
#include <stdio.h>
#include <time.h>
#include <math.h>
*/

double random_double(double a, double b){
    double borneMin, borneMax;
    if (a == b) // pour éviter que a et b soient identiques
    {
        printf("Erreur : a et b ont des valeurs identiques\n");
        return -1;
    }
    
    if (a<b) // interchangement si la deuxième valeur est plus petite que la première 
    {
        borneMin = a;
        borneMax = b;   
    }

    if (a>b)
    {
        borneMin = b;
        borneMax = a;
    }

    double val = (double)rand()/RAND_MAX*(borneMax-borneMin)+borneMin; // création d'une valeur aléatoire entre a et b exclu en double 
    return val;
}

float random_float(float a, float b){
    float borneMin, borneMax;
    if (a == b) // pour éviter que a et b soient identiques
    {
        printf("Erreur : a et b ont des valeurs identiques\n");
        return -1;
    }
    
    if (a<b) // interchangement si la deuxième valeur est plus petite que la première 
    {
        borneMin = a;
        borneMax = b;   
    }

    if (a>b)
    {
        borneMin = b;
        borneMax = a;
    }

    float val = (float)rand()/RAND_MAX*(borneMax-borneMin)+borneMin; // création d'une valeur aléatoire entre a et b exclu en float 
    //float val = rand()/(float) RAND_MAX*(borneMax-borneMin)+borneMin; 
    return val;
}

size_t random_size_t(size_t a, size_t b){
    size_t borneMin, borneMax;
    if ((a == b) || (a<0) || (b<0)) // pour éviter que a et b soient identiques PB ICI POUR <0
    {
        printf("Erreur : valeurs interdites\n");
        return 0;
    }
    
    if (a<b) // interchangement si la deuxième valeur est plus petite que la première 
    {
        borneMin = a;
        borneMax = b;   
    }

    if (a>b)
    {
        borneMin = b;
        borneMax = a;
    }

    size_t val = (size_t)rand()%(borneMax-borneMin)+borneMin; // création d'une valeur aléatoire entre a et b exclu en double 
    return val;
}

int random_int(int a, int b){

}

char random_char(char a, char b){

}

void random_init_string(char * c, size_t n){

}


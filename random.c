#include "random.h"
#include <stdlib.h>

double random_double(double a, double b){
    if(b>a)
    {
        double c =a;
        a = b;
        b = c;
    }
    return ((double)rand()/(double)RAND_MAX)*(a-b)+b;
}

float random_float(float a, float b){
     if(b>a)
    {
        float c =a;
        a = b;
        b = c;
    }
    return ((float) rand() / (float) RAND_MAX)*(a-b)+b;
}

size_t random_size_t(size_t a, size_t b){
    if(b>a)
    {
        size_t c =a;
        a = b;
        b = c;
    }
    return (size_t) (rand() % (a-b))+b;
}

int random_int(int a, int b){
    if(b>a)
    {
        int c =a;
        a = b;
        b = c;
    }
    return (int) (rand() % (a-b))+b;
}

char random_char(char a, char b){
    if(b>a)
    {
        char c =a;
        a = b;
        b = c;
    }
    return (char) (rand() % (a-b))+b;
}

void random_init_string(char * c, size_t n){
    for(int i=0; i<n; i++)
        c[i] = random_char('A','[');
}


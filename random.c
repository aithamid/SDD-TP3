#include "random.h"
#include <stdlib.h>

// renvoie un nombre aleatoire de type double entre a et b
double random_double(double a, double b){
    // si le deuxieme parametre est plus grand que le premier
    if(b>a)
    {
        double c =a;
        a = b;
        b = c;
    }
    // division d un nombre aleatoire par le maximum de sa valeur puis le multiplier par la difference des deux bornes, puis on a joute le plus petit
    return ((double)rand()/(double)RAND_MAX)*(a-b)+b;
}

// renvoie un nombre aleatoire de type float entre a et b
float random_float(float a, float b){
    // si le deuxieme parametre est plus grand que le premier
    if(b>a)
    {
        float c =a;
        a = b;
        b = c;
    }
    // division d un nombre aleatoire par le maximum de sa valeur puis le multiplier par la difference des deux bornes, puis on a joute le plus petit
    return ((float) rand() / (float) RAND_MAX)*(a-b)+b;
}

// renvoie un nombre aleatoire de type size_t entre a et b
size_t random_size_t(size_t a, size_t b){
    // si le deuxieme parametre est plus grand que le premier
    if(b>a)
    {
        size_t c =a;
        a = b;
        b = c;
    }
    //reste de la division d un nombre aleatoire par la difference des deux bornes, ensuite on ajoute le plus petit 
    return (size_t) (rand() % (a-b))+b;
}

// renvoie un nombre aleatoire de type int entre a et b
int random_int(int a, int b){
    // si le deuxieme parametre est plus grand que le premier
    if(b>a)
    {
        int c =a;
        a = b;
        b = c;
    }
    //reste de la division d un nombre aleatoire par la difference des deux bornes, ensuite on ajoute le plus petit 
    return (int) (rand() % (a-b))+b;
}

// renvoie un caractere aleatoire de type char entre a et b
char random_char(char a, char b){
    // si le deuxieme parametre est plus grand que le premier
    if(b>a)
    {
        char c =a;
        a = b;
        b = c;
    }
    return (char) (rand() % (a-b))+b;
}

// renvoie un caractere aleatoire de type char entre a et b
void random_init_string(char * c, size_t n){
    for(size_t i=0; i<n; i++)
        c[i] = random_char('A','[');
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

int main(){
    srand(time(NULL));
    time_t t;
    srand((unsigned) time(&t));
    printf("random_int : %d\n",random_int(4,10));
    printf("random_char : %c\n",random_char('B','D'));
    printf("random_size_t : %zu\n",random_size_t(4,9));
    printf("random_double : %lf\n",random_double(5.00,10.00));
    printf("random_float : %f\n",random_float(5.00,10.00));
    size_t n=5;
    char * c = malloc(sizeof(char)*n);
    random_init_string(c,n);
    printf("random_init_string : %s\n",c);
    return 0;
    
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

int main(int argc, char*argv[]){
    srand(time(NULL));
    time_t t;
    srand((unsigned) time(&t));
    printf("%d\n",random_int(4,10));
    printf("%c\n",random_char('B','D'));
    printf("%d\n",random_size_t(4,9));
    printf("%f\n",random_double(5.00,10.00));
    printf("%f\n",random_float(5.00,10.00));
    double X=((double)rand()/(double)RAND_MAX);
    printf("%lf",X);
    return 0;
    
}

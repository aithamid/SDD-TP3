#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

p_s_vector vector_alloc(size_t n){
    
	p_s_vector p_vector = malloc(sizeof(p_s_vector));
	p_vector->tab = malloc(sizeof(double)*n);
    	for(size_t i=0;i<n;i++)
    	{
        	p_vector->tab[i]=0.0;
        	p_vector->nbelement++;
    	}

    	return p_vector;

}

void vector_free(p_s_vector p_vector){
	free(p_vector->tab);
	free(p_vector);

}

void vector_set(p_s_vector p_vector, size_t i, double v){
	p_vector->tab[i]=v;
}

void vector_get(p_s_vector p_vector, size_t i, double * pv){
	*pv= p_vector->tab[i];
}

void vector_insert(p_s_vector p_vector, size_t i, double v){
    p_vector->nbelement++;
    double stock = v;
    p_vector->tab=(double *) realloc(p_vector->tab, sizeof(double) * p_vector->nbelement);
    for(size_t j=i; j<(p_vector->nbelement);j++)
    {
        double tmp=stock;
        stock=p_vector->tab[j];
        p_vector->tab[j]=tmp;
    }
}

void vector_erase(p_s_vector p_vector, size_t i){

    //deplacement de toutes les cases de 1
	p_vector->nbelement--;
	for(size_t j=i;j<p_vector->nbelement;j++){
		p_vector->tab[j]=p_vector->tab[j+1];
	}
	p_vector->tab=(double *) realloc(p_vector->tab, sizeof(double) * p_vector->nbelement);
}

void vector_push_back(p_s_vector p_vector, double v){
	p_vector->nbelement++;
	p_vector->tab=(double *) realloc(p_vector->tab, sizeof(double) * p_vector->nbelement);
	p_vector->tab[p_vector->nbelement-1]=v;

}

void vector_pop_back(p_s_vector p_vector){
	p_vector->nbelement--;
	p_vector->tab=(double *) realloc(p_vector->tab, sizeof(double) * p_vector->nbelement);
}

void vector_clear(p_s_vector p_vector){
	free(p_vector->tab);	
	p_vector->tab = NULL;
	p_vector->nbelement = 0;
}

int vector_empty(p_s_vector p_vector){
	if(p_vector->tab != NULL)
		return 0;
	return 1;
}

size_t vector_size(p_s_vector p_vector){
	return p_vector->nbelement;
}

void vector_display(p_s_vector p_vector)
{
	// State
	int res = vector_empty(p_vector);
	printf("State : ");
	if(res == 0){
		printf("(Not Empty) Size : %ld ", vector_size(p_vector));
	}
	else
		printf("(Empty) ");
	printf("Display : [ ");
	for(size_t i=0; i<p_vector->nbelement; i++)
	{
		if(p_vector->tab[i]==0)
			printf(RED "%0.2lf  "RESET, p_vector->tab[i]);
		else	
			printf(GREEN "%0.2lf  " RESET, p_vector->tab[i]);
	}
	printf("]\n");
}


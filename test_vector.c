#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


//int main(int argc, char *argv[])
int main()
{

	printf("TEST : Pour chaque changement on affiche avec la méthode vector_display\n");
	size_t l=rand()%11;

	printf("// VECTOR_ALLOC : on alloue un espace de %ld élements.\n", l);
	p_s_vector v = vector_alloc(l);

	vector_display(v);

	int pos = rand()%v->nbelement;
	double value = 3.0;
	printf("// VECTOR_SET : on initialise la %deme valeur du tableau donc, tab[%d] = %0.2lf.\n", pos+1, pos, value);
	vector_set(v, pos, value);
	vector_display(v);
	

	pos = rand()%v->nbelement;
	value = 2.0;
	printf("// VECTOR_INSERT : on insère à la valeur %lf à la %dème position du tableau.\n", value, pos+1);
	vector_insert(v, pos, value);
	vector_display(v);

	printf("// VECTOR_ERASE : on supprime à la valeur %lf à la %dème position du tableau.\n", value, pos+1);
	vector_erase(v, pos);
	vector_display(v);

	value = 3.33;
	printf("// VECTOR_PUSH_BACK : on insère à la valeur %lf à la fin du tableau.\n", value);
	vector_push_back(v, value);
	vector_display(v);

	printf("// VECTOR_POP_BACK : on supprime à la valeur %lf à la fin du tableau.\n", value);
	vector_pop_back(v);
	vector_display(v);
	
	printf("// VECTOR_CLEAR : on supprime toutes les valeurs.\n");
	vector_clear(v);
	vector_display(v);


	printf("// VECTOR_FREE : on libère la mémoire de v.\n");
	vector_free(v);
	
	return EXIT_SUCCESS;
}

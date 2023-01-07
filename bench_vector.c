#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "random.h"
#include "vector.h"

void insert_erase_random(size_t init_size, size_t n);
void insert_erase_head(size_t init_size, size_t n);
void insert_erase_tail(size_t init_size, size_t n);
void read_write_random(size_t init_size, size_t n);
void read_write_sequential(size_t init_size, size_t n);
void bubble_sort(size_t init_size, size_t n);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	// int value = strcmp(argv[1],"insert_erase_random");
	// printf("%d",value);
	if (argc != 4)
	{
		printf("Aide : %s test_type init_size n\n", argv[0]);
		printf("\ttest_type :\n\t\tinsert_erase_random \n\t\tinsert_erase_head \n\t\tinsert_erase_tail \n\t\tread_write_random \n\t\tread_write_sequential \n\t\tbubble_sort \n");
		return 0;
	}
	
	size_t init_size;
    sscanf(argv[2], "%zu", &init_size);
    size_t n;
    sscanf(argv[3], "%zu", &n);


	if (strcmp(argv[1], "insert_erase_random") == 0)
		insert_erase_random(init_size, n);
	if (strcmp(argv[1], "insert_erase_head") == 0)
		insert_erase_head(init_size, n);
	if (strcmp(argv[1], "insert_erase_tail") == 0)
		insert_erase_tail(init_size, n);
	if (strcmp(argv[1], "read_write_random") == 0)
		read_write_random(init_size, n);
	if (strcmp(argv[1], "read_write_sequential") == 0)
		read_write_sequential(init_size, n);
	if (strcmp(argv[1], "bubble_sort") == 0)
		bubble_sort(init_size, n);
	

	return 0;
}

// Ajoute et enleve a une position aleatoire de vector une valeur aleatoire
void insert_erase_random(size_t init_size, size_t n)
{
	p_s_vector v = vector_alloc(init_size);
	int pos = rand() % v->nbelement;
	for (int i = 0; i < (int)n; i++)
	{
		if (v->nbelement == 0)
		{
			return;
		}
		double nb_double = random_double(1.00, (double)n);
		printf("first : ");
		vector_display(v);
		printf("\n");
		vector_insert(v, pos, nb_double);
		printf("second : ");
		vector_display(v);
		printf("\n");
		pos = rand() % v->nbelement;
		vector_erase(v, pos);
		printf("third : ");
		vector_display(v);
		printf("\n");
	}
}

// Ajoute et enleve en tete de vector une valeur aleatoire
void insert_erase_head(size_t init_size, size_t n)
{
	p_s_vector v = vector_alloc(init_size);
	int pos = 0;
	for (int i = 0; i < (int)n; i++)
	{
		if (v->nbelement == 0)
		{
			return;
		}
		double nb_double = random_double(1.00, (double)n);
		printf("first : ");
		vector_display(v);
		printf("\n");
		vector_insert(v, pos, nb_double);
		printf("insert : ");
		vector_display(v);
		printf("\n");
		vector_erase(v, pos);
		printf("erase : ");
		vector_display(v);
		printf("\n");
	}
}

// Ajoute et enleve en queue de vector une valeur aleatoire
void insert_erase_tail(size_t init_size, size_t n)
{
	p_s_vector v = vector_alloc(init_size);

	for (int i = 0; i < (int)n; i++)
	{
		double nb_double = random_double(1.00, (double)n);
		printf("first : ");
		vector_display(v);
		printf("\n");
		vector_push_back(v, nb_double);
		printf("insert : ");
		vector_display(v);
		printf("\n");
		vector_pop_back(v);
		printf("erase : ");
		vector_display(v);
		printf("\n");
	}
}

// Recupere la valeur a une position aleatoire et l incremente de 1
void read_write_random(size_t init_size, size_t n)
{
	p_s_vector v = vector_alloc(init_size);
	int pos = rand() % v->nbelement;
	for (int i = 0; i < (int)n; i++)
	{
		if (v->nbelement == 0)
		{
			return;
		}
		double stock;
		vector_get(v, pos, &stock);
		stock += 1;
		vector_set(v, pos, stock);
		printf("Ajout a la position : %d a la valeur %.1f \n ", pos, stock);
		vector_display(v);
		printf("\n");
		pos = rand() % v->nbelement;
	}
}

// Recupere chaque valeur de vector et l incremente de 1
void read_write_sequential(size_t init_size, size_t n)
{
	p_s_vector v = vector_alloc(init_size);
	for (int i = 0; i < (int)n; i++)
	{
		for (int j = 0; j < v->nbelement; j++)
		{
			double stock;
			vector_get(v, j, &stock);
			stock += 1;
			vector_set(v, j, stock);
			printf("Ajout a la position : %d a la valeur %.1f \n ", j, stock);
			vector_display(v);
			printf("\n");
		}
	}
}

void bubble_sort(size_t init_size, size_t n)
{
	// p_s_vector v = vector_alloc(init_size);
	// vector_display(v);
	// int size_decrement = v->nbelement - 1;
	// for (int i = 0; i < (int)n; i++)
	// {

	// 	while (size_decrement != 0)
	// 	{
	// 		for (int j = 0; j < size_decrement; j++)
	// 		{
	// 			double stock, stock2;
	// 			vector_get(v, j, &stock);
	// 			vector_get(v, j + 1, &stock2);
	// 			if (stock > stock2)
	// 			{
	// 				vector_set(v, j, stock2);
	// 				vector_set(v, j + 1, stock);
	// 				printf("Changement de position: %d a la valeur %.1f \n ", j, stock);
	// 			}

	// 			vector_display(v);
	// 			printf("\n");
	// 		}
	// 		size_decrement--;
	// 	}
	// }
}

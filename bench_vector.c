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

int main(int argc, char*argv[]){
	srand(time(NULL));

	insert_erase_random(5,5);
	
	if(argc != 4){
		printf("Aide : %s test_type init_size n\n", argv[0]);
		printf("\ttest_type :\n\t\tinsert_erase_random \n\t\tinsert_erase_head \n\t\tinsert_erase_tail \n\t\tread_write_random \n\t\tread_write_sequential \n\t\tbubble_sort \n");
		return 0;
	}

	return 0;
}

void insert_erase_random(size_t init_size, size_t n){
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		vector_insert(p_vector, random_size_t(0, init_size), random_double((double)rand(), (double)rand()));
		vector_erase(p_vector, random_size_t(0, init_size+1));
	}
	vector_free(p_vector);
}

void insert_erase_head(size_t init_size, size_t n){
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		vector_push_back(p_vector, random_double((double)rand(), (double)rand()));
		vector_pop_back(p_vector);
	}
	vector_free(p_vector);
}

void insert_erase_tail(size_t init_size, size_t n){
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		vector_insert(p_vector, 0, random_double((double)rand(), (double)rand()));
		vector_erase(p_vector, 0);
	}
	vector_free(p_vector);
}

void read_write_random(size_t init_size, size_t n){
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		double value;
		size_t index = random_size_t(0, init_size);
		vector_get(p_vector, index, &value);
		value++;
		vector_set(p_vector, index, value);
	}
	vector_free(p_vector);
}

void read_write_sequential(size_t init_size, size_t n){
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = n; i > 0; i--)
	{
		double value;
		vector_get(p_vector, i, &value);
		value++;
		vector_set(p_vector, i, value);
	}
	vector_free(p_vector);
}

void bubble_sort(size_t init_size, size_t n){
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		double value = random_double((double)rand(), (double)rand());
		vector_set(p_vector, i, value);
	}
	for(int i = 0; i < init_size-1; i++)
	{
		for(int j = i; j < init_size-1; j++)
		{
			if(p_vector->p[i] > p_vector->p[j+1])
			{
				double interValue = p_vector->p[i];
				p_vector->p[i] = p_vector->p[j+1];
				p_vector->p[j+1] = interValue;
			}
		}
	}
	vector_free(p_vector);
}

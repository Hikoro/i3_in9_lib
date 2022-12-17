#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "random.h"
#include "vector.h"



int main(int argc, char*argv[])
{
	srand(time(NULL));

	// On regarde le nombre de valeurs en argument, il en faut 3 obligatoirement
	if(argc != 4){
		printf("Nombre d'arguments invalide !\n");
		printf("Aide : %s test_type init_size n\n", argv[0]);
		printf("\ttest_type :\n\t\tinsert_erase_random \n\t\tinsert_erase_head \n\t\tinsert_erase_tail \n\t\tread_write_random \n\t\tread_write_sequential \n\t\tbubble_sort \n");
		return 0;
	}
	else{
		// on a changé le size_t en int car quand le size_t reçoit un nombre négatif, il le change en un nombre erreur aléatoire positif
		int init_size;
		int n;
		int resultat;

		sscanf(argv[2],"%u",&init_size);
		sscanf(argv[3],"%u",&n);
		

		// on regarde si la taille du vecteur et le nombre d'itération est correct
		if (init_size>0 && n>0 && init_size != NULL && n != NULL)
		{
			// si le premier argument et la chaine de caractère sont identiques, resultat reçoit 0, sinon il reçoit une autre valeur et on compare avec une autre chaine de caractères
			resultat = strcmp(argv[1],"insert_erase_random");
			if (resultat == 0)
			{
				insert_erase_random(init_size,n);
			}

			else
			{
				resultat = strcmp(argv[1],"insert_erase_head");
				if (resultat == 0)
				{
					insert_erase_head(init_size,n);
				}	

				else
				{
					resultat = strcmp(argv[1],"insert_erase_tail");
					if (resultat == 0)
					{
						insert_erase_tail(init_size,n);
					}
					else
					{
						resultat = strcmp(argv[1],"read_write_random");
						if (resultat == 0)
						{
							read_write_random(init_size,n);
						}
						else
						{
							resultat = strcmp(argv[1],"read_write_sequential");
							if (resultat == 0)
							{
								read_write_sequential(init_size,n);
							}
							else
							{
								resultat = strcmp(argv[1],"bubble_sort");
								if (resultat == 0)
								{
									bubble_sort(init_size,n);
								}
								else
								{
									printf("Premier argument erroné! \n");
								}
								
							}
							
						}
						
					}
					
				}
				
			}
		}
		else
		{
			printf("Le deuxième ou troisième argument sont négatifs ou nuls! \n");
		}
		
		
		
	}
	return 0;
}

void insert_erase_random(size_t init_size, size_t n);
void insert_erase_head(size_t init_size, size_t n);
void insert_erase_tail(size_t init_size, size_t n); 
void read_write_random(size_t init_size, size_t n); 
void read_write_sequential(size_t init_size, size_t n); 
void bubble_sort(size_t init_size, size_t n);

// Fonction pour afficher le vecteur
void afficheTab(p_s_vector vector){
	if (vector->nb==0 || vector->nb == NULL)
	{
		printf("tableau vide");
	}
	else{
		for(int i = 0; i<vector->nb;i++){
			printf("%lf ",vector->p[i]);
		}
	}
	printf("\n");
}

// Fonction  qui insère et retire un élément aléatoire du tableau 
void insert_erase_random(size_t init_size, size_t n)
{
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		// insertion d'un élément
		vector_insert(p_vector, random_size_t(0, init_size), random_double((double)rand(), (double)rand()));
		// effacement d'un élément
		vector_erase(p_vector, random_size_t(0, init_size+1));
	}
	afficheTab(p_vector);
	vector_free(p_vector);
}

// Fonction qui ajoute et retire un élément en tête n fois
void insert_erase_head(size_t init_size, size_t n)
{
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		// on ajoute le dernier élément
		vector_push_back(p_vector, random_double((double)rand(), (double)rand()));
		// on retire le dernier élément
		vector_pop_back(p_vector);
	}
	afficheTab(p_vector);
	vector_free(p_vector);
}

// Fonction qui ajoute et retire un élément en queue n fois
void insert_erase_tail(size_t init_size, size_t n)
{
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		// on ajoute un élément en première position
		vector_insert(p_vector, 0, random_double((double)rand(), (double)rand()));
		// on retire un élément en première position
		vector_erase(p_vector, 0);
	}
	afficheTab(p_vector);
	vector_free(p_vector);
}

// Fonction qui lis une valeur du vecteur et l'incrémente de 1 puis la place dans le vecteur n fois
void read_write_random(size_t init_size, size_t n)
{
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = 0; i < n; i++)
	{
		double value;
		// index aléatoire du vecteur
		size_t index = random_size_t(0, init_size);
		// obtention d'une valeur par rapport à l'indice du vecteur
		vector_get(p_vector, index, &value);
		value++;
		// remplacement de la valeur incrémentée au même index
		vector_set(p_vector, index, value);
	}
	afficheTab(p_vector);
	vector_free(p_vector);
}

// Fonction qui lis une valeur du vecteur et l'incrémente de 1 puis la place dans le vecteur de l'indice le plus haut vers l'indice le plus bas (0)
void read_write_sequential(size_t init_size, size_t n)
{
	p_s_vector p_vector = vector_alloc(init_size);
	for(int i = n; i >= 0; i--)
	{
		double value;
		vector_get(p_vector, i, &value);
		// obtention d'une valeur par rapport à l'indice du vecteur
		value++;
		// remplacement de la valeur incrémentée au même index
		vector_set(p_vector, i, value);
	}
	afficheTab(p_vector);
	vector_free(p_vector);
}

// Fonction qui range dans l'ordre croissante les éléments du vecteur (trie à bulles)
void bubble_sort(size_t init_size, size_t n)
{
	p_s_vector p_vector = vector_alloc(init_size);

	// on met des valeurs aléatoires dans le tableau n fois
	for(int i = 0; i < n; i++)
	{
		double value = random_double((double)rand(), (double)rand());
		vector_set(p_vector, i, value);
	}

	// On effectue le tri en comparant chaque élément du tableau entre eux
	for(int i = 0; i < init_size-1; i++)
	{
		for(int j = i; j < init_size-1; j++)
		{
			// si la valeur d'après est plus petite que la valeur actuelle, on échange les places entre les deux
			if(p_vector->p[i] > p_vector->p[j+1])
			{
				double interValue = p_vector->p[i];
				p_vector->p[i] = p_vector->p[j+1];
				p_vector->p[j+1] = interValue;
			}
		}
	}
	afficheTab(p_vector);
	vector_free(p_vector);
}

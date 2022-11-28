#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char *argv[]){
	// EXO A
	printf("Fonction vector_alloc : \n");
	p_s_vector pvector = (p_s_vector)malloc(sizeof(s_vector));
	pvector = vector_alloc(5);
	afficheTab(pvector);

	// EXO C
	// 1)
	printf("\nFonction vector_set : \n");
	vector_set(pvector,10,1); // test valeur impossible
	vector_set(pvector,4,1); // test valeur possible
	afficheTab(pvector);
	// 2)
	printf("\nFonction vector_get : \n");
	double pv;
	vector_get(pvector,10,&pv); // test valeur impossible
	vector_get(pvector,4,&pv); // test valeur possible
	printf("pv possède comme valeur : %lf\n",pv);

	// EXO D
	printf("\nFonction vector_insert : \n");
	vector_insert(pvector,10,2); // test valeur impossible
	vector_insert(pvector,2,2); // test valeur possible
	vector_insert(pvector,0,2); // test valeur possible
	vector_insert(pvector,7,2); // test valeur possible
	afficheTab(pvector);

	// EXO E
	printf("\nFonction vector_erase : \n");
	vector_erase(pvector,10); // test valeur impossible
	vector_erase(pvector,2); // test valeur possible
	vector_erase(pvector,0); // test valeur possible
	vector_erase(pvector,5); // test valeur possible
	afficheTab(pvector);

	// EXO F
	printf("\nFonction vector_push_back : \n");
	vector_push_back(pvector,5);
	afficheTab(pvector);

	// EXO G
	printf("\nFonction vector_pop_back : \n");
	vector_pop_back(pvector);
	afficheTab(pvector);

	// EXO H
	printf("\nFonction vector_clear : \n");
	vector_clear(pvector);
	afficheTab(pvector);

	// EXO I
	printf("\nFonction vector_empty : \n");
	interrogationVectorVide(pvector);
	vector_push_back(pvector,10);
	interrogationVectorVide(pvector);
	afficheTab(pvector);

	//EXO J
	printf("\nFonction vector_size : \n");
	size_t nbElement = vector_size(pvector);

	// EXO B
	printf("\nFonction vector_free : \n");
	vector_free(pvector);

	return EXIT_SUCCESS;
}

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

void interrogationVectorVide(p_s_vector pvector){
	int vide = vector_empty(pvector);

	if (vide == 1)
	{
		printf("le tableau est vide\n");
	}
	else
	{
		printf("le tableau contient des valeurs\n");
	}
}
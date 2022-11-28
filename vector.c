#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

p_s_vector vector_alloc(size_t n){
    if(n>=0){
        p_s_vector vector = (p_s_vector)malloc(sizeof(s_vector)); //allocation de vector, un nouveau pointeur de la structure vector
        vector->p = (double*)malloc((n)*sizeof(double)); //allocation du tableau de double par rapport à n
        for (int i = 0; i < n; i++) //remplissage du tableau p en attribuant 0.0 pour chaque emplacement
        {
            vector->p[i] = 0.0;
        }
        vector->nb = n;//paramétrage du nombre de valeurs 
        return vector;
    }

    
}

void vector_free(p_s_vector p_vector){
    free((p_vector)->p);//libération de la mémoire du tableau du vecteur
    free(p_vector);//libération du vecteur
    p_vector = NULL;//mise à NULL du vecteur
    printf("mémoire de vector libérée\n");
}

void vector_set(p_s_vector p_vector, size_t i, double v){
    if (p_vector->nb>i && i>=0)//pour éviter que i soit un indice qui n'existe pas dans le tableau
    {
        p_vector->p[i] = v;
    }
    else
    {
        printf("L'indice %d n'existe pas\n",i);
    }
    
    
}

void vector_get(p_s_vector p_vector, size_t i, double * pv){
    if (p_vector->nb>i && i>=0)//pour éviter que i soit un indice qui n'existe pas dans le tableau
    {
        *pv = p_vector->p[i];
    }
    else
    {
        printf("L'indice %d n'existe pas\n",i);
    }
}

void vector_insert(p_s_vector p_vector, size_t i, double v){

    if (p_vector->nb>=i && i>=0)//pour éviter que i soit un indice qui n'existe pas dans le tableau
    {
        p_vector->p = (double*)realloc(p_vector->p,sizeof(double)*p_vector->nb+1);// on réalloue le tableau avec une place en +

        for (int j = p_vector->nb - 1; j > i; j--)// on parcourt le tableau en décalant de +1 les valeurs jusqu'à l'indice i
        {
            p_vector->p[j+1] = p_vector->p[j];
        }
        p_vector->nb++;// on ajoute 1 au nombre d'élément

        p_vector->p[i] = v;// on place la nouvelle valeur dans l'indice libéré
        
    }
    else
    {
        printf("L'indice %d n'existe pas\n",i);
    }
}

void vector_erase(p_s_vector p_vector, size_t i){
    if (p_vector->nb>=i && i>=0)//pour éviter que i soit un indice qui n'existe pas dans le tableau
    {
        p_vector->p = (double*)realloc(p_vector->p,sizeof(double)*p_vector->nb-1);// on réalloue le tableau avec une place en -

        for (int j = i; j < p_vector->nb-1; j++)// on parcourt le tableau en décalant de -1 les valeurs de l'indice i jusqu'à la fin
        {
            p_vector->p[j] = p_vector->p[j+1];
        }
        p_vector->nb--;// on retire 1 au nombre d'élément
    }
    else
    {
        printf("L'indice %d n'existe pas\n",i);
    }
}

void vector_push_back(p_s_vector p_vector, double v){
    p_vector->p = (double*)realloc(p_vector->p,sizeof(double)*p_vector->nb+1);// on réalloue le tableau avec une place en +
    p_vector->nb++;// on ajoute 1 au nombre d'élément
    p_vector->p[p_vector->nb-1] = v;// on ajoute la valeur au nouvel indice
    
}

void vector_pop_back(p_s_vector p_vector){
    if(p_vector->nb != NULL && p_vector->nb != 0){//si le nombre de valeurs est supérieur à 0
        p_vector->p = (double*)realloc(p_vector->p,sizeof(double)*p_vector->nb-1);// on réalloue le tableau avec une place en -
        p_vector->nb--;// on retire 1 au nombre d'élément
    }

}

void vector_clear(p_s_vector p_vector){
    if(p_vector->nb != NULL && p_vector->nb != 0){//si le nombre de valeurs est supérieur à 0
        int nbVal = p_vector->nb;//on stocke le nombre de valeurs présentes dans le tableau avant la suppression
        for (int i = 0; i < nbVal; i++)// on supprime la dernière valeur du tableau pour chaque valeur présente dans le tableau
        {
            vector_pop_back(p_vector);
        }
        
    }
}

int vector_empty(p_s_vector p_vector){
    if (p_vector->nb==0 || p_vector->nb == NULL)//si le nombre de valeurs est 0 ou alors que la valeur n'a jamais été initialisé
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

size_t vector_size(p_s_vector p_vector){
    size_t nbElement = 0;
    if(vector_empty(p_vector) == 0)//si le nombre de valeurs est supérieur à 0
    {
        for (size_t i = 0; i < p_vector->nb; i++) // même chose que nbElement = p_vector->nb
        {
            nbElement++;
        }
        
    }
    printf("le nombre d'éléments du tableau est de %lu\n",nbElement);
    return nbElement;
    
}


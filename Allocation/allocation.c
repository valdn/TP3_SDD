
#include <stdio.h>
#include <stdlib.h>
#include "allocation.h"

void * allocation_mem(size_t nobjets,size_t taille){
	void * pt;
	pt = malloc(nobjets * taille);/*allocation*/
	/* on verifie si l’allocation a marche*/
	if (pt==NULL){
		printf("Impossible d’allouer la memoire %ld %ld\n",nobjets,taille);
	}
	return(pt);
}

void * allocation_mem_init0(size_t nobjets,size_t taille){
	void * pt;
	pt = calloc(nobjets,taille);/*allocation avec calloc*/
	/* on verifie si l’allocation a marche*/
	if (pt==NULL){
		printf("Impossible d’allouer la memoire %ld * %ld\n",nobjets,taille);
	}
	return(pt);
}

void* reallocation_mem(void **pt, size_t nobjets,size_t taille){
	void *pt_realloc = realloc(*pt, nobjets*taille);
	if (pt_realloc != NULL){
		*pt = pt_realloc;
	}
	else{
		printf("Impossible de reallouer la memoire %ld * %ld a l’adresse %p\n",nobjets,taille,*pt);
	}
	return pt_realloc;
}

void libere_mem(void *pt){
  void ** adr_pt=(void **) pt;
  if((*adr_pt)!=NULL){
    free(*adr_pt); /*liberation de *pt */
  }
  *adr_pt=NULL; /* *pt pointe maintenant sur NULL, cad rien*/
}


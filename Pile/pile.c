#include "pile.h"

/**
*Cette fonction permet l'initialisation d'une pile
*@param size  Taille de la pile à créer
*/

pile_t * init_Pile(int size){
    pile_t * currentPile = malloc(sizeof(pile_t));
    if (currentPile!=NULL){
        currentPile->size = size;
        currentPile->head = -1;
        currentPile->data = malloc(sizeof(piledata_t)*size);
    }
   return currentPile; 
}

/**
*Cette fonction permet de libérer la pile
*@param pile  Pile à libérer
*/

void free_Pile(pile_t *pile){
    free(pile->data);
    free(pile);
}

/**
*Cette fonction permet de vérifier et de retourner si la pile est vide ou non
*@param pile pile vide ou non
*/

int isEmpty(pile_t * pile){
    int compt;
    if (pile->head == -1){
        compt = 1;
    } else {
        compt = 0;
    }
    return compt;
}

/**
*Permet d'empiler une donnée dans la pile
*@param pile Pile courante
*@param val Donnée à ajouter à la pile
*/

void stack_Pile(pile_t * pile, piledata_t val){
    if (pile->head < pile->size-1){
        pile->head += 1;
        pile->data[pile->head] = val;
     } else {
        pile->data = realloc(pile->data, sizeof(piledata_t)*pile->size * 2);
        printf("Size of the Pile is too small, resizing\n");
        pile->size = pile->size * 2;
        pile->head += 1;
        pile->data[pile->head] = val;
        
    }
}

/**
*Permet de dépiler une donnée de la pile
*@param pile  Pile courante
*@param elem  Adresse de l'élèment retirer de la pile
*/

void unstack_Pile(pile_t * pile, piledata_t * adrV){
    if(!isEmpty(pile)){
        *adrV = pile->data[pile->head];
        pile->head -= 1;
    } else {
        adrV=NULL;
    }
}

/**
*Permet d'afficher le contenu de la pile
*@param pile  Pile courante
*/

void display_Pile(pile_t * pile){
    if(!isEmpty(pile)){
        printf("Size = %d\n", pile->size);
        printf("Head = %d\n", pile->head);
        for (int i = 0; i <= pile->head; i++)
        {
            display_Data(pile->data[i]->value);
        }
    }
}

int top (pile_t * pile, piledata_t * adrV){
    int state = 1;

    if(!isEmpty(pile)){
        *adrV = pile->data[0];
        state = 0;
    }
    return state;
}
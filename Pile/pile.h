#ifndef pile_h
#define PILE_H


#include <stdlib.h>
#include <stdio.h>

#include "data_Pile.h"

typedef struct Pile {
    int size;
    int head;
    piledata_t * data;
} pile_t;

pile_t * init_Pile(int size);
void free_Pile(pile_t * pile);
int isEmpty(pile_t * pile);
void stack_Pile(pile_t * pile, piledata_t val);
void unstack_Pile(pile_t * pile, piledata_t *elem);
void display_Pile(pile_t * pile);

#endif
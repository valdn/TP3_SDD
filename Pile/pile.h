#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdio.h>

#include "../Tree/tree.h"

typedef struct Pile {
    int size;
    int head;
    tree_t * data;
} pile_t;

pile_t * init_Pile(int size);
void free_Pile(pile_t * pile);
int isEmpty(pile_t * pile);
void stack_Pile(pile_t * pile, tree_t val);
void unstack_Pile(pile_t * pile, tree_t *prec);
void display_Pile(pile_t * pile);

#endif
#include <stdlib.h>
#include <stdio.h>

#include "specific_list.h"

typedef struct list {
    struct cellule_t * tete;
} list_t;

typedef struct cellule {
    data_t value;
    struct cellule * suiv;
} cellule_t

void display_List(list_t * list, char * path);
list_t * init_List();
void fill_List_with_k_Value(list_t * list, matrix_t * matrix, int k);
void free_List(list_t * list);
void add_Cell_in_List(list_t * prec, data_t value);
list_t * search_in_ListbyCell(list_t * list, data_t data);
void delete_Occurences(list_t * list, int factory);
void delete_in_List(list_t * tempList);

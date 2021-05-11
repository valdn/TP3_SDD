#ifndef specific_tree_h
#define SPECIFIC_TREE

#include <stdlib.h>
#include <stdio.h>

typedef struct treedata {
    char letter;
} treedata_t;

//void display_Data(treedata_t d, FILE * file);
treedata_t init_Data(int value, int factory, int period);
int equals_Data(treedata_t data1, treedata_t data2);
int equal_Factory(int value, treedata_t data2);

#endif

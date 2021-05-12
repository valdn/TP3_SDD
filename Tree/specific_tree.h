#ifndef SPECIFIC_TREE_H
#define SPECIFIC_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct treedata {
    char letter;
} treedata_t;

void display_Data(treedata_t d);
treedata_t init_Data(char letter);

#endif

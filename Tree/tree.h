#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

#include "specific_tree.h"
#include "../Pile/pile.h"

typedef struct tree {
    treedata_t value;
    struct tree * lv;
    struct tree * lh;
} tree_t;

tree_t * init_Tree();
void free_tree(tree_t * current);
void createTree(tree_t * tree, char* expression);
void displayDictionary(tree_t tree);
void add_node_in_Tree(tree_t * tree, treedata_t letter);

#endif

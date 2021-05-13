#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

#include "specific_tree.h"

typedef struct tree {
    treedata_t value;
    struct tree * lv;
    struct tree * lh;
} tree_t;

#include "../Pile/pile.h"

tree_t * init_Tree();
void free_tree(tree_t * current);
tree_t * createTree(char* expression);
tree_t * create_Node(char letter);
void display_Tree(tree_t * tree);
void displayDictionary(tree_t ** tree, char * word, int i);
void add_node_in_Tree(tree_t * tree, treedata_t letter);

void insert_word(tree_t ** tree, char * word);
void search_pattern(tree_t ** tree, char * motif);

tree_t ** search_prec_sort(tree_t **tree, char letter);

#endif

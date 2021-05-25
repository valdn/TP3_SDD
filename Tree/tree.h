             /**********************************************************/
             /*DI NARDO Valentin - VIELLARD Bruno                 2021 */
             /*--------------------------------------------------------*/
             /*                        tree.h                          */
             /*          Traitement de fonction spécifique de tree     */
             /*                   FONCTIONS SPECIFIQUES A TREE         */
             /**********************************************************/

#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "specific_tree.h"


typedef struct tree {
    treedata_t value;
    struct tree * lv;
    struct tree * lh;
} tree_t;

#include "../Pile/pile.h"

/**
*Initialisation de la tête de l'arbre 
*/
tree_t * init_Tree();

/**
*Permet de vider l'arbre
*@param current  Arbre courant à vider
*/
void free_tree(tree_t * current);

/**
*Création de l'arbre avec une expression
*@param expression Expression en entrée supposé sans erreur
*/
tree_t * createTree(char* expression);

/**
*Permet de créer un noeud
*@param letter lettre contenue dans le noeud
*/
tree_t * create_Node(char letter);

/**
*Affichage du contenu de l'arbre
*@param tree Arbre à afficher
*/
void display_Tree(tree_t * tree);

/**
*Permet d'afficher le dictionnaire exprimé par un arbre'
*@param tree Arbre duquel afficher le dictionnaire
*@param word Mot courant à afficher
*@param i entier pour parcourir le mot
*/
void displayDictionary(tree_t ** tree, char * word, int i);

/**
*Permet d'insérer un mot dans un arbre'
*@param tree Arbre duquel afficher le dictionnaire
*@param word Mot à insérer
*/
void insert_word(tree_t ** tree, char * word);

/**
*Permet d'afficher tout les mots débutant par un certains motif'
*@param tree Arbre duquel afficher les mots correspondants
*@param motif Motif
*/
void search_pattern(tree_t ** tree, char * motif);

/**
*Recherche un caractère et retourne un pointeur sur le précédent
*@param tree Arbre dans lequel faire la recherche
*@param letter Lettre à trouver dans l'arbre
*/
tree_t ** search_prec_sort(tree_t **tree, char letter);

#endif

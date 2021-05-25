             /**********************************************************/
             /*DI NARDO Valentin - VIELLARD Bruno                 2021 */
             /*--------------------------------------------------------*/
             /*                        specific_tree.h                     */
             /*          Traitement de fonction spécifique de liste    */
             /*                   FONCTIONS SPECIFIQUES A LISTE        */
             /**********************************************************/

#ifndef SPECIFIC_TREE_H
#define SPECIFIC_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct treedata {
    char letter;
} treedata_t;

/* -------------------------------------------------------------------- */
/* display_Data         Affiche la cellule rentrée en paramètre         */
/*                                                                      */
/* En entrée: d la cellule à afficher                                   */
/*                                                                      */
/* -------------------------------------------------------------------- */
void display_Data(treedata_t d);

/* -------------------------------------------------------------------- */
/* init_Tree_Data         Initialisation des valeurs de l'arbre         */
/*                                                                      */
/* En entrée: letter, le caractère à initialiser. En sortie la cellule */
/*                                                                      */
/* -------------------------------------------------------------------- */
treedata_t init_Data(char letter);

#endif

             /**********************************************************/
             /*DI NARDO Valentin - VIELLARD Bruno                 2021 */
             /*--------------------------------------------------------*/
             /*                        specific_.c                     */
             /*          Traitement de fonction spécifique de liste    */
             /*                   FONCTIONS SPECIFIQUES A LISTE        */
             /**********************************************************/


#include "specific_tree.h"


/* -------------------------------------------------------------------- */
/* display_Data         Affiche la cellule rentrée en paramètre         */
/*                                                                      */
/* En entrée: d la cellule à afficher                                   */
/*                                                                      */
/* -------------------------------------------------------------------- */
void display_Data(treedata_t d) {
    printf("Letter : %c\n", d.letter);
}

/* -------------------------------------------------------------------- */
/* init_Tree_Data         Initialisation des valeurs de l'arbre         */
/*                                                                      */
/* En entrée: letter, le caractère à initialiser. En sortie la cellule */
/*                                                                      */
/* -------------------------------------------------------------------- */

treedata_t init_Tree_Data(char letter){
    treedata_t cell;
    cell.letter = letter;
    return cell;
}
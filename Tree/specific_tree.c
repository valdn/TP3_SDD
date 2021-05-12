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
/* En entrée: d la cellule à afficher et file la sortie de l'affichage  */
/*                                                                      */
/* -------------------------------------------------------------------- */
void display_Data(treedata_t d) {
    printf("Cost : %c", d.letter);
}

treedata_t init_Tree_Data(char letter){
    treedata_t cell;
    cell.letter = letter;
    return cell;
}
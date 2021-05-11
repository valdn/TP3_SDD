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
void display_Data(treedata_t d, FILE * file) {
    fprintf(file, "Cost : %d / Factory : %d / Period : %d", d.cost, d.factory, d.period);
}

treedata_t init_Data(int cost, int factory, int period){
    treedata_t cell;
    if(factory >= 0 && period >= 0 && cost >= 0){
        cell.factory = factory;
        cell.period = period;
        cell.cost = cost;
    }
    else{
        cell.factory = 0;
        cell.period = 0;
        cell.cost = 0;
    }
    return cell;
}

/* -------------------------------------------------------------------- */
/* equals_Data     Vérifie l'égalité entre les valeurs de 2 cellules    */
/*                                                                      */
/* En entrée: Les 2 cellules à comparer                                 */
/*                                                                      */
/* En sortie: Un booléen si les cellules vérifient l'égalité            */
/* -------------------------------------------------------------------- */

int equals_Data(treedata_t data1, treedata_t data2){
    if(data1.cost == data2.cost && data1.factory == data2.factory && data1.period == data2.period){
        return 1;
    }
    else {
        return 0;
    }
}

/* -------------------------------------------------------------------- */
/* equal_Factory         Vérifie si la valeur en entrée correspond      */
/*                       à la valeur usine de la cellule                */
/*                                                                      */
/* En entrée: value un entier et data2 une cellule                      */
/*                                                                      */
/* En sortie: Un booléen si la cellule vérifie l'égalité avec la valeur */
/* -------------------------------------------------------------------- */
int equal_Factory(int value, treedata_t data2){
    if(value == data2.factory){
        return 1;
    }
    else {
        return 0;
    }
}
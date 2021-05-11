             /**********************************************************/
             /*DI NARDO Valentin - VIELLARD Bruno                 2021 */
             /*--------------------------------------------------------*/
             /*                        list.c                          */
             /*          Traitement de liste chaînée                   */
             /*                   FONCTIONS LISTE                      */
             /**********************************************************/

#include "list.h"

/* -------------------------------------------------------------------- */
/* display_List           Affiche la liste                              */
/*                                                                      */
/* En entrée: list la liste courante et path l'endroit d'affichage      */
/*                                                                      */
/* Principe: Affiche la liste dans le terminal ou dans un fichi         */
/*           en fonction du paramètre en entré                          */
/*                                                                      */
/* -------------------------------------------------------------------- */

void display_List(list_t * list, char * path){

   list_t * current;
   FILE *file;


   if (strcmp(path, "stdout")==1){

      // use appropriate location if you are using MacOS or Linux
      file = fopen(path,"w");

      if(file == NULL)
      {
         printf("Error!\n");   
         exit(1);             
      }

      current = list->next;
      while(current!=NULL){
         display_Data(current->value, file);
         fprintf(file," / @ : %p / Next : %p\n",current, current->next);
         current = current->next;
      }
      printf("Displayed in file %s\n\n",path);
      fclose(file);
   } else {
      current = list->next;
      while(current!=NULL){
         display_Data(current->value, stdout);
         fprintf(stdout," / @ : %p / Next : %p\n",current, current->next);
         current = current->next;
      }
      printf("\n");
   }
}

/* -------------------------------------------------------------------- */
/* init_List         Initalise une liste chaînée                        */
/*                                                                      */
/*                                                                      */
/* En sortie: Retourne la liste initialisée                             */
/*                                                                      */
/* -------------------------------------------------------------------- */
list_t * init_List(){
   
   list_t * headList;

   headList = malloc(sizeof(list_t));
   headList->value.cost = -1;
   headList->value.factory = -1;
   headList->value.period = -1;
   headList->next = NULL;
   return headList;
}

/* -------------------------------------------------------------------- */
/* free_List          Libère les cellules de la liste chaînée           */
/*                                                                      */
/*                                                                      */
/* En entrée: current une liste                                          */
/*                                                                      */
/*                                                                      */
/* -------------------------------------------------------------------- */
void free_List(list_t * current){
   if(current != NULL){
      free_List(current->next);
      printf("Free %p", current);
      printf("\n");
      free(current);
   }
}
/* -------------------------------------------------------------------- */
/* add_Cell_in_List          Ajoute une cellule dans la liste           */
/*                                                                      */
/*                                                                      */
/* En entrée: prec un pointeur sur l'emplacement précédent l'insertion  */
/*            value une struct data de la cellule a insérer             */
/*                                                                      */
/* -------------------------------------------------------------------- */
void add_Cell_in_List(list_t * prec, data_t value){
   list_t * nextList;
   list_t * tempList;

   nextList = malloc(sizeof(list_t));
   nextList->value=value;
   tempList=prec->next;
   nextList->next=tempList;
   prec->next=nextList;
}

/* -------------------------------------------------------------------- */
/* search_in_ListbyCell          Recherche une cellule dans la liste    */
/*                                                                      */
/*                                                                      */
/* En entrée: list la liste dans laquelle chercher la cellule           */
/*            data la cellule a chercher                                */
/*                                                                      */
/* -------------------------------------------------------------------- */
list_t * search_in_ListbyCell(list_t * list, data_t data){
   list_t * tempList;

   tempList = list;
   while((tempList->next!=NULL) && !(equals_Data(tempList->next->value, data))){
      tempList=tempList->next;
   }
   return tempList;
}

/* -------------------------------------------------------------------- */
/* delete_Occurences Supprime les occurences d'une usine dans une liste */
/*                                                                      */
/*                                                                      */
/* En entrée: list la liste dans laquelle supprimer l'usine             */
/*            factory un entier correspondant à l'usine à supprimer     */
/*                                                                      */
/* -------------------------------------------------------------------- */
void delete_Occurences(list_t * list, int factory){
   
   list_t * tempList;
   
   tempList = list;
   while(tempList->next!=NULL){
      if (equal_Factory(factory, tempList->next->value)){
         delete_in_List(tempList);
      } else {
         tempList=tempList->next;
      }
   }
}

/* -------------------------------------------------------------------- */
/* delete_in_List Supprime la cellule suivante celle rentrée en paramètre */
/*                                                                      */
/*                                                                      */
/* En entrée: templist emplacement précédent la cellule à supprimer     */
/*                                                                      */
/* -------------------------------------------------------------------- */
void delete_in_List(list_t * tempList){
   list_t * freeList = tempList->next;
   tempList->next = freeList->next;
   free(freeList);
}

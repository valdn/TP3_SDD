#include "tree.h"

/**
*Initialisation de la tête de l'arbre 
*/
tree_t * init_Tree(){
   return NULL;
}

/**
*Création de l'arbre avec une expression
*@param expression Expression en entrée supposé sans erreur
*/
tree_t * createTree(char* expression){
   int position = 0;
   
   tree_t * arbre = NULL;
   pile_t* pile = init_Pile(25);
   tree_t * ptrCour = NULL;
   tree_t ** prec = &arbre;

   int stack = 1;

   if (pile != NULL){
     while(expression[position]!='\0'){
        if(expression[position] == '*'){
            stack = 0;
            prec = &(ptrCour->lv);
        }
        else if(expression[position] == '+'){
          unstack_Pile(pile, &ptrCour);
          prec = &(ptrCour->lh);
          stack = 1;
        }
        else if(expression[position] == '('){
            stack = 1;
        }
        else if(expression[position] == ')'){
          unstack_Pile(pile, &ptrCour);
        }
        else if (((expression[position] >= 'a') && (expression[position] <= 'z')) || ((expression[position] >= 'A') && (expression[position] <= 'Z')))
        {
            ptrCour = create_Node(expression[position]);
            if (stack == 1){
               stack_Pile(pile, ptrCour);
               stack = 0;
            }
            *prec = ptrCour;
        }
        position++;
      }
   }
   free_Pile(pile);
   return arbre;
}

/**
*Affichage du contenu de l'arbre
*@param tree Arbre à afficher
*/

void display_Tree(tree_t * tree){
   if (tree==NULL) return;
   printf("%c \n", tree->value.letter);
   display_Tree(tree->lv);
   display_Tree(tree->lh);

}

/**
*Permet de vider l'arbre
*@param current  Arbre courant à vider
*/

void free_tree(tree_t * current){
   tree_t * ptrCour = current;
   if (ptrCour != NULL){
      free_tree(ptrCour->lh);
      free_tree(ptrCour->lv);
      free(ptrCour);
   }
}

/**
*Permet de créer un noeud
*@param letter lettre contenue dans le noeud
*/

tree_t * create_Node(char letter){
   tree_t* tnew = (tree_t*)allocation_mem(1, sizeof(tree_t));
   if(tnew != NULL){
      tnew->value.letter=letter;
      tnew->lh=NULL;
      tnew->lv=NULL; 
   }
   return tnew;
}

/**
*Permet d'afficher le dictionnaire exprimé par un arbre'
*@param tree Arbre duquel afficher le dictionnaire
*@param word Mot courant à afficher
*@param i entier pour parcourir le mot
*/
void displayDictionary(tree_t ** tree, char * word, int i){
   tree_t * ptrCour = *tree;
   pile_t * pile = init_Pile(25);

   if (pile!= NULL){
      while(ptrCour != NULL){
         if ((ptrCour->value.letter >= 'A') && (ptrCour->value.letter <= 'Z')){
            word[i] = (ptrCour->value.letter) + 32;
            printf("%s\n", word);
         }
         else {
            word[i] = ptrCour->value.letter;
         }
         stack_Pile(pile, ptrCour);
         ptrCour = ptrCour->lv;
         while((ptrCour == NULL) && (!isEmpty(pile))){
            unstack_Pile(pile, &ptrCour);
            ptrCour = ptrCour->lh;

            word[i] = '\0';
            i--;
         }
         i++;
      }
   }
   printf("\n");
   free_Pile(pile);
}

/**
*Permet d'insérer un mot dans un arbre'
*@param tree Arbre duquel afficher le dictionnaire
*@param word Mot à insérer
*/
void insert_word(tree_t ** tree, char * word){
   tree_t ** prec = tree;
   tree_t * cour = *tree;
   tree_t * elt = NULL;
   
   int i = 0;
   int continuer = 1;
   
   if(word[0] != '\0'){
      while((word[i] != '\0') && (continuer)){
         prec = search_prec_sort(prec, word[i]);

         if(((*prec) == NULL) || (word[i] != tolower((*prec)->value.letter))){
            continuer = 0;
            elt = create_Node(word[i]);
            elt->lh = (*prec);
            (*prec) = elt;
            cour = elt;
            i++;
            while(word[i] != '\0'){
               elt = create_Node(word[i]);
               cour->lv = elt;
               prec = &cour;
               cour = cour->lv;
               i++;
            }
         }
         else{
            prec = &((*prec)->lv);
            cour = (*prec);
         }
         i++;
      }
      if (!continuer)
         (*prec)->value.letter = toupper((*prec)->value.letter);
      else
         printf("Le mot existe déjà\n");
   }
}

/**
*Permet d'afficher tout les mots débutant par un certains motif'
*@param tree Arbre duquel afficher les mots correspondants
*@param motif Motif
*/
void search_pattern(tree_t ** tree, char * motif){
   tree_t ** prec = tree;
   int i = 0, continuer = 1;

   while ((motif[i] != '\0') && (continuer)){
      prec = search_prec_sort(prec, motif[i]);
      if(((*prec) != NULL) && (tolower((*prec)->value.letter) == motif[i]))
      {
         prec =&((*prec)->lv);
      }
      else {
         continuer = 0;
      }
      i++;
   }

   if (*prec!=NULL)
      displayDictionary(prec, motif, i);
   else
      printf("Aucun mot correspondant au motif\n");
}

/**
*Recherche un caractère et retourne un pointeur sur le précédent
*@param tree Arbre dans lequel faire la recherche
*@param letter Lettre à trouver dans l'arbre
*/
tree_t ** search_prec_sort(tree_t **tree, char letter){
   tree_t * ptrCour = *tree;
   tree_t ** prec = tree;

   while ((ptrCour != NULL) && (tolower(ptrCour->value.letter)) < tolower(letter)){
      prec = &ptrCour->lh;
      ptrCour = ptrCour->lh;
   }
   return prec;
}
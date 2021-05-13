#include "tree.h"

tree_t * init_Tree(){
   return NULL;
}

tree_t * createTree(char* expression){
   int position = 0;
   
   tree_t * arbre = NULL;
   pile_t* pile = init_Pile(25);
   tree_t * ptrCour = NULL;
   tree_t ** prec = &arbre;

   if (pile != NULL){
     while(expression[position]!='\0'){
        if(expression[position] == '*'){
          prec = &(ptrCour->lv);
        }
        else if(expression[position] == '+'){
          unstack_Pile(pile, &ptrCour);
          prec = &(ptrCour->lh);
        }
        else if(expression[position] == '('){
          position++;
          printf("Création node : %c \n", expression[position]);
          ptrCour = create_Node(expression[position]);
          stack_Pile(pile, ptrCour);
          *prec = ptrCour;
        }
        else if(expression[position] == ')'){
          unstack_Pile(pile, &ptrCour);
        }
        else if (((expression[position] >= 'a') && (expression[position] <= 'z')) || ((expression[position] >= 'A') && (expression[position] <= 'Z')))
        {
            ptrCour = create_Node(expression[position]);
            stack_Pile(pile, ptrCour);
            *prec = ptrCour;
        }
        position++;
      }
   }
   return arbre;
}

void display_Tree(tree_t * tree){
   if (tree==NULL) return;
   printf("%c \n", tree->value.letter);
   display_Tree(tree->lv);
   display_Tree(tree->lh);
}

void free_tree(tree_t * current){
   tree_t * ptrCour = current;
   if (ptrCour != NULL){
      free_tree(ptrCour->lh);
      free_tree(ptrCour->lv);
      free(ptrCour);
   }
}

tree_t * create_Node(char letter){
   tree_t * tnew = malloc(sizeof(tree_t));
   if(tnew != NULL){
      tnew->value.letter=letter;
      tnew->lh=NULL;
      tnew->lv=NULL; 
   }
   return tnew;
}


tree_t * add_Vertical_Link(tree_t ** prec, tree_t * elem){
   elem->lv = *prec;
   *prec=elem;
}

tree_t * add_Horizontal_Link(tree_t ** prec, tree_t * elem){
   elem->lh = *prec;
   *prec=elem;
}

void displayDictionary(tree_t ** tree){
   tree_t * ptrCour = *tree;
   pile_t * pile = init_Pile(25);

   char word[30];
   int i = 0;

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
            //printf("Valeur de ptrCour : %c \n", ptrCour->value.letter);
            ptrCour = ptrCour->lh;

            word[i] = '\0';
            i--;
         }
         i++;
      }
   }
}
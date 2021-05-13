#include "tree.h"

tree_t * init_Tree(){
   return NULL;
}

tree_t * createTree(char* expression){
   int position = 0;
   
   tree_t * arbre = NULL;
   pile_t* pile = init_Pile(25);
   tree_t * ptrCour = NULL;
   tree_t * temp = NULL;
   tree_t ** prec = &arbre;

   if (pile != NULL){
     while(expression[position]!='\0'){
        if(expression[position] == '*'){
          prec = &(ptrCour->lv);
        }
        else if(expression[position] == '+'){
          unstack_Pile(pile, ptrCour);
          prec = &(ptrCour->lh);
        }
        else if(expression[position] == '('){
          position++;
          printf("Création node : %c \n", expression[position]);
          ptrCour = create_Node(expression[position]);
          stack_Pile(pile, *ptrCour);
          *prec = ptrCour;
        }
        else if(expression[position] == ')'){
          unstack_Pile(pile, ptrCour);
        }
        else if (((expression[position] >= 'a') && (expression[position] <= 'z')) || ((expression[position] >= 'A') && (expression[position] <= 'Z')))
        {
            ptrCour = create_Node(expression[position]);
            stack_Pile(pile, *ptrCour);
            *prec = ptrCour;
        }
        position++;
        display_Pile(pile);
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

}

tree_t * create_Node(char letter){
   tree_t * tnew = malloc(sizeof(tree_t));
   tnew->value.letter=letter;
   tnew->lh=NULL;
   tnew->lv=NULL; 
   return tnew;
}


tree_t * add_Vertical_Link(tree_t * tree, tree_t * verticalTree){
   tree->lv=malloc(sizeof(tree_t));
   
   return NULL;
}
#include "tree.h"

tree_t * init_Tree(){
   return NULL;
}

// tree_t createTree(char* expression, int * position){
//     int i;
// 	if(expression[*position] == '*'){
// 		++*position;
// 		i = *position-1;
// 		return creer_arbre(expression[i],
// 				   creer_arbre_expression(expression, position),
// 				   creer_arbre_expression(expression, position)
// 				   );
// 	}else if(expression[*position] == '+'){
// 		++*position;
// 		i = *position-1;
// 		return creer_arbre(expression[i],
// 				   creer_arbre_expression(expression, position),
// 				   creer_arbre_expression(expression, position)
// 				   );
// 	}else if(expression[*position] ==  '-' ){
// 		++*position;
// 		i = *position-1;
// 		return creer_arbre(expression[i],
// 				   creer_arbre_expression(expression, position),
// 				   creer_arbre_expression(expression, position)
// 				   );
// 	}else if(expression[*position] >= '0' && expression[*position] <= '9'){
// 	       	++*position;
// 		i = *position-1;
// 		return creer_noeud(expression[i]);
// 	}  
// }


void createTree(tree_t * tree, char* expression){
   int position = 0;
   pile_t* pile = init_Pile(15);
   tree_t * currentTree;
   tree_t prec;
   // void stack_Pile(pile_t * pile, data_t val);
   // void unstack_Pile(pile_t * pile, data_t *elem);
   // void display_Pile(pile_t * pile);
   while(expression[position]!='\0'){
      if(expression[position] == '*'){
         //Nouveau lien vertical
         //on ajoute le lien vertical
         position++;
         if (expression[position]!='(')
            printf("Ajout lien vertical de %c vers %c\n", expression[position-1], expression[position]);
         else position--;
      }
      else if(expression[position] == '+'){
         //Nouveau lien horizontal
         position++;
         //On dépile et on ajoute le lien horizontal
         unstack_Pile(pile, &prec);
         printf("On dépile : %c \n", prec.value.letter);
         printf("On ajoute un lien horizontal entre %c et %c\n", prec.value.letter, expression[position]);

      }
      else if(expression[position] == '('){
         position++;
         //Créer => Ajouter => Mettre dans la pile le noeud
         stack_Pile(pile, createPileData(expression[position]));
         printf("On empile le prochain : %c \n", expression[position]);   
      }
      else if(expression[position] == ')'){
         unstack_Pile(pile, &prec);
         //On récupère l'emplacement
         printf("On dépile : %c \n", prec.value.letter);
      }
      else{

      }
      position++;
      display_Pile(pile);
   }
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
   

}
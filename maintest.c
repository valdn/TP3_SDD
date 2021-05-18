#include "Tree/tree.h"

int main()
{
    char * expressionVide = "";
    char * expression = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S)))";

    char d[20] = "ab";
    char v[20]="";

    
    tree_t * treeVide = init_Tree();

    printf("Création d'un arbre vide\n");
    treeVide = createTree(expressionVide);
    printf("\n");

    printf("Affichage de l'arbre vide\n");
    displayDictionary(&treeVide, v, 0);

    printf("Recherche du paterne 'ab' dans l'arbre vide\n");
    search_pattern(&treeVide,d);

    printf("Insertion d'un mot dans l'arbre vide\n");
    insert_word(&treeVide, "abolir");
    printf("\n");

    printf("Affichage de l'arbre avec le nouveau mot\n");
    displayDictionary(&treeVide, v, 0);
    
    printf("Recherche du paterne 'ab' dans l'arbre avec le nouveau mot\n");
    search_pattern(&treeVide,d);

    printf("Libération de l'arbre\n");
    free_tree(treeVide);
    printf("\n");

    tree_t * tree = init_Tree();

    printf("Création d'un arbre rempli\n");
    tree = createTree(expression);
    printf("\n");

    printf("Affichage de l'arbre rempli\n");
    displayDictionary(&tree, v, 0);

    printf("Recherche du paterne 'ab' dans l'arbre rempli\n");
    search_pattern(&tree,d);

    printf("Insertion d'un mot dans l'arbre rempli\n");
    insert_word(&tree, "abolir");
    printf("\n");

    printf("Affichage de l'arbre avec le nouveau mot\n");
    displayDictionary(&tree, v, 0);
    
    printf("Recherche du patterne 'ab' dans l'arbre vide\n");
    search_pattern(&tree,d);

    printf("Libération de l'arbre\n");
    free_tree(tree);
    printf("\n");
    
    return 0;
}

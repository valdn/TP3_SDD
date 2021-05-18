#include "Tree/tree.h"

int main()
{
    char * expressionVide = "";
    char * expression = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S)))";

    char c[35]="";

    tree_t * tree = init_Tree();

    tree = createTree(expression);
    insert_word(&tree, "abolir");
    displayDictionary(&tree, c, 0);
    char d[35] = "ab";
    search_pattern(&tree,d);
    free_tree(tree);
    
    return 0;
}

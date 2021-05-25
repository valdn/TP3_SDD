#include "Tree/tree.h"

int main()
{
    char * expression = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S))+b*(a*(L*I*E+R*r*E)+i*(e*N+S*E)))";
    char * expression2 = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S)))";
    char * expression3 = "(b*(o*(N*(j*o*u*R+n*n*E*T)+U*T)+v*i(O+S)))";

    char c[35]="";

    tree_t * tree = init_Tree();

    tree = createTree(expression2);
    insert_word(&tree, "abolir");
    insert_word(&tree, "abolir");
    displayDictionary(&tree, c, 0);
    char d[35] = "ab";
    search_pattern(&tree,d);
    char y[35] = "zz";
    search_pattern(&tree,y);
    free_tree(tree);
    
    return 0;
}

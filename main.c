#include "Tree/tree.h"

int main(int argc, char const *argv[])
{
    char * expression = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S))+b*(a*(L*I*E+R*r*E)+i*(e*N+S*E)))";
    char * expression2 = "(a*(b*(a*T+i*m*E+o*l*i*R)+r*(d*U+T*S)))";
    char * expression3 = "(b*(o*(N*(j*o*u*R+n*n*E*T)+U*T)+v*i(O+S)))";

    char c[35]="";

    tree_t * tree = init_Tree();

    tree = createTree(expression);
    insert_word(&tree, "abaw");
    displayDictionary(&tree, c, 0);
    char d[35] = "ba";
    search_pattern(&tree,d);
    free_tree(tree);
    
    return 0;
}

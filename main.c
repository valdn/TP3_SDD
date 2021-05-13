#include "Tree/tree.h"

int main(int argc, char const *argv[])
{
    char* expression = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S))+b*(a*(L*I*E+R*r*E)+i*(e*N+S*E)))";
    char* expressionpetite = "(a*(b+C))";
    char * expression2 = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S)))";
    char * expression3 = "(b*(o*(N*(j*o*u*R+n*n*E*T)+U*T)+v*i(O+S)))";

    tree_t * tree = init_Tree();

    tree = createTree(expression3);
    display_Tree(tree);
    displayDictionary(&tree);
    return 0;
}

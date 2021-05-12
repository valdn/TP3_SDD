#include "Tree/tree.h"

int main(int argc, char const *argv[])
{
    //char* expression = "(a*(b*(a*T+i*m*E)+r*(d*U+T*S_))+b*(a*(L*I*E+R*r*E)+i*(e*N+S*E)))";
    char* expressionpetite = "(a*(b+c))";

    tree_t * tree = init_Tree();

    createTree(tree, expressionpetite);
    return 0;
}

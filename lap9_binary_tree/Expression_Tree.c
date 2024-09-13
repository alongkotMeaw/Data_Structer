#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// include my file
#include "function_for_Expression_tree.c"

void main(int argc, char const *argv[])
{
    char op[51];
    Treenode *node_left, *node_right;
    scanf("%s", op);
    /// printf("input length = %d\n", strlen(op));
    for (int i = strlen(op) - 1; i >= 0; i--) // read at end to first // -1 for index start 0
    {
        // printf("round of %c\n", op[i]);
        if ('0' <= op[i] && op[i] <= '9')
        {
            push(createNode(op[i]));
        }
        else
        {

            node_left = pop();
            node_right = pop();
            push(pushtree(node_left, node_right, createNode(op[i]))); // pust back
        }
    }

    // call preorder and postorder
    preinorder(Top); /// travel on tree for asin value to array
    printf("=%d", sumnode(Top));
}

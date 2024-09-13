#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// include my file
#include "function_for_Expression_Tree_posfix.c"

void main(int argc, char const *argv[])
{
    char op[51];
    Treenode *node_left, *node_right;
    scanf("%[^\n]", op);
    printf("input = %s", op);
    char *token = strtok(op, " ");
    while (token != NULL)
    {
        printf("round %s\n", token);
        if (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/' && token[0] != '^') // work because opera is char like + - * / ^
        {
            push(createNode(token));
        }
        else
        {
            node_left = pop();
            node_right = pop();
            printf("left %s\n", node_left->data);
            printf("right %s\n", node_right->data);
            printf("mother %s\n", token);
            push(pushtree(node_left, node_right, createNode(token)));
        }

        // cut str
        token = strtok(NULL, " ");
    }
    // function for call
    callopera();
    // preinorder(Root);
    printf("=%d", call_sumnode());
    // sumnode(Root);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
    struct Treenode *next;
    struct Treenode *mother;

} Treenode;
Treenode *Top = NULL;
Treenode *Root = NULL;

// function list
// stack
void push(Treenode *);
Treenode *pop();
// tree
Treenode *createNode(char new_data);
Treenode *pushtree(Treenode *node_lef, Treenode *node_right, Treenode *mother);
void preinorder(Treenode *);
// cal function
int Postfix();
int calculate(int x, int y, char opt);
int sumnode(Treenode *);

void main(int argc, char const *argv[])
{
    char op[51];
    Treenode *node_left, *node_right;
    scanf("%s", op);
    /// printf("input length = %d\n", strlen(op));
    for (int i = strlen(op) - 1; i >= 0; i--) // read at end to first // -1 for index start 0
    {
        if ('0' <= op[i] && op[i] <= '9')
        {
            // printf("2 case %c\n", op[i]);
            push(createNode(op[i]));
        }
        else
        {
            // printf("1 case %c\n", op[i]);
            node_left = pop();
            node_right = pop();
            // printf("left = %c\n", node_left->data);
            // printf("right = %c\n", node_right->data);
            //  if (Top == NULL)
            //  printf("top == null");
            push(pushtree(node_left, node_right, createNode(op[i]))); // pust back
        }
    }

    // call preorder and postorder
    preinorder(Top); /// travel on tree for asin value to array
    printf("= %d", sumnode(Top));
}

// stack
void push(Treenode *node_add) ///
{
    if (Top == NULL)
        Top = node_add;
    else
    {
        node_add->next = Top;
        Top = node_add;
    }
}

Treenode *pop()
{
    if (Top == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    Treenode *re_node = Top;
    Top = Top->next;
    return re_node;
}

Treenode *pushtree(Treenode *node_lef, Treenode *node_right, Treenode *mother)
{
    mother->leftChild = node_lef;
    node_lef->mother = mother; // set mother
    node_right->mother = mother;
    mother->rightChild = node_right;
    return mother;
}

// tree
Treenode *createNode(char new_data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = new_data;
    new_node->leftChild = NULL; // set all child node is null
    new_node->rightChild = NULL;
    return new_node;
}

void preinorder(Treenode *node_print) // Postfix
{
    if (node_print != NULL)
    {
        bool check_operrand = false;
        char operand[] = "+-*/^";
        for (int i = 0; i < strlen(operand); i++) // loop for check num
            if (node_print->data == operand[i])
            {
                check_operrand = true;
                break;
            }

        if (check_operrand)
        {
            printf("(");
            preinorder(node_print->leftChild);
            printf("%c", node_print->data);
            preinorder(node_print->rightChild);
            printf(")");
        }
        else
            printf("%c", node_print->data);
    }
}

bool isleft(Treenode *node_check)
{
    if (node_check->mother->leftChild == node_check)
        return true;
    else
        return false;
}

int sumnode(Treenode *node_sum)
{
    if (node_sum == NULL)
        return 0;
    if (isleft(node_sum))
        return node_sum->data;

    int x = sumnode(node_sum->leftChild);
    int y = sumnode(node_sum->rightChild);
    char opt = node_sum->data;
    return calculate(x, y, opt);
}

int calculate(int x, int y, char opt)
{

    int result = 0;
    switch (opt)
    {
    case '+':
        result = result + x + y;
        break;
    case '-':
        result = result + x - y;
        break;
    case '*':
        result = result + x * y;
        break;
    case '/':
        result = result + x / y;
        break;
    case '^':
        result = result + ceil(pow(x, y));
        break;
    }

    return result;
}

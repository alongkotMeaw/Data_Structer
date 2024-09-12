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
int index_return_preinoder = 0;
char array_return_preinorder[51];

// function list
// stack
void push(Treenode *);
Treenode *pop();
// tree
Treenode *createNode(char new_data);
Treenode *pushtree(Treenode *node_lef, Treenode *node_right, Treenode *mother);
void preinorder(Treenode *, char str[]);
// cal function
int Postfix();
int calculate();

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
    preinorder(Top, "infix"); /// travel on tree for asin value to array
    preinorder(Top, "posfix");
    printf("= %d", calculate());
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

void preinorder(Treenode *node_print, char str[]) // Postfix
{
    if (node_print != NULL)
    {
        if (!strcasecmp(str, "infix"))
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
                preinorder(node_print->leftChild, str);
                printf("%c", node_print->data);
                preinorder(node_print->rightChild, str);
                printf(")");
            }
            else
                printf("%c", node_print->data);
        }
        else if (strcmp(str, "Postfix"))
        {
            preinorder(node_print->leftChild, str);
            preinorder(node_print->rightChild, str);
            array_return_preinorder[index_return_preinoder++] = node_print->data;
        }
    }
}

///////////////////// od code at to use ///////////////////// ///

int calculate()
{

    typedef struct list
    {
        int num;
        struct list *next;
    } list;

    list *top = NULL;

    void push_in_cal(int n)
    {
        // printf("n input == %d\n", n);
        list *new_list = (list *)malloc(sizeof(list));
        new_list->num = n;
        new_list->next = top;
        top = new_list;
    }

    int pop_in_cal()
    {
        if (top == NULL)
        {
            printf("Stack is empty\n");
            return 0;
        }
        int re_n = top->num;
        list *temp = top;
        top = top->next;
        free(temp);
        return re_n;
    }

    // main

    char n;
    int result = 0, num_1, num_2;

    // +- 1 : */ 2 / () 0
    for (int i = 0; i < strlen(array_return_preinorder); i++)
    {
        switch (array_return_preinorder[i])
        {
        case '+':
            num_2 = pop_in_cal();
            num_1 = pop_in_cal();
            result = num_1 + num_2;
            push_in_cal(result);
            break;

        case '-':
            num_2 = pop_in_cal();
            num_1 = pop_in_cal();
            result = num_1 - num_2;
            push_in_cal(result);
            break;

        case '*':
            num_2 = pop_in_cal();
            num_1 = pop_in_cal();
            result = num_1 * num_2;
            push_in_cal(result);
            break;

        case '/':
            num_2 = pop_in_cal();
            num_1 = pop_in_cal();
            result = num_1 / num_2;
            push_in_cal(result);
            break;

        case '^':
            num_2 = pop_in_cal();
            num_1 = pop_in_cal();
            result = pow(num_1, num_2);
            push_in_cal(result);
            break;

        default:
            if (array_return_preinorder[i] >= '0' && array_return_preinorder[i] <= '9')
            {
                push_in_cal((array_return_preinorder[i] - '0'));
            }
            break;
        }
    }

    // printf("\n%d\n", result);

    return result;
}

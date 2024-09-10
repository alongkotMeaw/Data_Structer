#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAXTREE 15

char T[MAXTREE] = {'C'}; // Initialize Tree

int LeftNode(int index)
{
    return index * 2 + 1;
}

int RightNode(int index)
{
    return index * 2 + 2;
}

int MotherNode(int index)
{
    return floor((index - 1) / 2);
}

bool isLeft(int k)
{
    if (k % 2 == 1)
        return true;
    return false;
}

bool isRight(int k)
{
    if (k % 2 == 0)
        return true;
    return false;
}

void SetLeft(k, data)
{
    int index = 2 * k + 1;
    if (index < MAXTREE)
    {
        if (T[index] == '\0')
        {
            T[index] = data;
        }
        else
            printf("Node Inused\n");
    }
    else
        printf("Tree Overflow\n");
}

void SetRight(k, data)
{
    int index = 2 * k + 2;
    if (index < MAXTREE)
    {
        if (T[index] == '\0')
        {
            T[index] = data;
        }
        else
            printf("Node Inused\n");
    }
    else
        printf("Tree Overflow\n");
}

int main()
{
    int i = 0;
    SetLeft(0, 'P');
    SetRight(0, 'E');
    SetLeft(1, 'A');
    SetRight(1, 'T');
    SetLeft(2, 'K');
    SetRight(2, 'P');
    SetLeft(3, 'S');

    SetRight(5, 'X');
    SetLeft(6, 'Y');

    printf("%d\n", MotherNode(1));
    printf("%d\n", MotherNode(2));
    printf("%d\n", MotherNode(3));

    printf("%c is mother node of %c\n", T[MotherNode(5)], T[5]);
    printf("%c is left node of %c\n", T[LeftNode(2)], T[2]);
    printf("%c is right node of %c\n", T[RightNode(5)], T[5]);

    printf("%d\n", isLeft(5));
    printf("%d\n", isRight(4));

    for (i = 0; i < MAXTREE; i++)
        if (T[i] == '\0')
            printf(" ");
        else
            printf("%c", T[i]);

    return 0;
}

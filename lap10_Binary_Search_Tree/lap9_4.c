#include <stdio.h>
#include <stdbool.h>

bool is_tree(int left, int right)
{
    if (left <= right)
        true;
    else
        false;
}

void main()
{
    int size;
    scanf("%d", &size);

    int input[size], input_index = 0, max, min;
    for (; input_index < size; input_index++)
    {
        scanf(" %d", input[input_index]);
    }
    scanf(" %d %d", &min, &max);
    bool check = true;
    for (int travel = 0; travel < size; travel += 3)
    {
        if (input[travel] < input[travel + 2] && is_tree(input[travel + 1], input[travel + 2]))
        {
            check = false;
            break;
        }
    }
    printf("check == %d", check);
}

/*
7
17
0
19
0
0
0
22
15 20





*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n_mod = 10;
int max = 10;
typedef struct Node
{
    int data;
    struct Node *next;
} node;

// Array of pointers for hash table
node *hash_table[10];

void insertChain(int value)
{
    printf("value inserct to chain = %d\n", value);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    int index;
    if (n_mod == 10)
    {
        index = value % max;
    }
    index = ((value % n_mod - value % (n_mod / 10)) / (n_mod / 10)) % max;

    if (hash_table[index] == NULL)
    {
        hash_table[index] = new_node;
    }
    else
    {
        node *ptr = hash_table[index];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

int main()
{
    int i, n = 20;
    srand((unsigned)time(NULL)); // Initializes random number generator
    int num[n];
    printf("Number before sorting\n");
    for (i = 0; i < n; i++)
    {
        num[i] = rand(); // Random number between 0-32767
        printf("%d ", num[i]);
    }
    printf("\n");

    // Set null hash table
    for (i = 0; i < 10; i++)
        hash_table[i] = NULL;

    int loop_arry = 0;
    for (int lp = 0; lp < 5; lp++)
    {
        for (int loop_hash = 0; loop_hash < n; loop_hash++)
        {

            insertChain(num[loop_hash]);
            num[loop_hash] = 0;
        }
        loop_arry = 0;
        for (i = 0; i < 10; i++)
        {

            node *ptr = hash_table[i];
            while (ptr != NULL)
            {
                num[loop_arry++] = ptr->data;
                ptr = ptr->next;
            }
        }

        for (i = 0; i < 10; i++)
            hash_table[i] = NULL;

        printf("Number after sorting %d\n", lp);
        for (i = 0; i < n; i++)
        {
            printf("%d ", num[i]);
        }
        n_mod = n_mod * 10;
        printf("\n");
    }

    return 0;
}

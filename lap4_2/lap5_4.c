#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct dounode {
   int data;
   struct dounode *next;
   struct dounode *prev;
};

struct node *head = NULL;
struct dounode *dou_head = NULL;

// Function prototypes
void DisplayAddressLL1();
void DisplayAddressLL();
void doublyMaker();

void DisplayAddressLL1() {
    struct dounode *ptr;
    ptr = dou_head;
    while (ptr != NULL) {
        printf("Node val=%d, add=%p\t", ptr->data, (void*)ptr);
        printf("Next node add=%p\n", (void*)ptr->next);
        ptr = ptr->next;
    }
}

void DisplayAddressLL() {
    struct dounode *ptr;
    ptr = dou_head;

    while (ptr!= NULL) {
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        printf("Node val=%d, add=%p\t", ptr->data,ptr);
        printf("Prev node add=%p\n", ptr->prev);
        ptr = ptr->prev;
    }
}

void doublyMaker() {
    struct node *ptr = head; // head single
    struct dounode *new_node, *prev_node = NULL;

    while (ptr != NULL) {
        new_node = (struct dounode *)malloc(sizeof(struct dounode));
        new_node->data = ptr->data;
        new_node->next = dou_head;
        new_node->prev = prev_node;

        if (dou_head != NULL) {
            dou_head->prev = new_node;
        }

        dou_head = new_node;
        prev_node = new_node;
        ptr = ptr->next;
    }
}

int main() {
    //1.1 Code for creating Linked List with random number 1-100
    srand((unsigned) time(NULL));
    int n = 10;
    //scanf("%d", &n);
    struct node *new_node;

    //Code for creating Linked List
    for (int i = 0; i < n; i++) {
        new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = rand() % 100 + 1;
        new_node->next = head;
        head = new_node;
    }

    doublyMaker();

    //DisplayLL();
    DisplayAddressLL1();
    DisplayAddressLL();

    return 0;
}

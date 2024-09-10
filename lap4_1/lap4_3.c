#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void DisplayLL() {
  struct node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\t ", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);

     ptr = ptr -> next;
  }
}

void swap(struct node *n1, struct node *n2) {
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

void BubbleSort(int n) {
    struct node *ptr;
    bool check = true;
    for (int i = 0; i < n && check == true; i++) {
        check = false;
        ptr = head;
        for (int j = 0; j < n - 1 - i; j++) {
            if (ptr->next != NULL && ptr->data > ptr->next->data) {
                swap(ptr, ptr->next);
                check = true;
            }
            ptr = ptr->next;
        }
    }
}

void add_newnode(int value_newnode) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value_newnode;
    new_node->next = NULL;

  
    if (head == NULL || head->data >= value_newnode) {
        new_node->next = head;
        head = new_node;
        return;
    }

    
    struct node *current = head;
    while (current->next != NULL && current->next->data < value_newnode) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

int main() {
    srand((unsigned) time(NULL));
    int n = 6, new_value;

    for (int i = n - 1; i >= 0; i--) {
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = rand() % 100 + 1;
        new_node->next = head;
        head = new_node;
    }


    DisplayLL();

    BubbleSort(n);


    DisplayLL();

    printf("Enter value of new node: ");
    scanf("%d", &new_value);
    add_newnode(new_value);


    DisplayLL();

    return 0;
}

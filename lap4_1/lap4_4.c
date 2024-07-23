#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int pos, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

int searchList(int data) {
    Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

int main() {
    int num;
    char input[30] = "N1IF0";
    //scanf("%s",&input);
    char* token = strtok(input, "NIALF");
    while (token != NULL) {
            num =atoi(token);
            if(input[i] == 'N'){


            }else if(input[i] == I){
                if(input[i+1] == 'F'){

                }
                else if(input[i+1] == 'A'){

                }else if(input[i+1] == 'L')
            }
            token = strtok(NULL, "NIALF");
            printList();


    }

    return 0;
}


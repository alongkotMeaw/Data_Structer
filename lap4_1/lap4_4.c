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
            if (temp == NULL) {
                printf("Position out of range\n");
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAtEnd(int data) {
    // Create a new node
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
        /*
        if (temp != NULL) {
            printf(" ");
        }*/
    }

}

int searchList(int data) {
    Node* temp = head;
    int pos = 1;
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
    char input[30];//= "N3IF5IL2IF7IA29PS0S9";
    int i = 0;
    scanf("%s",input);
    while (i < strlen(input)) {
        if (input[i] == 'N') {
            i++;
            int num = 0;
            while (i < strlen(input) && input[i] >= '0' && input[i] <= '9') {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            insertAtBeginning(num);
        } else if (input[i] == 'I') {
            i++;
            if (input[i] == 'F') {
                i++;
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9') {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                insertAtBeginning(num);
            }

            else if (input[i] == 'L') {
                i++;
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9') {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                insertAtEnd(num);
            }

            else if (input[i] == 'A') {
                i++;
                int pos = 0;
                    pos = input[i] - '0';
                    i++;
                    //printf("check  Position = %d\n",pos);
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9') {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                //printf("check  num = %d\n",num);
                insertAtPosition(pos, num);
            }
        }else if(input[i] == 'P'){
            i++;
            printList();

        }else if(input[i] == 'S'){
            i++;
            int num = 0;
            while (i < strlen(input) && input[i] >= '0' && input[i] <= '9') {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            int result = searchList(num);
            printf("%d",result);
            //printf("i == %d ====== %d",i,strlen(input));
            //break;
        }
    }

    return 0;
}
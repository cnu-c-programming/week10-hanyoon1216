#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

void addNode(Node** head, const char* name, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void deleteNode(Node** head, const char* name) {
    Node* cur = *head;
    Node* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                *head = cur->next;
            } 
            else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void freeAllNodes(Node* head) {
    Node* cur = head;
    Node* nextNode;

    while (cur != NULL) {
        nextNode = cur->next; 
        free(cur);            
        cur = nextNode;       
    }
}

int main() {
    Node* head = NULL; 
    char input[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            scanf("%s %d", name, &score);
            addNode(&head, name, score);
        } 
        else if (strcmp(input, "delete") == 0) {
            scanf("%s", name);
            deleteNode(&head, name);
        } 
        else if (strcmp(input, "print") == 0) {
            printList(head);
        } 
        else if (strcmp(input, "quit") == 0) {
            freeAllNodes(head);
            break;
        }
    }

    return 0;
}

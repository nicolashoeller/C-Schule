/*
File: bst.c
Date: 06.05.2024
Author: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value);
Node* searchNode(Node *rootNode, int value);
void insertNode(Node **rootNode, int value);
void printInOrder(Node *rootNode);
void deallocateNodes(Node *rootNode);

int main() {
    Node *rootNode = NULL;
    int choice, value;

    while(1) {
        printf("\n[*] Menu:\n");
        printf("[1] Insert a value\n");
        printf("[2] Print the tree\n");
        printf("[3] Search an element\n");
        printf("[4] Exit\n");
        printf("[+] Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n[+] Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(&rootNode, value);
                break;
            case 2:
                printf("\n[*] The elements in the tree are: ");
                printInOrder(rootNode);
                printf("\n");
                break;
            case 3:
                printf("\n[+] Enter the value to search for: ");
                scanf("%d", &value);
                Node *foundNode = searchNode(rootNode, value);
                if (foundNode != NULL) {
                    printf("[*] Value found in the tree.\n");
                } else {
                    printf("[!] Value not found in the tree.\n");
                }
                break;
            case 4:
                deallocateNodes(rootNode);
                exit(0);
            default:
                printf("[!] Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}

Node* searchNode(Node *rootNode, int value) {
    if (rootNode == NULL || rootNode->value == value) {
        return rootNode;
    }

    if (rootNode->value < value) {
        return searchNode(rootNode->right, value);
    }

    return searchNode(rootNode->left, value);
}

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node **rootNode, int value) {
    if (*rootNode == NULL) {
        *rootNode = createNode(value);
    } else if (value < (*rootNode)->value) {
        insertNode(&(*rootNode)->left, value);
    } else {
        insertNode(&(*rootNode)->right, value);
    }
}

void printInOrder(Node *rootNode) {
    if (rootNode != NULL) {
        printInOrder(rootNode->left);
        printf("%d ", rootNode->value);
        printInOrder(rootNode->right);
    }
}

void deallocateNodes(Node *rootNode) {
    if (rootNode != NULL) {
        deallocateNodes(rootNode->left);
        deallocateNodes(rootNode->right);
        free(rootNode);
    }
}
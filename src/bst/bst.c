#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;


node* createNode(int key) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


node* insertNode(node* root, int key, int* inserted) {
    if (root == NULL) {
        *inserted = 1;
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key, inserted);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, inserted);
    } else {
        *inserted = 0; 
    }

    return root;
}

void searchNode(node* root, int key) {
    if (root == NULL) {
        printf("absent\n");
        return;
    }

    if (key < root->key) {
        searchNode(root->left, key);
    } else if (key > root->key) {
        searchNode(root->right, key);
    } else {
        printf("present\n");
    }
}


void printBST(node* root) {
    if (root == NULL) {
        return;
    }
    printf("(");
    printBST(root->left);
    printf("%d", root->key);
    printBST(root->right);
    printf(")");
}


node* findMin(node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


node* deleteNode(node* root, int key, int* deleted) {
    if (root == NULL) {
        *deleted = 0; 
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key, deleted);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key, deleted);
    } else {
        
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            *deleted = 1;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            *deleted = 1;
            return temp;
        }

       
        node* temp = findMin(root->right);

        
        root->key = temp->key;

        
        root->right = deleteNode(root->right, temp->key, deleted);
    }

    return root;
}


void freeBST(node* root) {
    if (root == NULL) {
        return;
    }
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    node* root = NULL;
    int inserted, deleted;
    char command;
    int key;

    while (scanf(" %c", &command) == 1) {
        inserted = 0;
        deleted = 0;

        if (command == 'i') {
            scanf(" %d", &key);
            root = insertNode(root, key, &inserted);
            if (inserted) {
                printf("inserted\n");
            } else {
                printf("not inserted\n");
            }
        } else if (command == 's') {
            scanf(" %d", &key);
            searchNode(root, key);
        } else if (command == 'p') {
            printBST(root);
            printf("\n");
        } else if (command == 'd') {
            scanf(" %d", &key);
            root = deleteNode(root, key, &deleted);
            if (deleted) {
                printf("deleted\n");
            } else {
                printf("absent\n");
            }
        }
    }

    
    freeBST(root);

    return EXIT_SUCCESS;
}


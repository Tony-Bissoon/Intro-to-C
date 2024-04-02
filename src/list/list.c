#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Node 
struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;

struct node *current = NULL; 
 

//Print the Linked List 
void printLinkedList(){
    struct node *n = head; 

    while( n != NULL){
        printf(" %d", n ->data);
        n = n ->next; 

    }
} 


void insert(int data ){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            // Value already exists; do not insert it again.
            free(new); // Free the memory allocated for the new node.
            return;
        }
        current = current->next;
    }

    if (head == NULL || head->data > data) {
        new->next = head;
        head = new;
    } else {
        current = head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }

   
}

    




void delete(int n){
  

    if (head == NULL) {
        return;
    }
    
    if (head->data == n) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node* current = head;
        while (current->next != NULL && current->next->data < n) {
            current = current->next;
        }
        if (current->next != NULL && current->next->data == n) {
            struct node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }

   

}



int main(int argc, char **argv){
    char command; 
    int value; 

   
    while (scanf(" %c%d", &command, &value) == 2) {
        int len = 0;
        if (command == 'i') {
            
            insert(value);
           
            
        } else if (command == 'd') {
            
            
            delete(value);
            
        
        }
        
        
        len = 0;
        struct node *current = head;
        while (current != NULL) {
            len++;
            current = current->next;
        }
        
        


        printf("%d :", len);
        printLinkedList();
        printf("\n");
    }

    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return EXIT_SUCCESS;

    
    

}




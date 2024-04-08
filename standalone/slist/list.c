#include "list.h"
#include "stdlib.h"
#include "stdio.h"



/* Implement the functions here */

/* Puts x at the end of the list */
void append(struct list_item *first, int x){
    // first item should be handled here
    if (first->next == NULL)
    {
        struct list_item *new_node = (struct list_item *)malloc(sizeof(struct list_item));
        new_node->value = x;
        new_node->next = NULL;
        first->next = new_node;
    }else{
        // if list have item have item will be traverse through loop
        struct list_item *temp = first;
        while (temp->next != NULL)
        {
            /* keep traversing until the end of list */ 
            temp = temp->next;
        }
        struct list_item *new_node = (struct list_item *)malloc(sizeof(struct list_item));
        new_node->value = x;
        new_node->next = NULL;
        temp->next = new_node;
        //temp = NULL;
    }
    
    
}

/* Puts x at the start of the list */
void prepend(struct list_item *first, int x){
    struct list_item *temp = first->next;
    struct list_item *new_node = (struct list_item *)malloc(sizeof(struct list_item));
    new_node->value = x;
    new_node->next = temp;
    first->next = new_node;
    temp = NULL; // clear the link from temp

}

/* Find the first element in the list larger than x and
 * put x right before that element */
void input_sorted(struct list_item *first, int x){

    if (first->next == NULL)
    {
        append(first,x);
        return;
    }
   struct list_item * curr = first->next;
   struct list_item * prev = first; 
   while (curr != NULL) 
    {
        if (x < curr->value)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    }  
    struct list_item *new_node = (struct list_item *)malloc(sizeof(struct list_item));
    new_node->value = x;
    new_node->next = curr;
    prev->next = new_node;
}

/* Prints all elements in the list */
void print(struct list_item *first){
    struct list_item *temp = first->next;
    printf("[ Singly List ]\n");
    while (temp != NULL)
    {
        /* code */
        int value = temp->value;
        printf("Value  %d\n",   value);  
        temp = temp->next;
    }
    
}

/* Free everything that is dynamically allocated */
void clear(struct list_item *first){
    struct list_item *temp = first->next;
    while (temp != NULL)
    {
        // move temo to next pointer 
        struct list_item * temp_free = temp;
        temp = temp->next;
        /* code */
        free(temp_free);
    }  
    first->next = NULL;
}

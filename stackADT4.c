#include <stdio.h>
#include <stdlib.h>
#ifdef IMP
#include "reference_stackADT.h"
#else
#include "stackADT.h"
#endif
#include "memtrace.h"





struct node{
    void* data;
    struct node *next;
};

struct stack_type{
    struct node *top;
};


Stack Stack_create(void){

    Stack s = malloc(sizeof(stack_type)); //cant use size of for incomplete types
    if (s == NULL){
        printf("Error in create: stack could not be created.");
        exit(EXIT_FAILURE); 
    }
    s->top = NULL;
    return s;
}


void Stack_destroy(Stack s){
    Stack_make_empty(s); //take everything out of stack
    free(s); //free the space for it 
}

void Stack_make_empty(Stack s){

    while(!is_empty(s)){ //while still items in the stack use pop to remove them all
        pop(s);
    }

}



bool Stack_is_empty(Stack s){

    return s->top == NULL; //is the top of the stack is full there are no entries in the stack

}



bool Stack_is_full(Stack s){
    return false; //stack is never full bc we are using a linked list 

}

void Stack_push(Stack s, void * i){

    struct node *new_node = malloc(sizeof(struct node)); //allocate space for the node to be pushed
    if(new_node == NULL){
        printf("error new node is NULL"\n); //if malloc returns null error occured
        exit(EXIT_FAILURE); //return failure
    }

    new_node->data = i; //set the new nodes data to given data
    new_node->next = s->top; //chain newnode to front of the list
    s->top = new_node; //assign top to newly added node

}


void * Stack_pop(Stack s){
    struct node *old_top;
    if(is_empty(s)){
        printf("error in pop, stack is empty\n"); //stack empty cannot pop
        exit(EXIT_FAILURE); //return failure
    }
    old_top = s->top; //set one to be poped to old top
    i = old_top->data; //copy old_tops data to be returned
    s->top = old_top->next; //set top to next to remove old-top from linked list
    free(old_top); //free the allocated space for it
    return i; //return tops data

}
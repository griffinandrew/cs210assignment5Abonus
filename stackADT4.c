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




static void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack Stack_create(void){

    Stack s = malloc(sizeof(struct stack_type)); //cant use size of for incomplete types
    if (s == NULL){
        terminate("Error in create: stack could not be created.\n");
    }
    s->top = NULL;
    return s;
}


void Stack_destroy(Stack s){
    Stack_make_empty(s); //take everything out of stack
    //free(s->top);
    free(s); //free the space for it 
}


bool Stack_is_empty(Stack s){
    //if(Stack_pop(s) != NULL){
   //     return 1;
    //}
    //return 0;
    return s->top == NULL; //is the top of the stack is null there are no entries in the stack
}



void * Stack_pop(Stack s){
    struct node *old_top;
    void* i;
    
    if(Stack_is_empty(s)){
        //i = NULL:
        //free(s->top);
        terminate("error in pop, stack is empty\n"); //stack empty cannot pop
        
      }

    //i = s->top->data;

    
    old_top = s->top; //set one to be poped to old top
    i = old_top->data; //copy old_tops data to be returned
    s->top = old_top->next; //set top to next to remove old-top from linked list
    //old_top->next = NULL;
    //free(old_top->data);
    free(old_top); //free the allocated space for it
    old_top = NULL;
    return i; //return tops data
   // }
}



void Stack_make_empty(Stack s){
    void* i;
   // if (Stack_is_empty(s)){
    //    free(s->top);
    //}

    //do{
   //     Stack_pop(s);
   // }
    while(!Stack_is_empty(s)){
        //Stack_pop(s);
        i = Stack_pop(s);
        if(i!=NULL){
            free(i);
            i = NULL;
        }
        //Stack_pop(s);
    }



    
     //while still items in the stack use pop to remove them all
        //Stack_pop(s);
       // if(s->top->next == NULL ){
       //     free(s->top);
       // }
    //}
    
   // if(Stack_is_empty){
   //     terminate("stack is empty\n");
  //  }

}




bool Stack_is_full(Stack s){
    return false; //stack is never full bc we are using a linked list 

}

void Stack_push(Stack s, void *i){

    struct node *new_node = malloc(sizeof(struct node)); //allocate space for the node to be pushed
    if(new_node == NULL){
        //free(new_node);
        terminate("error new node is NULL\n"); //if malloc returns null error occured
    }
    //if(s->top == NULL){
    //    new_node->data = i;
     //   new_node->next = NULL;
    //    s->top = new_node;
   // }
   // else{
    new_node->data = i; //set the new nodes data to given data
    new_node->next = s->top; //chain newnode to front of the list
    s->top = new_node; //assign top to newly added node
   // }
}
#include <stdio.h>
#include <stdlib.h>
#ifdef IMP
#include "reference_stackADT.h"
#else
#include "stackADT.h"
#endif
#include "memtrace.h"



typedef struct stack_type *Stack{




}


Stack Stack_create(void){

    Stack s = malloc(sizeof(struct style_type));
    if (s == NULL){
        printf("Error in create: stack could not be created.");
        exit(EXIT_FAILURE); 
    }
    s->top = NULL;
    return s;
}


void Stack_destroy(Stack s){
    Stack_make_empty(s);




}

void Stack_make_empty(Stack s){



}



bool Stack_is_empty(Stack s){




}



bool Stack_is_full(Stack s){




}



void Stack_push(Stack s, void * i){




}



void * Stack_pop(Stack s){





}




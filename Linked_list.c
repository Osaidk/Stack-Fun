//
// Created by Osaid K on 10/4/18.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stack_ll.h>

StackNode *head=NULL;


void makeStack(Stack312 *s) {
   s->top=NULL;    // setting it to NULL to start with.

}

bool isFull(Stack312 s){
    return false;     // Honestly without a specific number of entries, I don't know how to check for this.
}

bool isEmpty(Stack312 s){
    if ( s.top==NULL ) {return true;}  // when the pointer reaches NULL again, the stack is empty.
    else return false;
}

void push(StackEntry e,Stack312 *s){

    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));  // allocating memory for a new pixel.
    temp->pixel=e;

    if (s->top == NULL) {
        head = temp;
        head->next=NULL;
        s->top=head;        // my stack builds upwards just like a regular stack.
    }
    else {
        temp->next=head;
        head=temp;
        s->top=head;

    }



}

StackEntry pop(Stack312 *s){
    StackEntry element=s->top->pixel;  // popping an pixel, moves you downward to next pixel.
   s->top=s->top->next;
    return element;

}
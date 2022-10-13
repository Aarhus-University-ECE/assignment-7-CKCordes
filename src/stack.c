#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(stack* s) {
    // implement initialize here
    s->head = NULL;
}

void push(int x, stack* s) {
    /*creating a pointer to the node under head*/
    node* prev = s->head;
    /*allocating memory for the new node*/
    s->head = (node*)malloc(sizeof(node));
    /*assigning the data and pointing to the previous node*/
    s->head->data = x;
    s->head->next = prev;
}

int pop(stack* s) {
    // implement pop here
    // precondition
    assert(s->head != NULL);
    /*creating a pointer to the top of the stack*/
    node* top = s->head;

    /*fetching the top of the stacks data*/
    int topValue;
    topValue = top->data;

    /*Assigning the head to the next node*/
    s->head = top->next;
    free(top);

    return topValue;
}

bool empty(stack* s) {
    // implement empty here
    if (s->head == NULL) {
        return true;
    } else {
        return false;
    }
}

bool full(stack* s) {
    // implement full here
    // Cannot happen
    return false;
}

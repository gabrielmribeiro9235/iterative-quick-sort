#ifndef STACK_H
#define STACK_H

typedef struct {
    int start;
    int end;
} t_item;

typedef struct {
    int max;
    int top_index;
    t_item *items;
} t_stack;

t_stack* create_stack();
int push(t_stack*, int, int);
int pop(t_stack*, int*, int*);
int top(t_stack*, int*, int*);
void destroy(t_stack*);
void clear(t_stack*);
int is_empty(t_stack*);
int is_full(t_stack*);
int size(t_stack*);
void print(t_stack*);

#endif
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#define INITIAL_SIZE 10

static int is_full(t_stack *stack) {
    return stack == NULL || stack->top_index + 1 == stack->max;
}

static int increase_array_size(t_stack *stack) {
    int new_max = stack->max * 2;
    t_item *new = realloc(stack->items, sizeof(t_item) * new_max);

    if (new == NULL) {
        return 0;
    }

    stack->items = new;
    stack->max = new_max;
    return 1;
}

t_stack* create_stack() {
    t_stack *stack = malloc(sizeof(t_stack));

    if (stack == NULL) {
        return NULL;
    }

    stack->items = malloc(sizeof(t_item) * INITIAL_SIZE);

    if (stack->items == NULL) {
        free(stack);
        return NULL;
    }

    stack->max = INITIAL_SIZE;
    stack->top_index = -1;

    return stack;
}

int push(t_stack *stack, int start, int end) {
    if (stack == NULL) {
        return 0;
    }

    if (is_full(stack) && !increase_array_size(stack)) {
        return 0;
    }
    
    t_item item = { .start = start, .end = end};

    stack->top_index++;
    stack->items[stack->top_index] = item;

    return 1;
}

int pop(t_stack *stack, int *start_value, int *end_value) {
    if (is_empty(stack) || start_value == NULL || end_value == NULL) {
        return 0;
    }

    *start_value = stack->items[stack->top_index].start;
    *end_value = stack->items[stack->top_index].end;

    stack->top_index--;

    return 1;
}

int top(t_stack *stack, int *start_value, int *end_value) {
    if (is_empty(stack) || start_value == NULL || end_value == NULL) {
        return 0;
    }

    *start_value = stack->items[stack->top_index].start;
    *end_value = stack->items[stack->top_index].end;

    return 1;
}

int is_empty(t_stack *stack) {
    return stack == NULL || stack->top_index == -1;
}

void destroy(t_stack *stack) {
    if (stack == NULL) {
        return;
    }

    free(stack->items);
    free(stack);
}

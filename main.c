#include<stdio.h>
#include"./stack/stack.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void iterative_quick_sort(int* array, int size) {
    if (array == NULL || size <= 1) return;

    t_stack *stack = create_stack();
    push(stack, 0, size - 1);

    while (!is_empty(stack)) {
        int start, end;
        pop(stack, &start, &end);

        if (start >= end) continue;

        int swap_index = start;

        for (int i = start; i < end; i++) {
            if (array[i] < array[end]) {
                swap(&array[i], &array[swap_index]);
                swap_index++;
            }
        }

        swap(&array[end], &array[swap_index]);

        if (swap_index - 1 - start > end - swap_index + 1) {
            push(stack, start, swap_index - 1);
            push(stack, swap_index + 1, end);
        } else {
            push(stack, swap_index + 1, end);
            push(stack, start, swap_index - 1);
        }
    }

    destroy(stack);
}

void print_array(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void unit_test(int *array, int *expected, int size) {
    printf("Testing for ");
    print_array(array, size);

    iterative_quick_sort(array, size);

    for (int i = 0; i < size; i++) {
        if (array[i] != expected[i]) {
            printf(": failed!\n");
            printf("\tExpected: ");
            print_array(expected, size);
            printf("\n\tReceived: ");
            print_array(array, size);
            printf("\n\n");
            return;
        }
    }

    printf(": passed!\n\tResult: ");
    print_array(array, size);
    printf("\n\n");
}

int main() {
    int array1[] = {5, 2, 8, 1, 0, 3};
    int expected1[] = {0, 1, 2, 3, 5, 8};
    unit_test(array1, expected1, 6);

    int array2[] = {9, 1, 3, 4, 5, 8, 9, 8, 10};
    int expected2[] = {1, 3, 4, 5, 8, 8, 9, 9, 10};
    unit_test(array2, expected2, 9);

    int array3[] = {1, 2, 3, 4, 5};
    int expected3[] = {1, 2, 3, 4, 5};
    unit_test(array3, expected3, 5);

    int array4[] = {4, 3, 2, 1};
    int expected4[] = {1, 2, 3, 4};
    unit_test(array4, expected4, 4);

    unit_test(NULL, NULL, 0);

    int array5[] = {-1, -10, 0, 4, 8, 1, -1};
    int expected5[] = {-10, -1, -1, 0, 1, 4, 8};
    unit_test(array5, expected5, 7);

    int array6[] = {1, 1, 1};
    int expected6[] = {1, 1, 1};
    unit_test(array6, expected6, 3);

    int array7[] = {10};
    int expected7[] = {10};
    unit_test(array7, expected7, 1);

    printf("End of the program\n");

    return 0;
}

#include<stdio.h>
#include"./stack/stack.h"

void iterative_quick_sort(int* array, int size) {
    return;
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
            printf(": failed\n");
            printf("\tExpected: ");
            print_array(expected, size);
            printf("\n\tReceived: ");
            print_array(array, size);
            printf("\n\n");
            return;
        }
    }

    printf(": passed\n\n");
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

    return 0;
}

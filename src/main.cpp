#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "stack.c"
#include "taylor_sine.c"

// Add your test cases for Exercise 1b,c) here
void test_taylor_sine(double x, int n) {
    double taylor_sin = taylor_sine(x, n);
    double ANSI_sine = sin(x);
    double precision = abs(taylor_sin - ANSI_sine);

    printf("x = %lf   n = %d\ntaylor sine = %lf   ANSI_sine = %lf\n", x, n,
           taylor_sin, ANSI_sine);
    // it has to be inside of 0.01 of the ANSI sin
    if (precision > 0.01) {
        printf("Test case failed\n");
    } else {
        printf("\033[0;32m");
        printf("-----Test case succeded-----\n");
        printf("\033[0m");
    }
}

/*
Answer for question 1.c):
As we increase n out taylor sine function reaches the ANSI sine functions value,
it also allows us to calculate higher numbers of x. However when x reaches
higher numbers we need way higher precision and it will take us longer time
*/

void test_stack(void) {
    printf("Testing stack\n");
    stack s;
    initialize(&s);
    printf("Testing (A) Asserting the stack is empty upon initialization\n");
    assert(empty(&s));
    printf("\033[0;32m");
    printf("-----Successful-----\n");
    printf("\033[0m");

    printf("Testing (B), pushing x and asserting it is equal to pop(s)\n");
    int x = 5;
    int y;
    push(x, &s);
    y = pop(&s);
    assert(x == y && empty(&s));
    printf("\033[0;32m");
    printf("-----Successful-----\n");
    printf("\033[0m");

    printf("Testing (C) pushing and popping\n");
    int x0 = 1;
    int x1 = 2;
    int y0, y1;
    push(x0, &s);
    push(x1, &s);
    y0 = pop(&s);
    y1 = pop(&s);
    assert(empty(&s) && x0 == y1 && x1 == y0);
    printf("\033[0;32m");
    printf("-----Successful-----\n\n");
    printf("\033[0m");
}

int main(int argc, char **argv) {
    test_stack();

    printf("Test case 1:\n");
    test_taylor_sine(3, 6);

    printf("\nTest case 2:\n");
    test_taylor_sine(-3, 6);

    printf("\nTest case 3:\n");
    test_taylor_sine(30, 60);

    printf("\nTest case 4:\n");
    test_taylor_sine(5, -6);

    return 0;
}
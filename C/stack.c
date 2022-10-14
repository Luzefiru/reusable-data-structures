/**
 * @brief An implementation of a Stack data strcuture that accepts up to 100 {char} elements. Coded for reusability.
 * @version 0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100 // can modify the max size of the stack

char contents[STACK_SIZE];
int top = 0;
bool flag_underflow = false, flag_overflow = false;

bool is_empty(void);
bool is_full(void);
void make_empty(void);
char push(char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    // insert code here

    return 0;
}

/* checks if the stack is empty */
bool is_empty(void)
{
    return top == 0;
}

/* checks if the stack is full */
bool is_full(void)
{
    return top == STACK_SIZE;
}

/*
 * if the stack if full, then raise an overflow error
 * : otherwise set {ch} to the top & increment top index
 */
char push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

/* clears the stack */
void make_empty(void)
{
    top = 0;
}

/*
 * if the stack if empty, then raise an underflow error
 * : otherwise return the element at the top index & decrement top index
 */
char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

/* raises overflow flag */
void stack_overflow(void)
{
    flag_overflow = true;
    // printf("ERROR: Stack overflow");
    // exit(EXIT_FAILURE);
}

/* raises underflow flag */
void stack_underflow(void)
{
    flag_underflow = true;
    // printf("ERROR: Stack underflow");
    // exit(EXIT_FAILURE);
}

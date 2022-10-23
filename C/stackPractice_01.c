/* this was a program made to let me practice making a stack data structure with C from memory */
// estimated time of completion: 35 minutes
// this program is buggy with inputs greater than 1 character.
// it will serve as great practice with exception handling & input validation in the future.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_LEN 64

char stack[ARR_LEN] = {};
short int top = 0;

bool isFull(void);
bool isEmpty(void);
void push(char);
char pop(void);
void raiseStackOverflow(void);
void raiseStackUnderflow(void);

int main(void)
{
    char inp;

    for (;;)
    {
        printf("\n------------------------\n");
        printf("|Current Stack Contents|\n");
        printf("------------------------\n");

        for (int i = 0; i < ARR_LEN; i++)
            putchar(stack[i]);
        printf("\n\n");

        printf("[1] Push\n[2] Pop\n[3] Exit\n\nCommand: ");
        scanf(" %c", &inp);

        switch (inp)
        {
            char x;

            case '1':
                printf("Enter a character to push: ");
                scanf(" %c", &x);
                push(x);
                break;
            case '2':
                printf("Pop! %c\n", pop());
                break;
            case '3':
                printf("Exiting program, enter any key to continue... ");
                scanf(" %c");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("ERROR 003: Unexpected Error.\nExiting program...");
                exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}

void push(char ch)
{
    if (!isFull())
        stack[top++] = ch;
    else
        raiseStackOverflow();
}

char pop(void)
{
    if (!isEmpty())
    {
        char buffer;
        buffer = stack[--top];
        stack[top] = '\0';

        return buffer;
    }
    else
        raiseStackUnderflow();
}

bool isFull(void)
{
    return top == ARR_LEN;
}

bool isEmpty(void)
{
    return top == 0;
}

void raiseStackOverflow(void)
{
    printf("\nERROR 001: Stack Overflow.\nExiting program...");
    exit(EXIT_FAILURE);
}

void raiseStackUnderflow(void)
{
    printf("\nERROR 002: Stack Underflow.\nExiting program...");
    exit(EXIT_FAILURE);
}

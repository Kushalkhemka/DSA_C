#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Stack structure
typedef struct {
    char *array;  // Store char instead of int
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int n) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->array = (char*)malloc(sizeof(char) * n);
    s->top = -1;
    s->capacity = n;
    return s;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return (s->top == -1);
}

// Check if stack is full
int isFull(Stack* s) {
    return (s->top == s->capacity - 1);
}

// Push element onto stack
void push(Stack* s, char data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->array[++s->top] = data;
}

// Pop element from stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->array[s->top--];
}

// Peek top element of stack
char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->array[s->top];
}

// Free allocated memory for stack
void freeStack(Stack* s) {
    free(s->array);
    free(s);
}

// Function to determine precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
void InfixToPostfix(char exp[]) {
    Stack* s = createStack(strlen(exp) + 1);
    char postfix[strlen(exp) + 1];
    int j = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isalnum(c)) {
            // Operand
            postfix[j++] = c;
        } else if (c == '(') {
            push(s, '(');
        } else if (c == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            pop(s);  // Remove '(' from stack
        } else {
            while (!isEmpty(s) &&
                   (precedence(peek(s)) > precedence(c) ||
                    (precedence(peek(s)) == precedence(c) && c != '^'))) {
                postfix[j++] = pop(s);
            }
            push(s, c);
        }
    }

    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    freeStack(s);
}

float evalexp(float o1, float o2, char operator) {
    if (operator == '*') return o2 * o1;
    if (operator == '+') return o2 + o1;
    if (operator == '-') return o2 - o1;
    if (operator == '/') return o2 / o1;
    if (operator == '^') return pow(o2, o1);
    return 0;
}

float evalPostfix(char postexp[]) {
    Stack *s = createStack(strlen(postexp));
    int i = 0;
    while (postexp[i] != '\0') {
        char c = postexp[i];
        if (isdigit(c)) {
            push(s, c - '0'); // Convert char to int
        } else {
            float o1 = pop(s);
            float o2 = pop(s);
            float temp = evalexp(o1, o2, c);
            push(s, temp);
        }
        i++;
    }
    float result = pop(s);
    freeStack(s);
    return result;
}


int main() {
    char postfix[] = "23*54*+9-"; // Example: (2 * 3) + (5 * 4) - 9
    printf("Postfix Expression: %s\n", postfix);
    float result = evalPostfix(postfix);
    printf("Evaluated Result: %.2f\n", result);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct KStacks {
    int *top, *arr, *next;
    int K, cap, free_top;
} KStacks;

// Function to initialize K Stacks
KStacks* initializeKStacks(int K, int cap) {
    KStacks *S = malloc(sizeof(KStacks));
    S->top = (int*) malloc(sizeof(int) * K);
    S->next = (int*) malloc(sizeof(int) * cap);
    S->arr = (int*) malloc(sizeof(int) * cap);
    S->cap = cap;
    S->free_top = 0;
    S->K = K;

    // Initialize all stacks as empty
    for (int i = 0; i < K; i++) {
        S->top[i] = -1;
    }

    // Initialize free list
    for (int i = 0; i < cap - 1; i++) {
        S->next[i] = i + 1;
    }
    S->next[cap - 1] = -1;

    return S;
}

// Push function with boundary check
int push(KStacks *s, int sn, int data) {
    if (s->free_top == -1) {
        printf("Stack Overflow! No space left.\n");
        return 0;
    }

    int i = s->free_top;          // Get the free index
    s->arr[i] = data;             // Store the data
    s->free_top = s->next[i];     // Move `free_top` to the next free slot
    s->next[i] = s->top[sn];      // Link new element to the previous top
    s->top[sn] = i;               // Update `top` for stack `sn`

    return 1;
}

// Pop function with boundary check
int pop(KStacks *s, int sn) {
    if (s->top[sn] == -1) {
        printf("Stack Underflow! Stack %d is empty.\n", sn);
        return -1;
    }

    int i = s->top[sn];          // Get top element index
    int poppedValue = s->arr[i]; // Store popped value
    s->top[sn] = s->next[i];     // Update top to the next element
    s->next[i] = s->free_top;    // Add this index to the free list
    s->free_top = i;

    return poppedValue;
}

// Function to check if a stack is empty
int isEmpty(KStacks *s, int sn) {
    return s->top[sn] == -1;
}

// Function to print the stacks visually
void printStacks(KStacks *s) {
    printf("\n=== Stack Visualization ===\n");

    for (int i = 0; i < s->K; i++) {
        printf("Stack %d: ", i);
        int index = s->top[i];

        if (index == -1) {
            printf("Empty\n");
            continue;
        }

        while (index != -1) {
            printf("%d ", s->arr[index]);
            index = s->next[index];
            if (index != -1) {
                printf("-> ");
            }
        }
        printf("\n");
    }

    // Show memory representation
    printf("\n=== Internal Representation ===\n");
    printf("arr:  ");
    for (int i = 0; i < s->cap; i++) {
        printf("%2d ", s->arr[i]);
    }
    printf("\nnext: ");
    for (int i = 0; i < s->cap; i++) {
        printf("%2d ", s->next[i]);
    }
    printf("\ntop:  ");
    for (int i = 0; i < s->K; i++) {
        printf("%2d ", s->top[i]);
    }
    printf("\nfree_top: %d\n", s->free_top);
}

// Driver Code
int main() {
    KStacks *Stack = initializeKStacks(3, 5);

    // Test push operations
    push(Stack, 0, 10);
    push(Stack, 0, 20);
    push(Stack, 1, 30);
    push(Stack, 2, 40);
    push(Stack, 2, 50);

    printStacks(Stack); // Print initial state

    // Test pop operations


    printf("\nPopped from Stack 0: %d\n", pop(Stack, 0));
    printf("Popped from Stack 1: %d\n", pop(Stack, 1));
    printf("Popped from Stack 2: %d\n", pop(Stack, 2));

    printStacks(Stack); // Print after popping //we update top but don't remove from array due to which internal representation remains the same

    // Free allocated memory
    free(Stack->top);
    free(Stack->next);
    free(Stack->arr);
    free(Stack);

    return 0;
}

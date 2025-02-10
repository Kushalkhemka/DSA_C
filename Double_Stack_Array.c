#include <stdio.h>

#define MAXSIZE 20
struct stack {
    int array[MAXSIZE];
    int top1;
    int top2;
};

int peek1(struct stack *s) {
    return s->array[s->top1];
}

int peek2(struct stack *s) {
    return s->array[s->top2];
}

void push1(struct stack *s, const int value) {
    if(s->top1==s->top2-1) {
        printf("Overflow! of Stack 1");
    }else {
        s->top1++;
        s->array[s->top1]=value;
    }
}

void push2(struct stack *s, const int value) {
    if(s->top1==s->top2-1) {
        printf("Overflow! of Stack 2");
    }else {
        s->top2--;
        s->array[s->top2]=value;
    }
}


int pop2(struct stack *s) {
    if(s->top2>MAXSIZE-1) {
        printf("Underflow of Stack 2!");
        return -1;
    }
    const int ele = s->array[s->top2];
    s->top2++;
    return ele;
}

int pop1(struct stack *s) {
    if(s->top1<0) {
        printf("Underflow of Stack 1!");
        return -1;
    }
    const int ele = s->array[s->top1];
    s->top1--;
    return ele;
}

void print_stack(struct stack *s) {
    printf("Stack 1: ");
    for (int i = 0; i <= s->top1; i++) {
        printf("%d ", s->array[i]);
    }
    printf("\nStack 2: ");
    for (int i = MAXSIZE-1; i >=s->top2; i--) {
        printf("%d ", s->array[i]);
    }
    printf("\n");
}

int main() {
    struct stack s;
    s.top1 = -1;
    s.top2 = MAXSIZE;

    push1(&s, 10);
    push1(&s, 20);
    push1(&s, 30);
    push1(&s, 5);
    push1(&s, 6);
    push2(&s, 50);
    push2(&s, 70);


    printf("Top element is stack 1: %d\n", peek1(&s)); // Output: 30
    printf("Popped element of Stack 2: %d\n", pop1(&s));  // Output: 30
    // printf("Popped element: %d\n", pop1(&s));  // Output: 20
    // printf("Popped element: %d\n", pop1(&s));  // Output: 10
    // printf("Popped element: %d\n", pop2(&s));  // Output: Underflow!
    printf("Top element of stack 2 is: %d\n", peek2(&s));
    print_stack(&s);

    return 0;
}

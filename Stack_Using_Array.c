#include <stdio.h>

#define MAXSIZE 20
struct stack {
    int array[MAXSIZE];
    int top;
    int min;
};

int peek(struct stack *s) {
    return s->array[s->top];
}

int min_element_traverse(struct stack *s) {
    int min_ele=s->top;
    for(int i=s->top;i>=0;i--) {
        if(s->array[i]<min_ele) {
            min_ele=s->array[i];
        }
    }
    return min_ele;
}


void push(struct stack *s, const int value) {
    if(s->top>=MAXSIZE-1) {
        printf("Overflow!");
    }else {
        s->top++;
        s->array[s->top]=value;
    }
}

int pop(struct stack *s) {
    if(s->top<0) {
        printf("Underflow!");
        return -1;
    }
    const int ele = s->array[s->top];
    s->top--;
    return ele;
}

int main() {
        struct stack s;
        s.top = -1;

        push(&s, 10);
        push(&s, 20);
        push(&s, 30);


        printf("Top element is: %d\n", peek(&s)); // Output: 30
        printf("Popped element: %d\n", pop(&s));  // Output: 30
        printf("Popped element: %d\n", pop(&s));  // Output: 20
        printf("Popped element: %d\n", pop(&s));  // Output: 10
        printf("Popped element: %d\n", pop(&s));  // Output: Underflow!

        return 0;

}

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
struct stack {
    char array[MAXSIZE];
    int top;
    int min; //to find the min element in the stack
};

int isEmpty(struct stack *s) {
    return (s->top==-1);
}

int matching(char a, char b) {
    return ((a=='('&&b ==')' )|| (a=='[' && b==']') || (a=='{' && b== '}'));
}

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


int balanced_paranthesis(char arr[]) {
    struct stack s1;
    s1.top = -1;
    int i=0;
    while(arr[i]!='\0') {
        if(arr[i]=='[' || arr[i]=='{' || arr[i]=='(') {
            push(&s1,arr[i]);
        }
        else {
            if(s1.top<0) {
                return 0; //underflow
            }
            if(!matching(s1.array[s1.top],arr[i])) {
                return 0;
            }
            pop(&s1);
        }
        i++;
    }
    return 1;
}

void stock_span(int arr[], int size) {
    struct stack s1;;
    s1.top = -1;
    push(&s1,0);
    printf("%d",1);

    for(int i=1;i<size;i++) {
        while(!isEmpty(&s1) && arr[s1.array[s1.top]]<=arr[i]) {
            pop(&s1);
        }
        int span = isEmpty(&s1)?(i+1):(i-s1.array[s1.top]);
        printf("Span of %d is %d\n",arr[i],span);
        push(&s1,i);

    }
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
        printf("%d \n",balanced_paranthesis("(({({}[()])}))"));
        int arr[] = {13,15,12,14,16,8,6,10,30};
        stock_span(arr,9);
        return 0;

}

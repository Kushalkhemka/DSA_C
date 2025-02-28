#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
struct stack {
    char array[MAXSIZE];
    int top;
    int min;
};

struct MinStack {
    struct stack s;
    struct stack ms;
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

int isFull(struct stack *s) {
    return (s->top==MAXSIZE-1);
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

void pushMin(struct MinStack* ms, int data) {
    push(&(ms->s),data);

    if(isEmpty(&(ms->ms))||(ms->ms.array[ms->ms.top])>=data) {
        push(&(ms->ms),data);
    }
}

void pushMinEff(struct stack *s, int data) {
    if (isFull(s)) {
        printf("Overflow!\n");
        return;
    }

    if (isEmpty(s)) {
        s->min = data;
        push(s, data);
    } else if (data < s->min) {
        // Push the difference as an encoded value
        push(s, data - s->min);
        s->min = data;
    } else {
        push(s, data);
    }
}

// **Space Efficient Pop**
int popMinEff(struct stack *s) {
    if (isEmpty(s)) return INT_MIN;

    int x = pop(s);
    if (x < 0) {  // Encoded value
        int originalMin = s->min;
        s->min = originalMin - x;  // Restore previous min
        return originalMin;
    }
    return x;
}

void pushMinEff2(struct stack* s, int data) {
    if(isEmpty(s)) {
        s->min = data;
        push(s,data);
    }
    else if(data<=s->min) {
        push(s,2*data-s->min);
        s->min=data;
    }
    else {
        push(s,data);
    }
}

int popMinEff2(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }

    int temp = pop(s);
    if(temp<=s->min) {
        int oldMin=s->min;
        s->min=2*s->min-temp;
        return oldMin;
    }
    return temp;
}

int peekMinEff(struct stack*s) {
    int x=peek(s);
    return (x<=s->min)?s->min:x;
}

// **Get Minimum**
int getMinEff(struct stack *s) {
    if (isEmpty(s)) return INT_MIN;
    return s->min;
}
int popMin(struct MinStack* ms) {
    if (isEmpty(&(ms->s))) return INT_MIN;
    int x = pop(&(ms->s));
    if (x==ms->ms.array[ms->ms.top]) {
        pop(&(ms->ms));
    }
    return x;
}

int getMin(struct MinStack *ms) {
    if(isEmpty(&ms->ms)) return INT_MIN;
    return (ms->ms.array[ms->ms.top]);
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

void prev_greater_ele(int arr[],int size) {
    struct stack s1;;
    s1.top = -1;
    push(&s1,arr[0]);
    printf("%d",-1);

    for(int i=1;i<size;i++) {
        while(!isEmpty(&s1) && s1.array[s1.top]<=arr[i]) {
            pop(&s1);
        }

        // int span = isEmpty(&s1)?(i+1):(i-s1.array[s1.top]);
        if (!isEmpty(&s1)) {
            printf("Nearest greater element of %d is %d\n",arr[i],s1.array[s1.top]);
        }
        else {
            printf("Nearest greater element of %d is %d\n",arr[i],-1);
        }
        push(&s1,arr[i]); //push bigger element

    }
}

void next_greater_ele(int arr[],int size) {
    struct stack s1;;
    s1.top = -1;
    push(&s1,arr[size-1]);
    printf("NEXT GREATER ELEMENTS \n");
    int arr5[size]; //use to it to print in reverse order so O(2n) -> O(n) time complexity with O(2n) space complexity.
    for(int i=size-1;i>=0;i--) {
        while(!isEmpty(&s1) && s1.array[s1.top]<=arr[i]) {
            pop(&s1);
        }

        // int span = isEmpty(&s1)?(i+1):(i-s1.array[s1.top]);
        if (!isEmpty(&s1)) {
            printf("Nearest greater element of %d is %d\n",arr[i],s1.array[s1.top]);
        }
        else {
            printf("Nearest greater element of %d is %d\n",arr[i],-1);
        }
        push(&s1,arr[i]); //push bigger element

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
        int arr1[]={15,10,18,12,4,6,2,8};
        prev_greater_ele(arr1,8);
        int arr2[]={5,15,10,8,6,12,9,18};
        next_greater_ele(arr2,sizeof(arr2)/sizeof(int));
        stock_span(arr,9);


        //getmin() Min stack
        struct MinStack ms;
        ms.s.top = -1;
        ms.ms.top = -1;

        pushMin(&ms, 10);
        pushMin(&ms, 5);
        pushMin(&ms, 8);
        pushMin(&ms, 2);
        pushMin(&ms, 12);

        printf("Current Min: %d\n", getMin(&ms));  // Output: 2

        popMin(&ms);
        printf("Current Min: %d\n", getMin(&ms));  // Output: 2

        popMin(&ms);
        printf("Current Min: %d\n", getMin(&ms));  // Output: 5

        struct stack s3;
        s3.top = -1;

        pushMinEff(&s3, 10);
        pushMinEff(&s3, 5);
        pushMinEff(&s3, 8);
        pushMinEff(&s3, 2);
        pushMinEff(&s3, 12);

        printf("Min: %d\n", getMinEff(&s3));  // Output: 2

        popMinEff(&s3);
        printf("Min: %d\n", getMinEff(&s3));  // Output: 5

        popMinEff(&s3);
        printf("Min: %d\n", getMinEff(&s3));  // Output: 5

        popMinEff(&s3);
        printf("Min: %d\n", getMinEff(&s3));  // Output: 10

        struct stack s6;
        s6.top = -1; // Initialize stack

        printf("Pushing elements: 5, 3, 7, 2\n");
        pushMinEff2(&s6, 5);
        printf("Minimum: %d | Peek: %d\n", getMinEff(&s6), peekMinEff(&s6));

        pushMinEff2(&s6, 3);
        printf("Minimum: %d | Peek: %d\n", getMinEff(&s6), peekMinEff(&s6));

        pushMinEff2(&s6, 7);
        printf("Minimum: %d | Peek: %d\n", getMinEff(&s6), peekMinEff(&s6));

        pushMinEff2(&s6, 2);
        printf("Minimum: %d | Peek: %d\n", getMinEff(&s6), peekMinEff(&s6));

        printf("\nPopping elements...\n");

        printf("Popped: %d | New Min: %d | Peek: %d\n", popMinEff2(&s6), getMinEff(&s6), peekMinEff(&s6));
        printf("Popped: %d | New Min: %d | Peek: %d\n", popMinEff2(&s6), getMinEff(&s6), peekMinEff(&s6));
        printf("Popped: %d | New Min: %d | Peek: %d\n", popMinEff2(&s6), getMinEff(&s6), peekMinEff(&s6));
        printf("Popped: %d | New Min: %d | Peek: %d\n", popMinEff2(&s6), getMinEff(&s6), peekMinEff(&s6));

        printf("\nTrying to pop from empty stack...\n");
        printf("Popped: %d\n", popMinEff2(&s6));  // Should print stack underflow


        return 0;

}

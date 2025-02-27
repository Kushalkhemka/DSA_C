#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    vector<int> v;
    vector<int> min;
    int top;
}stack;

int peek(const stack *s) {
    return s->v.back();
}

// int min_element_traverse(struct stack *s) {
//     int min_ele=s->top;
//     for(int i=s->top;i>=0;i--) {
//         if(s->array[i]<min_ele) {
//             min_ele=s->array[i];
//         }
//     }
//     return min_ele;
// }


void push(stack *s, const int value) {
        s->top++;
        s->v.push_back(value);
}

int pop(stack *s) {
    if(s->v.empty()) {
        printf("Underflow! ");
        return -1;
    }
    const int ele = s->v.back();
    s->v.pop_back();
    s->top--;
    return ele;
}

int main() {
    stack s;
    s.top = -1;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);


    printf("Top element is: %d\n", peek(&s)); // Output: 30
    printf("Popped element: %d\n", pop(&s));  // Output: 30
    printf("Popped element: %d\n", pop(&s));  // Output: 20
    printf("Popped element: %d\n", pop(&s));  // Output: 10
    printf("%d\n", pop(&s));  // Output: Underflow!

    return 0;

}

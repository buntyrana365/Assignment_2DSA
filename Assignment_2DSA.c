#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum capacity of the stack

// Structure to represent a Stack
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Helper function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Helper function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// PUSH Operation: Inserts an element onto the top of the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("[ERROR] Stack Overflow! Cannot push %d. Stack is full (Capacity: %d).\n", value, MAX);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("[SUCCESS] Pushed %d into the stack. Current top index: %d\n", value, s->top);
}

// POP Operation: Removes and returns the top element of the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("[ERROR] Stack Underflow! Cannot pop. Stack is empty.\n");
        return -1; // Error code indicating stack is empty
    }
    int poppedValue = s->items[s->top];
    s->top--;
    printf("[SUCCESS] Popped %d from the stack. New top index: %d\n", poppedValue, s->top);
    return poppedValue;
}

// PEEK Operation: Retrieves the top element without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("[ERROR] Stack Underflow! Stack is empty. Nothing to peek.\n");
        return -1;
    }
    printf("[INFO] Top element (PEEK): %d\n", s->items[s->top]);
    return s->items[s->top];
}

// DISPLAY Operation: Prints all elements from top to bottom
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("[INFO] Stack is empty: []\n");
        return;
    }
    printf("[INFO] Stack elements (Top -> Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d]", s->items[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    printf("=========================================\n");
    printf("     STACK IMPLEMENTATION USING ARRAY    \n");
    printf("=========================================\n\n");

    printf("--- 1. Testing Initial Empty Stack ---\n");
    display(&s);
    peek(&s);
    pop(&s); // Triggers Stack Underflow

    printf("\n--- 2. Testing PUSH Operations ---\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    display(&s);

    printf("\n--- 3. Testing STACK OVERFLOW ---\n");
    push(&s, 60); // Triggers Stack Overflow because MAX is 5

    printf("\n--- 4. Testing PEEK Operation ---\n");
    peek(&s);

    printf("\n--- 5. Testing POP Operations ---\n");
    pop(&s);
    pop(&s);
    display(&s);

    printf("\n--- 6. Testing STACK UNDERFLOW after clearing ---\n");
    pop(&s);
    pop(&s);
    pop(&s);
    display(&s);
    pop(&s); // Triggers Stack Underflow again

    return 0;
}
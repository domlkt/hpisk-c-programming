#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    Node* temp = s->top;
    int poppedValue = temp->data;

    s->top = s->top->next;
    free(temp);

    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    
    return s->top->data;
}

// Function to display the elements in the stack
void displayStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    Node* temp = s->top;
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function for testing
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    displayStack(&s);

    printf("Top element: %d\n", peek(&s));

    pop(&s);
    pop(&s);

    displayStack(&s);

    return 0;
}

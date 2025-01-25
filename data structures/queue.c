#include <stdio.h>
#include <stdlib.h>


/*
     Queue:
     
      ____________ ____         ____________ ____              ____________ ____
     |            |    |       |            |    |            |            |    |
     |            |    |       |            |    |            |            |    |
     |            | |--------->|            | |---------> ... |            | |---------> NULL   
     |            |    |       |            |    |            |            |    |
     |____________|____|       |____________|____|            |____________|____| 

           front                                                     back


*/




// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct Queue {
    Node* front;
    Node* back;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = q->back = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->back == NULL) {
        q->front = q->back = newNode; // The first node
        return;
    }
    
    q->back->next = newNode;
    q->back = newNode;
    printf("Enqueued %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int dequeuedValue = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->back = NULL; // Queue becomes empty
    }

    free(temp);
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the elements in the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function for testing
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    displayQueue(&q);
    
    dequeue(&q);
    dequeue(&q);
    
    displayQueue(&q);

    return 0;
}

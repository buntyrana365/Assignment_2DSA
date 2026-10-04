#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Maximum capacity of the queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Check if the queue is full
bool isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// ENQUEUE: Insert an element into the circular queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d (Queue is Full).\n", value);
        return;
    }
    
    // If inserting the first element
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX; // Circular increment
    }
    
    q->items[q->rear] = value;
    printf("Successfully enqueued: %d\n", value);
}

// DEQUEUE: Remove an element from the circular queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue (Queue is Empty).\n");
        return -1;
    }

    int value = q->items[q->front];

    // If only one element was left in the queue, reset queue to empty
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Circular increment
    }

    printf("Successfully dequeued: %d\n", value);
    return value;
}

// FRONT: Peek at the front element of the queue
int peekFront(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! No front element.\n");
        return -1;
    }
    return q->items[q->front];
}

// DISPLAY: Print all elements from FRONT to REAR in circular order
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Circular Queue elements [Front = %d, Rear = %d]: ", q->front, q->rear);
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    int choice, value;

    printf("=========================================\n");
    printf("   CIRCULAR QUEUE IMPLEMENTATION IN C    \n");
    printf("=========================================\n");

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                value = peekFront(&q);
                if (value != -1) {
                    printf("Front Element: %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct {
    char data[SIZE][50];
    int front;
    int rear;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->front = -1;
    cb->rear = -1;
}

int isEmpty(CircularBuffer *cb) {
    return cb->front == -1;
}


int isFull(CircularBuffer *cb) {
    return (cb->rear + 1) % SIZE == cb->front;
}


void enqueue(CircularBuffer *cb, char value[]) {
    if (isFull(cb)) {
        printf("Overflow! Buffer is full.\n");
        return;
    }

    if (isEmpty(cb)) {
        cb->front = 0;
    }

    cb->rear = (cb->rear + 1) % SIZE;
    strcpy(cb->data[cb->rear], value);

    printf("Inserted: %s\n", value);
}


void dequeue(CircularBuffer *cb, char result[]) {
    if (isEmpty(cb)) {
        printf("Underflow! Buffer is empty.\n");
        return;
    }

    strcpy(result, cb->data[cb->front]);

    if (cb->front == cb->rear) {
        cb->front = cb->rear = -1;
    } else {
        cb->front = (cb->front + 1) % SIZE;
    }
}


void display(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer is empty\n");
        return;
    }

    int i = cb->front;
    printf("Buffer contents: ");

    while (1) {
        printf("%s | ", cb->data[i]);
        if (i == cb->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];
    char fullText[50];
    char removed[50];

    
    printf("Enter your name: ");
    scanf("%s", name);

  
    sprintf(fullText, "%s-CE-ESY", name);

    
    enqueue(&cb, fullText);

    
    printf("\nAfter insertion:\n");
    display(&cb);

    
    printf("\nReading from buffer:\n");
    while (!isEmpty(&cb)) {
        dequeue(&cb, removed);
        printf("Removed: %s\n", removed);
    }

  
    printf("\nAfter removing all elements:\n");
    display(&cb);

    return 0;
}

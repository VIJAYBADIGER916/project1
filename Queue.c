#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for(int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if(value != -1)
                    printf("Popped: %d\n", value);
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

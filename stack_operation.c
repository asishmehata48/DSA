#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE], top = -1;

// Push operation
void push(int value) {
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}

// Peek operation
void peek() {
    if (top == -1)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

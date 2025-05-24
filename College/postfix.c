#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Stack operations
void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // Skip whitespaces
        if (ch == ' ')
            continue;

        // If digit, push to stack
        if (isdigit(ch)) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; // Adjust for loop increment
            push(&s, num);
        } 
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': push(&s, pow(val1, val2)); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    return pop(&s);
}

// Main function
int main() {
    char expr[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+9-): ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0;  // Remove newline

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100
#define MAX_STACK_SIZE 100

typedef struct Stack {
    char urls[MAX_STACK_SIZE][MAX_URL_LENGTH];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push a URL onto the stack
void push(Stack* stack, const char* url) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->top++;
        strcpy(stack->urls[stack->top], url);
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop a URL from the stack
char* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->urls[stack->top--];
    } else {
        return NULL;
    }
}

// Function to get the top URL of the stack without popping
char* peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->urls[stack->top];
    } else {
        return NULL;
    }
}

int main() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);

    char currentPage[MAX_URL_LENGTH] = "";
    char url[MAX_URL_LENGTH];
    char action[10];

    while (1) {
        printf("Enter a URL to visit (or type 'exit' to quit): ");
        scanf("%s", url);

        if (strcmp(url, "exit") == 0) {
            break;
        }

        // If we are visiting a new page, push the current page to the back stack
        if (strlen(currentPage) > 0) {
            push(&backStack, currentPage);
            // Clear the forward stack since we are visiting a new page
            initStack(&forwardStack);
        }

        // Visit the new page
        strcpy(currentPage, url);
        printf("Visited: %s\n", currentPage);
        printf("Current Page: %s\n", currentPage);

        // Handle navigation actions
        while (1) {
            printf("Action (Go Back, Go Forward, or type 'visit' to visit a new page): ");
            scanf("%s", action);

            if (strcmp(action, "Go Back") == 0) {
                if (!isEmpty(&backStack)) {
                    push(&forwardStack, currentPage); // Save current page to forward stack
                    strcpy(currentPage, pop(&backStack)); // Go back
                    printf("Current Page: %s\n", currentPage);
                } else {
                    printf("No pages to go back to.\n");
                }
            } else if (strcmp(action, "Go Forward") == 0) {
                if (!isEmpty(&forwardStack)) {
                    push(&backStack, currentPage); // Save current page to back stack
                    strcpy(currentPage, pop(&forwardStack)); // Go forward
                    printf("Current Page: %s\n", currentPage);
                } else {
                    printf("No pages to go forward to.\n");
                }
            } else if (strcmp(action, "visit") == 0) {
                break; // Exit the inner loop to visit a new page
            } else {
                printf("Invalid action. Please try again.\n");
            }
        }
    }

    return 0;
}

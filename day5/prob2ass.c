#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_LENGTH 100
#define MAX_STACK_SIZE 100

typedef struct Stack {
    char items[MAX_STACK_SIZE][MAX_ITEM_LENGTH];
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

// Function to push an item onto the stack
void push(Stack* stack, const char* item) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->top++;
        strcpy(stack->items[stack->top], item);
    } else {
        printf("Stack overflow! Cannot add more items.\n");
    }
}

// Function to pop an item from the stack
char* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        return NULL;
    }
}

// Function to display remaining stock
void displayStock(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No remaining stock.\n");
    } else {
        printf("Remaining Stock: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%s", stack->items[i]);
            if (i < stack->top) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    Stack stock;
    initStack(&stock);

    char item[MAX_ITEM_LENGTH];
    char action[10];

    while (1) {
        printf("Enter an item to add to stock (or type 'dispatch' to dispatch an item, 'exit' to quit): ");
        scanf("%s", item);

        if (strcmp(item, "exit") == 0) {
            break;
        } else if (strcmp(item, "dispatch") == 0) {
            if (!isEmpty(&stock)) {
                char* dispatchedItem = pop(&stock);
                printf("Dispatching Item: %s\n", dispatchedItem);
            } else {
                printf("No items to dispatch.\n");
            }
        } else {
            push(&stock, item);
            printf("Stock Added: %s\n", item);
        }

        displayStock(&stock);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 1000000

typedef struct{
    int arr[MAX_SIZE];
    int top;
}Stack;

void initStack(Stack *stack){
    stack->top=-1;
}
int isEmpty(Stack *stack){
    return stack->top==-1;
}
int isFull(Stack *stack){
    return stack->top == MAX_SIZE-1;
}
void push(Stack *stack,int value){
    if(isFull(stack)){
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top]=value;
}
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
int top(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}


// Function to check if the parentheses match
bool isBalanced(char *str) {
    Stack st;
    initStack(&st);
    int n=strlen(str);
    if (str[0] == ']' || str[0] == '}' || str[0] == ')')
        return false;
    for (int i = 0; i <n ; i++) {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
            push(&st, str[i]);
        } else {
            if (isEmpty(&st))
                return false;
            char top_char = pop(&st);
            if ((top_char == '[' && str[i] != ']') ||
                (top_char == '{' && str[i] != '}') ||
                (top_char == '(' && str[i] != ')')) {
                return false;
            }
        }
    }
    return isEmpty(&st);
}

int main() {
    char str[MAX_SIZE];

    scanf("%s", str);
    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

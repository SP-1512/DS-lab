#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int item) 
{
    if (top >= MAX - 1) 
	{
        printf("Stack Overflow. Cannot push %d\n", item);
        return;
    }
    stack[++top] = item;  
    printf("%d pushed onto stack\n", item);
}
int pop() 
{
    if (top < 0) 
	{
        printf("Stack Underflow. Cannot pop.\n");
        return -1;  
    }
    int poppedItem = stack[top--]; 
    return poppedItem;
}
int peek() 
{
    if (top < 0) 
	{
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}
int main() 
{
    push(10);
    push(20);
    push(30);
    printf("Current top element: %d\n", peek());
    printf("%d popped from stack\n", pop());
    printf("Now the top element is: %d\n", peek());
    return 0;
}

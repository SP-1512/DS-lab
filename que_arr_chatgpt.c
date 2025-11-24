#include <stdio.h>
#define MAX 100 
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value) 
{
    if (rear == MAX - 1) 
	{
        printf("Queue Overflow. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1)
        front = 0;
    rear++;             
    queue[rear] = value;
    printf("%d enqueued into the queue.\n", value);
}
int dequeue() 
{
    if (front == -1 || front > rear) 
	{
        printf("Queue Underflow. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = queue[front]; 
    front++;     
    if (front > rear)
        front = rear = -1;
    return dequeuedValue;
}
int peek() 
{
    if (front == -1) 
	{
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}
int main() 
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Front element is: %d\n", peek());
    printf("%d dequeued from the queue.\n", dequeue());
    printf("Front element is now: %d\n", peek());
    return 0;
}

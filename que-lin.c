//queue using arrays
#include<stdio.h>
#define max 5
int queue[max];
int front=-1;
 int rear= -1;
void enqueue()
{
	int value;
	printf("enter value:");
	scanf("%d",&value);
	if(rear==max-1)
	{
		printf("\nqueue is full overflow");
	}
	else if(front==-1&& rear==-1)
	{
		rear=front=0;
		queue[rear]=value;
	}
	else
	{
		rear++;
		queue[rear]=value;
	}
}
void dequeue()
{
	if(rear==-1 && front ==-1)
	{
		printf("\nqueue is underflow not full");
	}
	else if(front==rear)
	{
		front=rear=-1;
		printf("\n queue is empty");
	}
	else
	{
		printf("\n%d is removed",queue[front]);
		front++;
	}
}
void peek()
{
   if(rear==-1 && front ==-1)
	{
		printf("\nqueue is underflow not full");
	}
	else
	{
	 printf("\nfront is:%d",queue[front]);	
	}	
}
void display()
{
	int i;
   if(rear==-1 && front ==-1)
	{
		printf("\nqueue is underflow not full");
	}
	else
	{
		printf("queue elements are:");
	for(i=front;i<=rear;i++)
	{
	printf("%d\t",queue[i]);	
	}	
	}	
}


int main()
{
 int ch;
 while(1)
 {
 	printf("\n1.enqueue\n2.dequeue\n3.peek\n4.display\nenter your choice:");
 	scanf("%d",&ch);
 	{
 		switch(ch)
 		{
 		case 1:
 			{
 				enqueue();
 				break;
			 }
			 case 2:
 			{
 				dequeue();
 				break;
			 }
			 case 3:
 			{
 				peek();
 				break;
			 }
			 case 4:
 			{
 				display();
 				break;
			 }
			default:
				printf("choice is wrong");
	 }
	 }	
}
}

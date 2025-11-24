#include<stdio.h> 
#include<stdlib.h> 
typedef struct stack 
{     
	int data; 
 	struct stack *next; 
} 
STACK; 
STACK*top=NULL; 
int count=0; 
void push(int); 
int pop(); 
int peek(); 
void display(); 
void push(int info) 
{    
	STACK*newnode=(STACK*)malloc(sizeof(STACK)); 
 	if(newnode==NULL) 
 	{     
	 	printf("Stack overflow"); 
 	 	return ; 
 	} 
 	newnode->data=info;  	
	newnode->next=NULL;  	
	if(top==NULL)  	
	top=newnode;  	
	else 
 	{     
	 newnode->next=top; 
 	 	top=newnode; 
 	} 
	 count++; 
 	printf("%d is pushed to stack\n",info); 
} 
int pop() 
{     
	int ele; 
	if(top==NULL) 
	{     
		printf("underflow"); 
	 	return -1; 
 	} 
 	else 
 	{           
	 	STACK *temp=top; 
 	 	top=top->next;  	 	
		  ele=temp->data;  	 	
		  count--;  	 	
		  free(temp);  	 	
		  return ele; 
 	} 
} 
int peek() 
{      
if(top==NULL) 
 	{           
	 printf("underflow"); 
 	 	return -1; 
 	} 
 	else 
 	{      
	 return top->data; 
 	} 
} 
void display() 
{         
if(top==NULL) 
 	printf("empty\n"); 
 	else 
 	{          
	 STACK *temp=top;  	 	
	 printf("\n*stack elements*\n");  	
	 while(temp!=NULL) 
	 	{          
		 printf("\t%d\n",temp->data); 
	 	 	temp=temp->next; 
 	 	} 
 	} 
} 
int main() 
{        
	int ch,x; 
 	do 
 	{           
	 printf("\n1.Push\n2.Pop\n3.Peek\n 4.Display\n5.To exit"); 
 	 	printf("\nenter your choice");  	 	
		  scanf("%d",&ch);  	 	
		  switch(ch) 
 	 	{            
		case 1: 
			printf("\n enter element:"); 
 	 	 	        scanf("%d",&x);  	 	 	        
					   push(x); break;  	 	 	
		case 2: 
					x=pop();  	 	 	        
					if(x!=-1) 
 	 	 			{    
					   printf("popped element is %d\n",x); 
 	 	 	        break; 	
					}  	 	 	
		case 3: 
					x=peek();  	 	 	        
					if(x!=-1)
					{ 
 	 	 	        printf("top most element is %d\n",x); 
           			break ;
		   			}    
		case 4: 
					display(); 
					break;    
		case 5: 
				exit(0); 
 	 	 	default: printf("\n invalid choice"); 
 	 	} 
	} 
	while(1); 
	return 0; 
}


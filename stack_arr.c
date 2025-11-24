#include<stdio.h> 
#include<stdlib.h> 
#define SIZE 5  
int top=-1; 
int stack[SIZE]; 
void push(); 
int pop(); 
int peek(); 
void display(); 
void push(int ele) 
{   
if(top==SIZE-1) 
 	{   
	 printf("Overflow");  
	} 
 	else 
 	{       
	 top++;  stack[top]=ele;  
	} 
} 
int pop() 
{  int x; 
 	if(top==-1) 
 	{   
	 printf("underflow"); 
 	 	return -1;  
	}  	
	else 
 	{
	 top--;     
	 x=stack[top];  
	 
	} 	 
    return x ; 
} 
int peek() 
{     
int x; 
 	if(top==-1) 
 	{     
	 printf("underflow"); 
 	 	return -1; 
	}  	
	else 
 	{    
	 return stack[top]; 
	} 
} 
void display() 
{ 
int i; 
 	if(top==-1) 
 	{    
	 printf("underflow");  
	} 
 	else 
 	{    
	 printf(" stack elements: \n"); 
 	 	for(i=top;i>=0;i--) 
 	 	{     
		  printf("\t%d\n",stack[i]);  
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
		  case 1: printf("\n enter element:"); 
 	 	 	        scanf("%d",&x);  	 	 	        
					push(x); 
					break;  	 	 	
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
 	 	 	default: 
			   printf("\n invalid choice"); 
 	 	} 
	} 
 	while(1);  
 	return 0; 
} 


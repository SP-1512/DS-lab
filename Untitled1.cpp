#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void create_list();
struct node *create_node();
void display();
void insert_beg();
void insert_last();
void insert_anywhere();
struct node *head=NULL,*end=NULL;
int count=0;
struct node *create_node()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("can't allocate memory\n");
		
	}
	printf("Enter  data into node\n");
	scanf("%d",&info);
	newnode->data=info;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void create_list()
{
	struct node *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}count++;
	printf("Node is created\n");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}printf("End full\n");
}
void insert_beg()
{
	
	struct node *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		head->next=newnode;
		newnode->prev=head;
		head=newnode;
	}count++;
	printf("Node is inserted at beg\n");
}
void insert_last()
{
	struct node *newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}count++;
	printf("Node is inserted at last\n");
}
int main()
{
	int ch;
	while(1)
	{
		printf("*****MENU*****\n");
		printf("\n1.create node\n2.display\n3.insert_beg\n4.insert_last");
		printf("Enetr choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create_node();
				break;
				case 2:
					display();
					break;
					case 3:
						insert_beg();
						break;
					case 4:
					insert_last();
					break;
					case 5:exit(0);
					default:
					
						printf("Invalid chioce\n");
									
		}
	}
}

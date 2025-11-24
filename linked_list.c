#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL, *end=NULL;
void create_nodes();
void display();
void insertfirst();
void insertlast();
void insert();
void deletefirst();
void deletelast();
void delete_any();
void search();
void replace();
int count;
void create_nodes()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n memory full");
	    return ;
	}
	printf("enter data into node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		end=newnode;
	} count++;
	printf("\n node created");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\n list is empty");
		return;
	} 
	temp=head;
	printf("\n list elements are...");
	do
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
void insert_first()
{
int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n memory full");
	    return ;
	}
	printf("enter data into node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=head;	
	head=newnode;
	count++;
	printf("\n node added at first");
}
void insert_last()
{
int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n memory full");
	    return ;
	}
	printf("enter data into node");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	end->next=newnode;	
	end=newnode;
	count++;
	printf("\n node added at first");
}
void insert()
{
	int i,info,pos;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory full");
		return;
	}
	printf("\n enter element");
	scanf("%d",&info);
	printf("\n enter position");
	scanf("%d",&pos);
	newnode->data=info;
	newnode->next=NULL;
	if(pos<0||pos>count+1)
	{
		printf("\n Invalid position");
		free(newnode);
		return;
	}
	struct node *temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
}
void deletefirst()
{
	if(head==NULL)
	{
		printf("empty list");
		return;
	}
	struct node *temp=head;
	head=head->next;
	free(temp);
	count--;
	printf("Node deleted");
}
void deletelast()
{
	if(head==NULL)
	{
		printf("empty list");
		return;
	}
	struct node *prev,*curr;
	curr=head;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	free(curr);
	end=prev;
	count--;
	printf("Node deleted");
}
void delete_any()
{ int pos,i;
	if(head==NULL)
	{
		printf("empty list");
		return;
	}
	printf("enter position");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("Invalid");
		return;
	}
	struct node *prev,*curr;
	curr=head;
	for(i=1;i<pos;i++)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	free(curr);
	count--;
	printf("Node deleted");
}
void search()
{
	if(head==NULL)
	{
		printf("empty list");
		return;
	}
	struct node *curr=head; int found,key;
	printf("enter the element to search");
	scanf("%d",&key);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("element found");
			return;
		}
		curr=curr->next;
	}printf("element not found");
}
void replace()
{
	if(head==NULL)
	{
		printf("empty list");
		return;
	}
	struct node *curr=head; int found,key,rep;
	printf("enter the element to be replaced");
	scanf("%d",&key);
	printf("enter the element to replace");
	scanf("%d",&rep);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			curr->data=rep;
			return;
		}
		curr=curr->next;
	}printf("element not found");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n*****MENU*****");
		printf("\n 1.create \n 2.display \n 3.To insert node at first \n 4.Insert node at last \n 5.Insert in specified location \n 6.Delete first node \n 7.Delete last node \n 8.Delete any node \n 9.search a node \n 10.To replace a node \n 11.To exit");
		printf("\n enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create_nodes();
					break;
			case 2: display();
						break;
			case 3: insert_first();
					break;
			case 4: insert_last();
			  		break;	
			case 5: insert();
			  		break;	
			case 6: deletefirst();
			  		break;
			case 7: deletelast();
			  		break;
			case 8: delete_any();
			  		break;
			case 9: search();
			  		break;
			case 10: replace();
			        break;
			case 11: exit(0);
			default:
				printf("\n invalid choice");
		}
	}
	return 0;
}



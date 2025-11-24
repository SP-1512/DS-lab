#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node *prev;
	int data;
	struct node *next;
};
void create_list();
struct node *create_node();
void display();
void reverse_order();
void insert_beg();
void insert_last();
void insert_anywhere();
void delete_beg();
void delete_end();
void deieteanywhere();
void search();
struct node *head=NULL,*end=NULL;
int count=0;
//creation of node
struct node * create_node()
{    
    int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{	
	printf("can't allocate memory\n");
		return; 
	}
	printf(" enter data into node:");
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
	}
	count++;
	printf("__node created__\n");	
}
void display()
{
	struct node*temp;
	if(head==NULL)
	{	
		printf("list is empty\n");
		return;	
	}
		temp=head;
		printf("list in forward:\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("End null\n");
}
void reverse_order()
{	struct node*temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;	
	}
	temp=end;
	printf("list in forward:\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
	printf("Head null\n");
}
void insert_beg()
{	struct node*newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode;
	}
	else	
	{	
	    head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
		 count++;
		 printf("___node added at first___\n");
}
void insert_last()
{
	struct node*newnode=create_node();
	if(head==NULL)
	{
		head=end=newnode; 
	}
	else
	{	
	   end->next=newnode;
		newnode->prev=end;
		end=newnode;
	} count++; 
	printf("___node added at last___\n");
}
void insert_anywhere()
{	struct node*newnode,*temp,*curr;
	int pos,i;
	printf("\n enter position");
	scanf("%d",&pos);
	if(pos<1||pos>count+1)
	{
		printf("invalid \n");
		return ;
	}
	if(pos==1)
	{	
	insert_beg(); return;
	}
	else if(pos==count+1)
	{	
	insert_last();
	return;
	} 
	else
	{
	newnode=create_node();
	curr=head;
	for(i=1;i<pos;i++)
	{
		temp=curr;
		curr=curr->next;
	}
	newnode->next=curr;
	newnode->prev=temp;
	temp->next=newnode;
	curr->prev=newnode;
	count++;
	 printf("__node added__");
	}
}
void delete_beg()
{	struct node *temp;
	if(head==NULL)
	{
		printf("\n list is empty");
		return;
	}
	temp=head;
	head=head->next;
	if(head==NULL)
	{
		end=NULL;
	}
	else
	{
		head->prev=NULL;
	}
	free(temp);
	count--;
	printf("\n node deleted");
}
void delete_end()
{	struct node*temp;
	if(head==NULL)
	{
		printf("\n list is empty");
		return;	
	}
	temp=end;
	end=end->prev;
	if(end==NULL)
	{ 
	 head=NULL;	
	}
	else
	{
		end->next=NULL;	
	}
	free(temp);
	count--;
	printf("\n __node deleted__");
}
void deleteanywhere()
{
	int pos,i;
	struct node *curr,*temp;
if(head==NULL)
	{
		printf("\n list is empty");
		return;
	}
	printf("\n enter position:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("\n invalid position");
		return;
	}
	curr=head;
	for(i=1;i<pos;i++)
	{
		temp=curr;
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next->prev=temp;
	free(curr);
	count--;
	printf("\n __node deleted__");
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
int main()
{ 
	int ch;
	while(1)
	{	printf("\n**menu**");
		printf("\n 1.create \n 2.display \n 3.reverse order");
		printf("\n 4.insert beg \n 5. insert last \n 6. insert anywhere");
		printf("\n 7. Delete beg \n 8.Delete end \n 9. Delete any node\n 10.Search a node \n 11.To exit");
		printf("\nenter choice:");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1: create_list(); break;
			case 2: display(); break;
			case 3: reverse_order(); break; 
			case 4: insert_beg(); break;
			case 5: insert_last(); break;  
			case 6: insert_anywhere(); break; 
			case 7: delete_beg(); break;
			case 8: delete_end(); break;
			case 9: deleteanywhere(); break;
			case 10: search();break;
			case 11: exit(0);
			default:printf("\n invalid choice");
		}
	}
	return 0;
}

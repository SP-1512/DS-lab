#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*end=NULL;
void create();
void display();
void insertfirst();
void insertlat();
void insert_any();
void delete_beg();
void delete_end();
void delete_any_pos();
void search();
void replace();
int count=0;
void create()
{
	int info;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory is full...");
		return;
	}
	printf("Enter data:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if (head==NULL)
	{
		head=end=newnode;
		end->next=head;
	}
	else
	{
		end->next=newnode;
		end=newnode;
		end->next=head;
	}
	count++;
	printf("\n Node added");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
	    printf("List is empty");
	    return ;
	}
	temp=head;
    do
	{
    	printf("%d -> ",temp->data);
    	temp=temp->next;
	}
	while(temp!=head);
}
void insertfirst()
{
	int info;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory is full...");
		return;
	}
	printf("Enter data:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=head;
	if(head==NULL)
	{
	    head=end=newnode;
	    end->next=head;
	}
	else
	{
		head=newnode;
	    end->next=head;
	}
	count++;
}
void insertlast()
{
	int info;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory is full...");
		return;
	}
	printf("Enter data:");
	scanf("%d",&info);
	newnode->data=info;
	end->next=newnode;
	end=newnode;
	end->next=head;
	count++;
}
void insert_any()
{
	int info,pos,i;
	struct node *newnode,*temp;
	printf("\nEnter Position:");
	scanf("%d",&pos);
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n*Memory is not created*\n");
		return;
	}
	if(pos==1)
	{
	    insertfirst();
	    return;
	}
	if(pos==count+1)
	{
	    insertlast();
	    return;
	}
	printf("Enter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(pos<1||pos>count)
	{
		printf("\n*Insertion Not Possible*");
		free(newnode);
		return;
	}
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
	printf("---Node is Inserted---\n");
}
void delete_beg()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	if(head==end)
	{
	    head=end=NULL;
	    free(temp);
	}
	else
	{
		head=head->next;
	    free(temp);
	    end->next=head;
	}
	count--;
	printf("\n---Node is Deleted---\n");
}
void delete_end()
{
	struct node *curr,*prev;
	curr=head;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	while(curr->next!=head)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=head;
	end=prev;
	free(curr);
	count--;
	printf("\n---Node is deleted---\n");
}
void delete_any_pos()
{
	int pos,i;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	printf("enter position to delete");
	scanf("%d", &pos);
	if(pos==1)
	{
	    delete_beg();
	    return;
	}
	if(pos==count)
	{
	    delete_end();
	    return;
	}
	struct node *temp,*prev;
	temp=head;
	for(i=1;i<pos;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	count--;
	printf("Node is deleted at any pos");
}
void search()
{
	int key;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	printf("\nEnter element to search:");
	scanf("%d",&key);
	struct node *temp=head;
	do
	{
		if(temp->data==key)
	    {
	    	printf("\nElement Found");
	    	return ;
		}
		temp=temp->next;
	}
	while(temp!=head);
	printf("\nElement not found");
}
void replace()
{
	int key,ele;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	printf("\nEnter element to search:");
	scanf("%d",&key);
	printf("\nEnter element to replace:");
	scanf("%d",&ele);
	struct node *temp=head;
	do
	{
		if(temp->data==key)
	    {
	    	temp->data=ele;
	    	printf("\nElement repaced");
	    	return ;
		}
		temp=temp->next;
	}
	while(temp!=head);
	printf("\nElement not found");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n***INDEX*\n");
		printf("1.Create\n2.Display\n3.Insert node at Beginning\n");
		printf("4.Insert node at any position\n5.Insert node at end\n");
		printf("6.Delete node at Beginning\n7.Delete node at end\n");
		printf("8.Delete any Node\n9.search\n10.replace\n11.Exit\n");
		printf("Enter Your Choice:");
	    scanf("%d",&ch);
    	switch(ch)
    	{
		  case 1:create();break;
		  case 2:display();break;
		  case 3:insertfirst();break;
	      case 4:insert_any();break;
		  case 5:insertlast();break;
		  case 6:delete_beg();break;
		  case 7:delete_end();break;
		  case 8:delete_any_pos();break;
		  case 9:search();break;
		  case 10:replace();break;
	      case 11:exit(0);
		  default:printf("\n--Invalid choice--");
    	}
    }
    return 0;
}

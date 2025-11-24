#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node *f=NULL,*r=NULL;
int size=0;
struct node
{
    int data;
    struct node *next;
};
void enqueue()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node)); 
    temp->next=NULL;
    printf("\nenter data :");
    scanf("%d",&temp->data);
    if(max==size)
    {
        printf("queue is full");
    }
    else if(f==NULL&&r==NULL)
    {
    f=r=temp;
    printf("%d enqueued",temp->data);
    }
    else
    {
        r->next=temp;
        r=temp;
        printf("%d is enqueued",temp->data);
    }
}
void dequeue()
{
    if(f==NULL&&r==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        if(f==NULL)
        {
            f=r=NULL;
            printf("queue is empty");
        }
        else
        {
        printf("%d dequeued",f->data);
        f=f->next;
        free(f);
        }
    }
}
void peek()
{
    if(f==NULL&&r==NULL)
    {
        printf("underflow");
    }
    else
    {
        printf("%d",f->data);
    }
}
void display()
{
    
    if(f==NULL&&r==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        struct node *ptr;
        ptr=f;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\nenter choice:\n1.enqueue,2.dequeue,3.peek,4.display:");
        scanf("%d",&ch);
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
            printf("wrong choice");
        }
    }
}

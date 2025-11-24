#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL, *end = NULL;
int count = 0;
void create_nodes();
void display();
void insert_first();
void create_nodes() 
{
    int info;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) 
	{
        printf("\nMemory full");
        return;
    }
    printf("Enter data into node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = NULL;
    if (head == NULL) {
        head = end = newnode;
    } else {
        end->next = newnode;
        end = newnode;
    }

    count++;
    printf("\nNode created");
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }

    temp = head;
    printf("\nList elements are: ");
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  // Proper termination of output
}

void insert_first() {
    int info;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory full");
        return;
    }

    printf("Enter data into node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = head;
    if (head == NULL) {
        head = end = newnode;
    } else {
        head = newnode;
    }

    count++;
    printf("\nNode added at first");
}

int main() {
    int ch;

    while (1) {
        printf("\n***** MENU *****");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert at First");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create_nodes();
                    break;
            case 2: display();
                    break;
            case 3: insert_first();
                    break;
            case 4: exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    
    return 0;
}


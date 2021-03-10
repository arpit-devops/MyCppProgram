#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node *next;
};

void insert_at_beg (struct node **node, int value){

struct node *ptr = (struct node *) malloc (sizeof(struct node));
//struct node *temp = *node;
ptr -> data = value;

ptr -> next = (*node);
*node = ptr;
}


void display(struct node *node){

struct node *ptr = node;
if (node == NULL){

    printf("\n list is empty\n ");

}

while (ptr != NULL){

    printf("%d -> ", ptr -> data);

    ptr = ptr -> next;
 }

}

void insert_in_bet(struct node **node, struct node *index, int value)
{
    struct node * ptr = (*node)
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if (value == '0')
    {
        temp -> data = '1';
    }
    else{
        temp->data = '0';
    }
    while (ptr != NULL)
    {
        if (ptr ->next == index)
        {
            temp -> next = ptr -> next -> next;
            ptr -> next = temp;

        }
    }


}




void reverse (struct node **node)
{
    struct node *p1, *p2, *p3;
    if(*node == NULL)
    {
        printf("\n list is empty\n ");
        return;
    }

    p1 = (*node);
    p2 = p1->next;
    p3 = p2->next;


    p1 -> next = NULL;
    p2 ->next = p1;


    while(p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3 -> next;
        p2->next = p1;

     }

    (*node) = p2;

    display(*node);

}

int main()
{
    struct node * head = NULL;
    int choice;
    int value;
    while(1)
    {


    printf("enter your choice \n 1-> to add \n 2-> display \n 3-> reverse list \n 4-> insert at between \n5-> exit ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n enter a value to be inserted");
        scanf("%d", &value);
        insert_at_beg(&head, value);
        printf("value = %d is inserted", value);
        break;

    case 2:
        printf("\n list is \n ");
        display(head);
        break;
    case 3:
        reverse(&head);
        break;
    case 4:


    case 5:
        exit(0);
    default:
        printf("\n wrong input  try again \n");

    }

    }

}


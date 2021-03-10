#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node *head = NULL;
struct node *for_nrzi = NULL;

void insert_at_end( struct node **head, int value)
{

    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr-> data = value;
    ptr->next = NULL;
    if (*head == NULL)
    {
     *head = ptr;
     return;
    }
    struct node * temp = *head;
    while( temp -> next != NULL )
    {
        temp=temp->next;
    }

    temp->next=ptr;


}

void to_nrzi(struct node *head)
{
    struct node *ptr = head;
    int first = ptr->data;
    int prev = ptr->data;
    printf("first = %c\n",first);
    int temp = '1';
    while (ptr != NULL)
    {
        if (first == ptr->data)
        {
            insert_at_end(&for_nrzi, temp);
        }
        else{
              if (temp == '1')
              {
                  temp = '0';
                  insert_at_end(&for_nrzi, temp);
              }
              else if (temp == '0')
              {
                  temp = '1';
                  insert_at_end(&for_nrzi, temp);
              }

        }

    ptr = ptr->next;

    }
}


void display(struct node *head)
{
    struct node * ptr = head;
    while(ptr != NULL)
    {
        printf("%c",ptr->data);
        ptr = ptr->next;
    }
    //printf("\n");

}


void print_bin(unsigned char byte)
{

    int i = CHAR_BIT;
    int a;
    while(i--) {
           // printf("%d",i);
        a =('0' +((byte >> i) & 1));
        insert_at_end(&head, a);
    //printf("%c",a);
    }

//    for (int j=0; j<8; j++)
//    {
//       // printf("aa");
//        printf("%c",item[j]);
//    }

//display(head);

//to_nrzi(head);

}


int main()
{

    int c;
    while( (c = getchar()) != 10)
    {
        print_bin((char*)c);
    }
    printf("\n change to bit stream\n");
    display(head);
    printf("\n change to bit nrzi\n");
    to_nrzi(head);
    display(for_nrzi);



    return 0;
}

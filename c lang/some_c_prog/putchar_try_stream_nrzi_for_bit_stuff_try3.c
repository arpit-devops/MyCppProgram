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
struct node *after_bit_stuff = NULL;

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
    //printf("first = %c\n",first);
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
//       // printf("%c",item[j]);
//    }

//display(head);

//to_nrzi(head);

}

void add_stuff(struct node * index, int value)
{
    //printf("void %u ", index);
    //struct node * ptr =;
    after_bit_stuff = for_nrzi;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(value == '1')
        temp->data = '0';
    else
        temp->data = '1';

    while(after_bit_stuff != NULL)
    {

        if (after_bit_stuff == index)
        {
            //printf("index %d",index );
            //printf("after_bit_stuff   %d",after_bit_stuff);
           temp->next = (struct node *)after_bit_stuff;
           after_bit_stuff->next = temp;
           //;
        }
        after_bit_stuff = after_bit_stuff->next;

    }

display(after_bit_stuff);
}






void bit_stuff(struct node * head)
{
    struct node * ptr = head;
    //struct node * temp = (struct node *)malloc(struct node);
    struct node *temp = NULL;
    int count =0;
    int a;
    while(ptr != NULL)
    {
        count=0;
        a = ptr -> data;
        temp = ptr;
        for (int i=0 ; i<5; i++)
        {
            if (a == temp->data )
            {
                count ++;
            }
                temp = temp->next;
        }
        if(count == 5 ){
        //printf("count = %d",count);

        add_stuff(temp, temp->data);
        //printf("temp   %u ",temp);
        }
        ptr = ptr->next;

    }


}


int main()
{
    int c;
    while( (c = getchar()) != 10)
    {
        print_bin((unsigned char*)c);
    }
    printf("\n change to bit stream\n");
    display(head);
    printf("\n change to bit nrzi\n");
    to_nrzi(head);
    display(for_nrzi);
    printf("\n bit stuff \n");
    bit_stuff(for_nrzi);
    display(after_bit_stuff);

    return 0;
}

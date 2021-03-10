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

void insert_in_bet(struct node **node, struct node *index, int value)
{
    printf("value = %c", value);
    struct node * ptr = (*node);
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if (value == '0')
    {
        temp -> data = '1';
    }
    else{
        temp->data = '0';
    }
    printf("\n temp_data %c", temp ->data);
    while (ptr != NULL)
    {
        if (ptr ->next == index)
        {
            temp -> next = ptr;
            ptr -> next = temp;

        }
       ptr = ptr->next;
    }
    printf("\n display ptr \n");
    display(ptr);

}




void bit_stuff(struct node * head)
{
    struct node * ptr_outer = head;
    struct node * ptr_inner = head;
    struct node * ptr_temp = NULL;
    after_bit_stuff = head;

    int temp1;
    int temp2;
    int count=0;

    while (ptr_outer != NULL)
    {
        temp1 = ptr_outer -> data;
        while(ptr_inner -> next != NULL)
        {
            count =0;
            ptr_temp = ptr_inner -> next;
            for (int i=0; i<4; i++)
            {

                temp2 = ptr_temp -> data;
                if (temp1 == temp2)
                {
                    count++;

                }
                ptr_temp = ptr_temp -> next;

            }

            if (count == 4)
            {
                insert_in_bet(after_bit_stuff, ptr_temp, ptr_temp -> data);

            }

            ptr_inner = ptr_inner->next;
        }

        ptr_outer = ptr_outer->next;
    }

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
    printf("\n bit stuff \n");
    bit_stuff(for_nrzi);
    display(after_bit_stuff);

    return 0;
}

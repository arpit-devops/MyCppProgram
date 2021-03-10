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






void bit_stuff(struct node * head)
{
    int var=0;
    int cout_temp;
    int count =0;
    int k,j;
    struct node * ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    int * arr = (int *) malloc(count * sizeof(int));
    int * b = (int *) malloc(2 * count * sizeof(int));
    ptr = head;
    printf("count %d", count);

    for(int i =0 ; i<count; i++)
{

        arr[i] = ptr-> data;
        ptr = ptr->next;
        //printf("arr-%c", arr[i]);

}


    cout_temp=1;
    j=0;
    while(var<count)
    {
        if(arr[var]=='1')
        {
            b[j]=arr[var];
            for(k=var+1; arr[k]=='1' && k<count && cout_temp<5; k++)
            {
                j++;
                b[j]=arr[k];
                cout_temp++;
                if(cout_temp==5)
                {
                    j++;
                    b[j]='0';
                }
                var=k;
            }
        }
        else
        {
            b[j]=arr[var];
        }
        var++;
        j++;
    }
    printf("\nAfter Bit Stuffing :");
    for(var=0; var<j; var++)
        printf("%c",b[var]);



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
    bit_stuff(head);
    //display(after_bit_stuff);

    return 0;
}

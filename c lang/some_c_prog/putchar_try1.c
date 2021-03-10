
#include<stdio.h>


int main()
{
    unsigned char temp =  ((~0)) ;
    temp = temp >>1 ;
    printf("temp = %x\n",temp);
    char c;
    char bin;
    printf("\n enter a character to see its binary \n");
    c = getchar();
    printf("c= %c\n", c);
    char temp_char = c;
    for (int i =0; temp_char !=0; i++)
    {
            bin = temp & (temp_char);
            bin = bin >> ((sizeof(char)*8)-0);
            temp_char = (temp_char<<1);
            printf("%d", bin);
    }




    return 0;
}

#include <stdio.h>
#include <limits.h>

void print_bin(unsigned char byte)
{
    int i = CHAR_BIT;
    while(i--) {
        putchar( '0' +((byte >> i) & 1));
    }

}




int main()
{

    int c;
    while( (c = getchar()) != 10)
    {
        print_bin((char*)c);
    }


    return 0;
}

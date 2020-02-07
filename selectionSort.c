#include<stdio.h>
int *selection(int [],int);

void main()
{
        int arr[6];        // we take array of 6 element

        printf("\n enter array\n");
        for(int i=0;i<6;i++)
                scanf("%d",&arr[i]);

    int *ptr=selection(arr,6);                 // sorted array base address points to ptr
        printf("\n your array is \n");
        for(int i=0;i<6;i++)
        printf("  %d  ",ptr[i] );

}

int *selection(int arr[],int n)
{int min;
        int tempvar;
        //int temp[6];
        for(int i=0;i<n-1;i++)
        {
                min =i;

                for(int j=i+1;j<n;j++)
                {
                                        if(arr[min]>arr[j])
                        {
                                min=j;
                        }
                }

                tempvar=arr[i];             // swapping done here
                arr[i]=arr[min];
                arr[min]=tempvar;

        }

        return arr;
}
                                                           

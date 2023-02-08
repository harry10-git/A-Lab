#include<stdio.h>
#include<stdlib.h>


int main()
{

    printf("Enter a number ");
    int num1;
    scanf("%d",&num1);

    int arr1[10];
    int p1=0;

    while(num1!=1)
    {

        for(int i=2; i<=num1; i++)
        {
            if(num1 % i == 0)
            {
                // printf("%d  ",i);
                num1 = num1/i ;
                arr1[p1]=i;
                p1++;
                break;
            }
        }
    }

    for (int i = 0; i<p1 ; i++)
    {
        printf("%d ",arr1[i]);
    }


    printf("\nEnter a number ");
    int num2;
    scanf("%d",&num2);

    int arr2[10];
    int p2=0;

    while(num2!=1)
    {

        for(int i=2; i<=num2; i++)
        {
            if(num2 % i == 0)
            {
                // printf("%d  ",i);
                num2 = num2/i ;
                arr2[p2]=i;
                p2++;
                break;
            }
        }
    }

    for (int i = 0; i<p2 ; i++)
    {
        printf("%d ",arr2[i]);
    }
    
    int gcd=1;

    for(int i =0, j=0; i<=p1 && j<=p2 ; )
    {
        if(arr1[i]==arr2[j])
        {
            gcd = gcd * arr1[i];
            i++;
            j++;
        }
        else if (arr1[i]<arr2[j])
        {
            i++;
        }
        else 
            j++;
    }

    printf("\nThe gcd is %d",gcd);




     return 0;
}
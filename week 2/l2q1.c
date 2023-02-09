#include<stdio.h>
#include<stdlib.h>


int main()
{
    int num1, num2;

    int opcount=0;

    printf("Enter num1 ");
    scanf("%d",&num1);
    printf("Enter num2 ");
    scanf("%d",&num2);

    int m = (num1>num2)? num1:num2 ;
    int n = (num1<num2)? num1:num2 ;

    int gcd= 0;

    for(int j = num2 ; j>0 ; j--,opcount++)
    {
        if(num1 % j ==0)
        {
            if(num2 % j ==0)
            {
                gcd = j;
                break;
            }
        }
    }

    printf("The gcd is %d",gcd);
    printf("\nThe opcount is %d",opcount);





     return 0;
}

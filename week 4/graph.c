#include<stdio.h>

#include<stdlib.h>


 

int main()

{

    int n;


 

    printf("Enter num of nodes: ");

    scanf("%d",&n);

     int * mat;

    mat = (int *)malloc(n*sizeof(int));


 

    for(int i=0; i<n; i++)

    {

        for(int j=0; j<n; j++)

        {

            mat + i = (int *)malloc(n*sizeof(int));
        }

    }


 

    int x=0;

    for(int i=0; i<n; i++)

    {

         

       while( x != -1 && x<n)

        {

            printf("Enter nodes connected to %d :",i);

            scanf("%d",&x);

              mat[i][x]=1;

        }

        x=0;

        // printf("\n here");        

    }



 

    for(int i=0; i<n; i++)

    {

        for(int j=0; j<n; j++)

        {

            printf("%d  ",mat[i][j]);

        }

        printf("\n");

    }



 

    return 0;

}
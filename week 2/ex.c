#include<stdio.h>

 int EuclidGCD(int m, int n) {
 int r;
int opcount = 0; // variable to count how many times the basic operation executes.
while(n!=0) {
opcount++;
r = m %n;
m = n;
n=r;
}
printf("Operation count= %d\n", opcount);
return m;
}


int main() {
int m,n;
printf("Enter the two numbers whose GCD has to be calculated ");
scanf("%d", &m);
scanf("%d", &n);
printf("The sum is %d\n",m+n);
printf("GCD of two numbers using Euclid’s method is %d",
EuclidGCD(m,n)); return 0;
}
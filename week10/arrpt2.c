#include <stdio.h>
int main(void)
{
int a;
int * aPtr;
int *p1;
int *p2;

int v1 = 0;
printf("Value of v1: %d\n",v1);
printf("Value of p1: %d\n\n",p1);

p1 = &v1;
printf("Address of v1: %p\n\n",p1);

*p1 = 42;
printf("Value after change of v1: %d\n", v1);
printf("Pointer of p1: %d\n\n", *p1);

p2 = p1;
printf("Pointer of p2 from p1: %d\n", *p2);

a = 7;
aPtr = &a;

printf("The address of a is %p\nThe value of aPtr is %p\n",&a,aPtr);
printf("The value of a is %d\nThe value of *aPtr is %d\n",a,*aPtr);
printf("\nThe result of &*aPtr is %p\n and the value of *&aPtr is %p\n", &*aPtr,*&aPtr);
printf("\nThe result of *&a is %d\n",*&a);

//CANT DO THIS because you cannot deference an int: printf("%d",*a);
}

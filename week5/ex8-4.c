#include <stdio.h>

 /* Declare several 100-element arrays */

 int intarray[100];
 float floatarray[100];
 double doublearray[100];

 int main()
 {
 /* Display the sizes of numeric data types */

 printf("\n\nSize of int = %d bytes", sizeof(int));
 printf("\nSize of short = %d bytes", sizeof(short));
 printf("\nSize of long = %d bytes", sizeof(long));
 printf("\nSize of long long = %d bytes", sizeof(long long));
 printf("\nSize of float = %d bytes", sizeof(float));
 printf("\nSize of double = %d bytes", sizeof(double));

 /* Display the sizes of the three arrays */

 printf("\nSize of intarray = %d bytes", sizeof(intarray));
 printf("\nSize of floatarray = %d bytes", sizeof(floatarray));
 printf("\nSize of doublearray = %d bytes\n", sizeof(doublearray));

 return 0;
 }

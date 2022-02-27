#include <stdio.h>

 /* Declare an array to hold expenses, and a counter variable */

 float expenses[13];
 int count;

 int main( void )
 {
 /* Input data from keyboard into array */

 /*for (count = 1; count < 13; count++)
 {
 printf("Enter expenses for month %d: ", count);
 scanf("%f", &expenses[count]);

 }*/
 
 FILE *fd = fopen("expenses.txt", "r");
 int n = 0;
 char ch= ' ';
 
 while(n < 12)
 {
     fscanf(fd,"%f",&expenses[n]);
     ch = fgetc(fd);
     n++;
 }
  
 fclose(fd);

 /* Print array contents */

 for (count = 0; count < 12; count++)
 {
 printf("Month %d = $%.2f\n", count + 1, expenses[count]);
 }
 return 0;
 }

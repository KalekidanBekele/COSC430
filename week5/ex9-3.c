#include <stdio.h>
 #define MAX 10


 int id[MAX] = { 274865,123055,264512,343684,434648,525724,623636,724626,823527,974212 };
 int *id_ptr, count;
 float bal[MAX] = { 46.3, 236, 463.2, 679.3, 976.84, 124.5, 464.6, 346.7, 463.8, 76.9 };
 float *bal_ptr;

 int main( void )
 {
 id_ptr = id;
 bal_ptr = bal;
 
/* FILE *fd = fopen("studentbal.txt", "r");
 int n = 0;
 char ch= ' ';
 
 while(n < 10)
 {  
     fscanf(fd,"%d",*id_ptr);
     fscanf(fd,"%f",*bal_ptr);
     n++;
 }
  
 fclose(fd);*/
 


 printf("Student ID \tBalance\n");
 for (count = 0; count < MAX; count++)
 printf("%d\t\t$%.2f\n", *id_ptr++, *bal_ptr++);

 return 0;
 }

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

typedef struct Employee{
char fName[21];
char lName[21];
char salary[14];
}Employee;

int main()
{
Employee EmpArr[100];

strcpy(EmpArr[0].fName, "John");
strcpy(EmpArr[0].lName, "Smith");
strcpy(EmpArr[0].salary, "50000.00");

strcpy(EmpArr[99].fName, "David");
strcpy(EmpArr[99].lName, "Doe");
strcpy(EmpArr[99].salary, "60000.00");

int fd;
if((fd = open("emp.dat", O_RDWR | O_CREAT| O_TRUNC)) == -1)
return -1;
ssize_t BUFSIZE = 100 * sizeof(Employee);

if(write(fd, EmpArr, BUFSIZE) < 0)
{
close(fd);
return (-2);
}

lseek(fd,(off_t)0, SEEK_SET);
char fTemp[21];
char lTemp[21];
char sTemp[14];

for(int i = 0; i < 1; i++)
{
if(read(fd, fTemp,21) < 0)
{
close(fd);
return (-3);
}
strcpy(EmpArr[i].fName, fTemp);

if(read(fd, lTemp,21) < 0)
{
close(fd);
return (-4);
}
strcpy(EmpArr[i].lName, lTemp);

if(read(fd, sTemp,14) < 0)
{
close(fd);
return (-5);
}
strcpy(EmpArr[i].salary, sTemp);

}


printf("EmpArr[0] First name: %s\n",EmpArr[0].fName);
printf("EmpArr[0] Last name: %s\n",EmpArr[0].lName);
printf("EmpArr[0] Salary: $%s\n",EmpArr[0].salary);

printf("EmpArr[99] First name: %s\n",EmpArr[99].fName);
printf("EmpArr[99] Last name: %s\n",EmpArr[99].lName);
printf("EmpArr[99] Salary: $%s\n",EmpArr[99].salary);

close(fd);
return 0;
}

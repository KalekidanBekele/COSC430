#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define MAX 100

typedef struct Employee{
char fName[21];
char lName[21];
char salary[14];
}Employee;

int main()
{
    int fd;
    Employee EmpArr[MAX];
    
    int j = 0;
    
    fd =  open("emp.dat", O_RDWR | O_CREAT| O_TRUNC);
    
    if(fd == -1)
        return -1;
    
    while (j < 99)
    {
        printf("Input Index: ");
        scanf("%d", &j);
        
        if(j > 99)
        {
            printf("\nIndex too large.\n");
            break;
        }
        printf("Input First Name: ");
        scanf("%s", &EmpArr[j].fName);
        printf("Input Last Name: ");
        scanf("%s", &EmpArr[j].lName);
        printf("Input Salary: ");
        scanf("%s", &EmpArr[j].salary);
    }
    
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
    
    for(int i = 0; i < MAX; i++)
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
    
    if(j == 99)
    {
        printf("\n\nEmpArr[99] First name: %s\n",EmpArr[99].fName);
        printf("EmpArr[99] Last name: %s\n",EmpArr[99].lName);
        printf("EmpArr[99] Salary: $%s\n",EmpArr[99].salary);
    }
    else
        printf("\nNo Info in EmpArr[99].\n");
   
    fclose(fd);
    printf("\nEnd of Program.\n");
    
    return 0;
}

#include <stdio.h>
#include <string.h>

struct user
{
  char str[20];
  int A;
};

int main()
{   
    FILE *fd = NULL;
    struct user clients[16];
    int hindex;
    int sindex;
    int high = -999999;
    int shigh= -999999;
    int n = 0;
    char ch = ' ';
    
    fd = fopen("investments.txt", "r");
   
    while(n < 16)
    {
        fscanf(fd,"%[^ ]",clients[n].str);
        ch = fgetc(fd);
        fscanf(fd,"%d",&clients[n].A);
        ch = fgetc(fd);
        
        n++;
    }
    
    for (int i = 0; i < 16; i++)
    {
        if (clients[i].A > high)
        {
            high = clients[i].A;
            hindex = i;
        }
        if (clients[i].A > shigh && i != hindex)
        {
            shigh = clients[i].A;
            sindex = i;
        }
    }
    
    printf("Highest balance: %dK\n", high);
    printf("Client's Name: %s\n", clients[hindex].str);
    printf("index: %d\n", hindex);

    printf("Second Balance: %dK\n", shigh);
    printf("Client's Name: %s\n", clients[sindex].str);
    printf("index: %d\n", sindex);

    fclose(fd);

    return 0;
}

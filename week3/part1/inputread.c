#include <stdio.h>

int main()
{
    int A[] = { 341,273,278,329,445,402,388,275,243,334,412,393,299,343,317,265 };
    char *str[] = { "Elena", "Thomas", "Hamilton", "Suzie", "Phil", "Matt", "Alex", "Emma", "John", "James", "Jane", "Emily", "Daniel", "Neda", "Aaron", "Kate" };
    int n = 16;
    
    int hindex;
    int sindex;
    int high = -999999;
    int shigh= -999999;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > high)
        {
            high = A[i];
            hindex = i;
        }
        if (A[i] > shigh && i != hindex)
        {
            shigh = A[i];
            sindex = i;
        }
    }

    printf("Highest balance: %dK\n", high);
    printf("Client's Name: %s\n", str[hindex]);
    printf("index: %d\n", hindex);

    printf("Second Balance: %dK\n", shigh);
    printf("Client's Name: %s\n", str[sindex]);
    printf("index: %d\n", sindex);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int i;

int main(int argc, char** argv)
{
	int j;
	j=argc;
	i=j;

	printf("Argc: %d\n",i);

	j=sizeof(long);
	printf("Size of long: %d\n",j);

	j=sizeof(int*);
	printf("Size of int*: %d\n",j);

	return 0;
}

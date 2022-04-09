#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	int *p1, *p2;

	p1 = (int *) malloc(sizeof(int));

	*p1 = 42;
	p2 = p1;
	printf ("*p1 == %d\n *p2 == %d\n", *p1,*p2);

	*p2 = 53;
	puts ("\n\nAfter *p2 = 53:\n");
	printf("*p1 == %d\n *p2 == %d\n", *p1,*p2);
	p1 = (int *) malloc(sizeof(int));

	*p1 = 88;
	*p2 = 33;
	puts ("\n\nAfter *p1 = 88 and *p2 = 33");
	puts("and created new var for p1 to reference:\n");
	printf("*p1 == %d\n *p2 == %d\n", *p1,*p2);

	free(p1);
	// why not free p1 before second malloc???
	free(p2);
	return(0);
}

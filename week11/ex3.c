#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
// runls - use "execl" to run ls
	printf("executing ls\n");

	execl("/bin/ls", "ls", "-l", (char*)0);

	perror("execl failed to run ls");
	exit(1);

//runls2 - uses execv to run ls
//	char* const av[] = {"ls", "-l", (char*)0};

//	execv("/bin/ls", av);

//	perror("execv failed");
//	exit(1);
}

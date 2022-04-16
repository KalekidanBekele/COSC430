#include <stdio.h>

int main(int argc, char** argv)
{
	char* const argin[] = {"commmand", "with", "arguments", (char*)0};

	execvp("prog", argin);
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void my_exit1()
{
	printf("my_exit1\n");
}

void my_exit2()
{
	printf("my_exit2\n");
}

int main()
{	
	atexit(my_exit1);
	atexit(my_exit2);
	// _exit(0);
	exit(0);
}
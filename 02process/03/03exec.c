#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main()
{
	printf("Entering main...\n");
	printf("main pid = %d \n",getpid());
	int ret = execlp("./hello", "hello", NULL);
	if(-1 == ret)
		ERR_EXIT("execlp");
	printf("Exiting  main...\n");
	return 0;
}
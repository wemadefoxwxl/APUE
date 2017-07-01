#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main(int argc, char *argv[])
{
	printf("Entering main ...\n");
	int ret = fcntl(1, F_SETFD, FD_CLOEXEC);
	if (ret == -1)
		perror("fcntl error");

	execlp("./hello", "hello", NULL);
	printf("Exiting main ...\n");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define ERR_EXIT(m)\
		do\
		{\
			perror(m);\
			exit(EXIT_FAILURE);\
		}while(0)


int main()
{
	int fd;
	fd = open("fifo2",O_WRONLY | O_NONBLOCK);
	if(-1 == 0)
		ERR_EXIT("open");

	printf("open successful \n");
	return 0;
}
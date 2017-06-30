#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

int main()
{
	int fd = open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(-1 == fd)
		ERR_EXIT("open error");
	close(1);
	if(fcntl(fd,F_DUPFD,0) < 0)
		ERR_EXIT("fcntl");
	printf("hello\n");

	return 0;
}
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	int fd = open("b.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(-1 == fd)
		ERR_EXIT("open");

	// dup2完成I/O重定向
	dup2(fd,1);
	printf("hello world\n");

	return 0;
}
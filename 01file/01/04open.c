#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

int main()
{
	umask(0);
	int fd = open("text2.txt",O_WRONLY | O_CREAT |O_EXCL,S_IRUSR | S_IWUSR);
	if(-1 == fd)
		ERR_EXIT("open");
	printf("open successful \n");
	close(fd);

	return 0;
}
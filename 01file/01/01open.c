#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define ERR_EXIT(m)\
		do\
		{\
			perror(m);\
			exit(EXIT_FAILURE);\
		}while(0)

int main()
{
	int fd;
	fd = open("test.txt",O_RDONLY);

	if(-1 == fd)
	{
		ERR_EXIT("open");
	}

	printf("open successful \n" );

	return 0;
}
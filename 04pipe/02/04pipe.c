#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main()
{
	int fd[2];
	if(pipe(fd) == -1)
		ERR_EXIT("pipe");

	int flags = fcntl(fd[1],F_GETFL,0);
	fcntl(fd[1],F_SETFL,flags|O_NONBLOCK);
	int ret;
	int count = 0;
	while(1)
	{
		ret = write(fd[1],"A",1);
		if(ret == -1)
		{
			printf("err = %s \n", strerror(errno));
			break;
		}
		++count;
	}
	printf("count = %d\n", count);
	return 0;
}
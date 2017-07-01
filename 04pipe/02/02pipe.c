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

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(0 == pid)
	{
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		char buf[10];
		memset(buf,0,sizeof(buf));
		int ret = read(fd[0],buf,sizeof(buf));
		printf("ret  = %d \n", ret);
	}

	return 0;
}
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

void handler(int sig)
{
	printf("recv sig is %d \n", sig);
}

int main()
{	
	signal(SIGPIPE,handler);
	int fd[2];
	if(pipe(fd) == -1)
		ERR_EXIT("pipe");

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(0 == pid)
	{
		close(fd[0]);
		exit(0);
	}
	else
	{
		close(fd[0]);
		sleep(2);
		int ret  = write(fd[1],"hello",5);
		if(ret == -1)
			printf("write error\n");
	}
	
	return 0;
}
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
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
	int pipefd[2];
	if(pipe(pipefd) == -1)
		ERR_EXIT("pipe");

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");
	if(0 == pid)
	{
		close(pipefd[0]);
		write(pipefd[1],"hello",5);
		close(pipefd[1]);
		exit(0);
	}
	else
	{
		close(pipefd[1]);
		char buf[10];
		memset(buf,0,sizeof(buf));
		read(pipefd[0],buf,sizeof(buf));
		printf("buf = %s \n", buf);
		close(pipefd[0]);
	}

	return 0;
}
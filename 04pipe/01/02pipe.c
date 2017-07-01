#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

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
		dup2(fd[1],STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);
		fprintf(stderr, "error execlp ls \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd[0],STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execlp("/usr/bin/wc","wc","-w",NULL);
		fprintf(stderr, "error execlp wc\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
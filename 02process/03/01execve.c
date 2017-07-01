#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main()
{
	signal(SIGCHLD,SIG_IGN);
	printf("before fork pid = %d\n",getpid());

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(pid > 0)
	{
		printf("this is parent id = %d child id = %d \n", getpid(),pid);
	}
	else
	{
		char *const args[] = {"ps", NULL};
		execve("/bin/ps", args, NULL);
		ERR_EXIT("execve");		
	}

	return 0;
}
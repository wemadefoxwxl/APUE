#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
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
	signal(SIGCHLD,SIG_IGN);
	printf("before fork pid = %d \n", getpid());
	pid_t pid = fork();
	if(pid == -1)
		ERR_EXIT("fork");

	// 父进程
	if(pid > 0)
	{
		printf("this is parent pid = %d  child pid = %d\n",getpid(),pid);
		sleep(10);
	}
	else
	{
		printf("this is child pid  = %d parent pid = %d\n",getpid(),getppid());
	}

	return 0;
}
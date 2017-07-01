#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

#define ERR_EXIT(m)\
		do\
		{\
			perror(m);\
			exit(EXIT_FAILURE);\
		}while(0)

void handler(int sig)
{
	printf("recv signal = %d\n",sig);
}

int main()
{
	if(signal(SIGUSR1,handler) == SIG_ERR)
		ERR_EXIT("signal");

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(0 == pid)
	{
		killpg(getpgrp(),SIGUSR1);
		exit(0);
	}

	int n = 5;
	do
	{
		n = sleep(n);
	}while(n > 0);

	return 0;
}
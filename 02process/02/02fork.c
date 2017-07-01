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

int globale = 100;

int main()
{
	signal(SIGCHLD,SIG_IGN);
	printf("before fokk pid = %d\n",getpid());

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(pid > 0)
	{
		sleep(1);
		globale += 50;
		printf("this is parent ,globale = %d\n",globale);
		sleep(3);
	}
	else
	{
		globale -= 50;
		printf("this is child  ,globale = %d\n",globale);
	}

	return 0;
}
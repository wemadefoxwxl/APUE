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

int gval = 100;

int main()
{	
	signal(SIGCHLD,SIG_IGN);
	printf("before fork pid = %d\n",getpid());

	pid_t pid = vfork();
	if(-1 == pid)
		ERR_EXIT("vfork");

	if(pid > 0)
	{
		sleep(1);
		gval += 50;
		printf("this is parent id = %d child id = %d  gval = %d\n ", getpid(),pid,gval);
		sleep(3);
	}
	else
	{
		gval -= 10;
		printf("this is child id  = %d  parent id = %d gval = %d\n",getpid(),getppid(),gval);
		exit(0);
	}


	return 0;
}
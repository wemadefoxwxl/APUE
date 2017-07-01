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
	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(0 == pid)
	{
		sleep(3);
		printf("this is child process \n");
		exit(100);
	}

	printf("this is parent process\n");
	int status;
	if(wait(&status) < 0)
		ERR_EXIT("wait");
	printf("%d\n",WEXITSTATUS(status));


	return 0;
}
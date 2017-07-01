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
		printf("this is child\n");
		// exit(100);
		abort();
	}

	printf("this is parent \n");
	int status;
	int ret = waitpid(pid,&status,0);
	printf("ret = %d pid = %d\n", ret, pid);
	if(WIFEXITED(status))
		printf("child exit normal exit status = %d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("child exited abnormal signal number=%d\n", WTERMSIG(status));
	else if (WIFSTOPPED(status))
		printf("child stoped signal number=%d\n", WSTOPSIG(status));

	return 0;
}
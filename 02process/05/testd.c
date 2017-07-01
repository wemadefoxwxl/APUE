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

int setup_daemon(int nochdir,int noclode);

int main()
{
	//daemon(0,0);
	setup_daemon(0,0);
	printf("test1 ...\n");
	while(1)
		;
	printf("test2 ...\n");
	return 0;
}

int setup_daemon(int nochdir,int noclode)
{
	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(pid > 0)
		exit(EXIT_SUCCESS);

	setsid();
	if(0 == nochdir)
		chdir("/");
	if(0 == noclode)
	{
		umask(0);
		for(int i = 0; i < 3;++i)
			close(i);
		open("/dev/null",O_RDWR);
		dup(0);;
		dup(0);
	}
	return 0;
}
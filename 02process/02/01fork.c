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
	printf("before fokk pid = %d\n",getpid());
	int fd = open("test.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(-1 == fd)
		ERR_EXIT("open");

	pid_t pid = fork();
	if(-1 == pid)
		ERR_EXIT("fork");

	if(pid == 0)
	{
		printf("this is child id  = %d  parent id = %d \n",getpid(),getppid() );
		char buf[50];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"this is child\n");
		write(fd,buf,strlen(buf));
		close(fd);
	}
	else
	{
		printf("this is parent id = %d child id = %d \n", getpid(),pid);
		char buf[50];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"this is parnet\n");
		write(fd,buf,strlen(buf));
		close(fd);
		sleep(3);
	}

	return 0;
}
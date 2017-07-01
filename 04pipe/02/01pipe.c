#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

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
		sleep(2);
		close(fd[0]);
		char buf[50];
		memset(buf,0,sizeof(buf));
		strcmp(buf,"hello world\n");
		write(fd[1],buf,sizeof(buf));
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		int flags = fcntl(fd[0],F_GETFL,0);
		if(-1 == flags)
			ERR_EXIT("fcntl");
		fcntl(fd[0],F_SETFL,flags|O_NONBLOCK);
		char buf[50];
		memset(buf,0,sizeof(buf));
		int ret = 0;
		while((ret = read(fd[0],buf,sizeof(buf))) == -1)
		{
			if(EAGAIN == errno)
			{
				continue;
			}
			ERR_EXIT("read");
		}
		printf("buf = %s\n", buf);
	}

	return 0;
}

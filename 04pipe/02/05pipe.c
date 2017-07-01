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

#define SIZE 68*1024

int main()
{
	char a[SIZE];
	char b[SIZE];

	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));

	int fd[2];
	if(pipe(fd) == -1)
		ERR_EXIT("pipe");

	pid_t pid = fork();
	int ret = 0;
	if(0 == pid)
	{
		close(fd[0]);
		ret = write(fd[1],a,sizeof(a));
		printf("Apid = %d  write %d bytes to pipe \n", getpid(),ret);
		close(fd[1]);
		exit(0);
	}

	pid = fork();
	if(0 == pid)
	{
		close(fd[0]);
		ret = write(fd[1],b,sizeof(b));
		printf("Bpid = %d  write %d bytes to pipe \n", getpid(),ret);
		close(fd[1]);
		exit(0);
	}

	close(fd[1]);

	sleep(10);
	int wrfd = open("test.txt",O_CREAT | O_WRONLY | O_TRUNC,0644);
	char buf[SIZE*4];
	memset(buf,0,sizeof(buf));
	int n = 1;
	while(1)
	{
		ret = read(fd[0],buf,sizeof(buf));
		if(0 == ret)
			break;
		printf("n = %02d pid = %d read %d bytes from pipe buf[4095] = %c\n", n++,getpid(),ret,buf[4095]);
		write(wrfd,buf,ret);
		memset(buf,0,sizeof(buf));
	}
}
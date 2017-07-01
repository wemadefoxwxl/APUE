#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
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
	mkfifo("tp",0644);
	int infd = open("Makefile",O_RDONLY);
	if(-1 == infd)
		ERR_EXIT("open infd");

	int outfd = open("tp",O_WRONLY);
	if(-1 == outfd)
		ERR_EXIT("open outfd");

	char buf[1024];
	memset(buf,0,sizeof(buf));
	int n = 0;
	if((n = read(infd,buf,1024)) > 0)
		write(outfd,buf,n);
	close(infd);
	close(outfd);

	return 0;
}
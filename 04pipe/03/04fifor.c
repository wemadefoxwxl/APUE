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
	int outfd = open("Makefile2",O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(-1 == outfd)
		ERR_EXIT("open outfd");

	int infd = open("tp",O_RDONLY);
	if(-1 == infd)
		ERR_EXIT("open infd");

	char buf[1024];
	memset(buf,0,sizeof(buf));
	int n;
	if((n = read(infd,buf,1024)) > 0)
		write(outfd,buf,n);
	close(infd);
	close(outfd);
	unlink("tp");

	return 0;
}
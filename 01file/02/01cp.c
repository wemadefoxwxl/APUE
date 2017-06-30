#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)


int main(int argc,char* argv[])
{
	int infd;
	int outfd;
	if(3 != argc)
	{
		fprintf(stderr, "use %s src dest\n", argv[0]);
		exit(EXIT_FAILURE); 
	}

	infd = open(argv[1],O_RDONLY);
	if(-1 == infd)
		ERR_EXIT("open src");
	outfd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(-1 == outfd)
		ERR_EXIT("open dest");

	char buf[1024];
	memset(buf,0,sizeof(buf));
	int nread = 0;
	while((nread = read(infd,buf,sizeof(buf))) >0)
	{
		write(outfd,buf,nread);
	}
	printf("complete \n");
	close(infd);
	close(outfd);

	return 0;
}
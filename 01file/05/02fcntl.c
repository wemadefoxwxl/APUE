#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

void set_flag(int fd,int flags);
void clr_flag(int fd,int flags);

int main()
{
	char buf[1024];
	memset(buf,0,sizeof(buf));

	set_flag(0,O_NONBLOCK);
	int ret = read(0,buf,1024);
	if(ret == -1)
		printf("read : strerror = %s\n",strerror(ret) );
	else
		fputs(buf,stdout);

	clr_flag(0,O_NONBLOCK);
	ret = read(0,buf,1024);
	if(ret == -1)
		// printf("read : strerror = %s\n",strerror(errno) );
		perror("read");
	else
		fputs(buf,stdout);
	printf("Done\n");

	return 0;
}

void set_flag(int fd,int flags)
{
	int val = fcntl(fd,F_GETFL,0);
	if(val == -1)
		ERR_EXIT("fcntl F_GETFL");
	val |= flags;
	if(fcntl(fd,F_SETFL,val) < 0)
		ERR_EXIT("fcntl F_SETFL");
}

void clr_flag(int fd,int flags)
{
	int val = fcntl(fd,F_GETFL,0);
	if(-1 == val)
		ERR_EXIT("fcntl F_GETFL");
	val &=~val;
	if(fcntl(fd,F_SETFL,val) < 0)
		ERR_EXIT("fcntl F_SETFL");
} 











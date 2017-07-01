#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
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

int main()
{
	char buf1[1024];
	char buf2[1024];
	memset(buf1,0,sizeof(buf1));
	memset(buf2,0,sizeof(buf2));

	int fd1 = open("test.txt",O_RDONLY);
	if(-1 == fd1)
		ERR_EXIT("open file1");
	int ret = read(fd1,buf1,5);
	if(-1 == ret)
		ERR_EXIT("read error");
	printf("buf1 is %s \n", buf1);

	int fd2 = open("test.txt",O_RDWR);
	if(-1 == fd2)
		ERR_EXIT("open file2");

	ret = read(fd2,buf2,5);
	if(-1 == ret)
		ERR_EXIT("read error");
	printf("buf2 is %s \n",buf2);
	write(fd2,"AAAAA",5);

	memset(buf1,0,sizeof(buf1));
	read(fd1,buf1,5);
	printf("read again buf1 is %s \n",buf1 );

	close(fd1);
	close(fd2);


	return 0;
}
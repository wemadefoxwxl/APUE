#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
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
	int fd = open("a.txt",O_RDONLY);
	if(-1 == fd)
		ERR_EXIT("open error");

	char buf[1024];
	memset(buf,0,sizeof(buf));

	int ret = read(fd,buf,5);
	if(-1 == ret)
		ERR_EXIT("read error");
	printf("buf = %s \n", buf);

	//  获取文件的偏移
	ret = lseek(fd,0,SEEK_CUR);
	if(-1 == ret)
		ERR_EXIT("lseek");
	close(fd);
	printf("current offset = %d \n", ret);
	return 0;
}
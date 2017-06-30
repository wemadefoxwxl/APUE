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
	int fd = open("hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(-1 == fd)
		ERR_EXIT("open error");
	write(fd,"ABCDE",5);

	//   产生空洞文件
	int ret = lseek(fd,1024*1024,SEEK_END);
	if(-1 == ret)
		ERR_EXIT("lseek");

	write(fd,"hello",5);

	close(fd);
	return 0;
}
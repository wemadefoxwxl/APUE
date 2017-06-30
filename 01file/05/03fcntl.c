#include <unistd.h>
#include <sys/stat.h>
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

int main(int argc, char *argv[])
{
	int fd;
	fd = open("test2.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		ERR_EXIT("open error");

	struct flock lock;
	memset(&lock, 0, sizeof(lock));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	if (fcntl(fd, F_SETLK, &lock) == 0)
	// if (fcntl(fd, F_SETLKW, &lock) == 0)
	{
		printf("lock success\n");
		printf("press any key to unlock\n");
		getchar();
		lock.l_type = F_UNLCK;
		if (fcntl(fd, F_SETLK, &lock) == 0)
			printf("unlock success\n");
		else
			ERR_EXIT("unlock fail");
	}
	else
		ERR_EXIT("lock fail");




	return 0;
}

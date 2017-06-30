#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = close(10);
	if(-1 == fd)
	{
		perror("close error");
	}

	printf("EINTR  is  %s\n",strerror(EINTR) );
	printf("EAGAIN is %s\n",strerror(EAGAIN));
	printf("EMFILE is %s\n",strerror(EMFILE));
	printf("EMFILE is %s\n",strerror(EMFILE));
	


	return 0;
}
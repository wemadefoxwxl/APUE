#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int mysystem(const char* command);

int main()
{
	// system("ls -l |wc -l");
	mysystem("ls -l |wc -w");
	printf("exiting ....\n");
	return 0;
}

int mysystem(const char* command)
{
	if(command == NULL)
		return 1;

	int status = 0;
	pid_t pid = fork();
	if(pid  == -1)
		ERR_EXIT("error");
	if(0 == pid)
	{
		execl("/bin/sh", "sh", "-c", command, NULL);
		exit(127);
	}
	else
	{
		while(waitpid(pid,&status,0) < 0)
		{
			if(EINTR == errno)
				continue;
			status = -1;
			break;
		}
	}
	return status;

}
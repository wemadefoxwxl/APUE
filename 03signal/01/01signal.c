#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define ERR_EXIT(m)\
		do\
		{\
			perror(m);\
			exit(EXIT_FAILURE);\
		}while(0)

void handler(int sig)
{
	printf("recv a signal = %d \n", sig);
}

int main()
{
	if(signal(SIGINT,handler) == SIG_ERR)
		ERR_EXIT("signal");
	while(1)
		;

	return 0;
}
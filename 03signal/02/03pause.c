#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

#define ERR_EXIT(m)\
		do\
		{\
			perror(m);\
			exit(EXIT_FAILURE);\
		}while(0)

void handler(int sig)
{
	printf("recv signal = %d\n",sig);
	sleep(3);
}

int main()
{
	if(signal(SIGINT,handler) == SIG_ERR)
		ERR_EXIT("signal");

	for(;;)
	{
		pause();
		printf("pause return\n");
	}

	return 0;
}

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
	printf("recv a sig = %d\n",sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	if(sigaction(SIGINT,&act,NULL) == -1)
		ERR_EXIT("sigaction");

	for(;;)
		pause();

	return 0;
}
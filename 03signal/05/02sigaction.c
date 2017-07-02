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
	printf("recv a sig = %d\n", sig);
}

#define __sighandler_t sig_t
__sighandler_t my_signal(int sig,__sighandler_t handler)
{
	struct sigaction act;
	struct sigaction oldact;

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	if(sigaction(sig,&act,&oldact) < 0)
		return SIG_ERR;
	return oldact.sa_handler;
}

int main()
{
	my_signal(SIGINT,handler);
	for(;;)
		pause();

	return 0;
}









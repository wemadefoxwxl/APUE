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
	sleep(5);
}

int main()
{
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigset_t s;
	sigemptyset(&s);
	sigaddset(&s,SIGINT);
	sigaddset(&s,SIGINT);
	sigprocmask(SIG_BLOCK,&s,NULL);

	if(sigaction(SIGINT,&act,NULL) < 0)
		ERR_EXIT("sigaction");

	for(;;)
		pause();
	return 0;
}
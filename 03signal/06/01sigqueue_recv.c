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

void handler(int, siginfo_t *, void *);

int main(int argc, char *argv[])
{
	struct sigaction act;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGINT, &act, NULL) < 0)
		ERR_EXIT("sigaction error");

	for (;;)
		pause();
	return 0;
}

void handler(int sig, siginfo_t *info, void *ctx)
{
	printf("recv a sig=%d data=%d data=%d\n", sig, info->si_value.sival_int, info->si_int);
}
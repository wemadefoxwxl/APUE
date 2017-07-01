#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

#define ERR_EXIT(m)\
		do\
		{\
			perror(m);\
			exit(EXIT_FAILURE);\
		}while(0)

void handler(int sig)
{
	printf("recv a sig = %d\n",sig );
}


int main()
{
	if(signal(SIGALRM,handler) == SIG_ERR)
		ERR_EXIT("signal");

	struct timeval tv_interval = {1, 0};
	struct timeval tv_value = {5, 0};
	struct itimerval it;
	it.it_interval = tv_interval;
	it.it_value = tv_value;
	setitimer(ITIMER_REAL, &it, NULL);

	for(;;)
		pause();
	return 0;
}
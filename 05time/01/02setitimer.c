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


int main(int argc, char *argv[])
{
	struct timeval tv_interval = {1, 0};
	struct timeval tv_value = {1, 0};
	struct itimerval it;
	it.it_interval = tv_interval;
	it.it_value = tv_value;
	setitimer(ITIMER_REAL, &it, NULL);

	int i;
	for (i=0; i<10000; i++)
		;

	struct itimerval oit;
	setitimer(ITIMER_REAL, &it, &oit);
	printf("%d %d %d %d\n", (int)oit.it_interval.tv_sec, (int)oit.it_interval.tv_usec, (int)oit.it_value.tv_sec, (int)oit.it_value.tv_usec);

	return 0;
}
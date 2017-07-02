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
	if(sig == SIGINT)
		printf("recv a sig = %d\n",sig);
	else if(sig == SIGQUIT)
	{
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset,SIGINT);
		sigprocmask(SIG_UNBLOCK,&uset,NULL);
	}
}

void printsigset(sigset_t* set)
{
	for(int i = 0;i < NSIG;++i)
	{
		if(sigismember(set,i))
			putchar('1');
		else
			putchar('0');
	}
	printf("\n");
}


int main()
{
	// 未决信号集
	sigset_t pset;
	// 堵塞信号集
	sigset_t bset;

	sigemptyset(&bset);
	sigaddset(&bset,SIGINT);

	if(signal(SIGINT,handler) == SIG_ERR)
		ERR_EXIT("signal");
	if(signal(SIGQUIT,handler) == SIG_ERR)
		ERR_EXIT("signal");

	sigprocmask(SIG_BLOCK,&bset,NULL);
	for(;;)
	{
		sigpending(&pset);
		printsigset(&pset);
		sleep(1);
	}

	return 0;
}
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

int main(int argc,char* argv[])
{
	if(2 != argc)
	{
		fprintf(stderr, "Usage %s pid\n",argv[0] );
		exit(EXIT_FAILURE);
	}

	pid_t pid = atoi(argv[1]);
	union sigval v;
	v.sival_int = 100;
	sigqueue(pid,SIGINT,v);
	
	return 0;
}
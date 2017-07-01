#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main()
{
	// fork();
	// fork();
	// fork();
	// printf("ok\n");

	for(int i = 0; i < 2;++i)
	{
		fork();	
		printf("-");
	}
	sleep(1);
	fflush(stdout);
	return 0;
}
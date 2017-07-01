#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main(void)
{
	printf("hello pid = %d\n", getpid());
	for (int i=0; environ[i]!=NULL; ++i)
	{
		printf("%s\n", environ[i]);
	}
	sleep(3);
	return 0;
}
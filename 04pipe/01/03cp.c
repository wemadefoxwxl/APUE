#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	close(0);
	open("Makefile",O_RDONLY);
	close(1);
	open("Makefile2",O_WRONLY | O_CREAT | O_TRUNC,0644);

	execlp("cat","cat",NULL);

	return 0;
}
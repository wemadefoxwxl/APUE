#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("fileno(stdin)  = %d \n",fileno(stdin));
	printf("fileno(stdout) = %d \n",fileno(stdout));
	printf("fileno(stderr) = %d \n",fileno(stderr));

	return 0;
}
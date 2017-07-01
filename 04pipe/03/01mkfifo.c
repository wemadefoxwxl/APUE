#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	mkfifo("fifo2",0644);
	return 0;
}
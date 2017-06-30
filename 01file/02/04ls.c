#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>


#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

int main()
{
	DIR* dir = opendir("../../..");
	struct dirent* de;
	while((de = readdir(dir)) != NULL)
	{
		// 过滤隐藏文件
		if((strncmp(de->d_name,".",1)) == 0)
			continue;
		printf("%s\n", de->d_name);
	}

	closedir(dir);
	return 0;
}
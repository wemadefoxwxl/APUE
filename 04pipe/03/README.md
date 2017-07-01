01mkfifo.c     mkfifo name  命令创建命名管道				
			   mkfifo系统调用命名管道
02fifor.c      O_RDONLY | O_NONBLOCK的方式打开fifo。				
03fifow.c      O_WRONLY | O_NONBLOCK的方式打开fifo。				
04fifor.c 05fifow.c  fifo实现进程间通信，进行文件复制。

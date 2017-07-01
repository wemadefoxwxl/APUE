01pipe.c    pipe的O_NONBLOCK的使用				
02pipe.c    如果所有管道的写端对应的文件描述符关闭，则返回为0。       
03pipe.c    如果所有管道的写端对用的文件描述关闭，则write操作会返回SIGPIPE。   
04pipe.c    验证管道的容量。						
05pipe.c    管道的写入原子性的测试。如果写入的数据量小于PIPE_BUF时，Linux保证写入的原子性。
			如果写入的数据量大于PIPE_BUF时，linux将不再保证写入的原子性。		
        

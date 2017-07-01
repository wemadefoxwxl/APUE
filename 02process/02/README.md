01fork.c   fork之后，子进程继承了父进程打开的文件描述符，故每个文件的引用计数为2；父子进程共享文件表，则文件偏移也共享。 		       
02fork.c   全区变量在父子进程中是怎么样的。         
03vfork.c  vfork创建进程。fork与vfork的主要区别在于，fork子进程拷贝父进程的数据，vfork子进程与父进程共享数据，所以vfork有个限制，子进程必须立刻执行_exit()或者exec函数。			
04exit.c   exit(3)与_exit(2)与区别，exit是c库函数，_exit是系统调用，exit会调用_exit,exit会调用fflush进行清空缓冲区。		
05atexit.c   atexit注册终止处理程序。				
06fork.c     fork创建的进程个数。	

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>

#define __NR_print_self 336
int main(int argc, char *argv[])
{  
    long int x;
    int errsv;
     x = syscall(__NR_print_self);
    printf("System call %ld\n",x); 
	if(x==-1)
	  {
	    errsv = errno;
	    printf("errno: %d\n",errsv);
	}
     return 0;
}

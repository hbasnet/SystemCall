#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>

#define __NR_print_self 337
int main(int argc, char *argv[])
{  
    
    int pid;
    long int x;
    int errsv;
    printf("Please enter a pid: ");
    scanf("%d",&pid);
     x = syscall(__NR_print_self,pid);
    printf("System call %ld\n",x); 
	if(x==-1)
	  {
	    errsv = errno;
	    printf("errno: %d\n",errsv);
	}
     return 0;
}

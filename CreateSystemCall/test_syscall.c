#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#define __NR_helloworld 335

int main(int argc, char *argv[])
{
	long int x;
	x = syscall(__NR_helloworld);
	printf("System call %ld",x);
	return 0;
}


#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<linux/linkage.h>
SYSCALL_DEFINE0(print_self)
{
    struct task_struct *proces;
    printk("Process: %s\n PID_Number: %d\n", current->comm, current->pid);
    printk("Start time: %llu\n Virtual runtime: %llu\n",(unsigned long long)current->se.exec_start, (unsigned long long)current->se.vruntime);
    printk("State: ");
    switch(current->state)
    {
	case -1:
		printk("unrunnable\n");
		break;
	case 0:
		printk("runnable\n");
		break;
	default:
		printk("stopped\n");
		break;
    }

    printk("Parent process until init\n");
    for(proces=current;proces!=&init_task;proces=proces->parent)
    {
	 printk("%s %d\n",proces->comm, proces->pid);
    
    }

    return 0;
}

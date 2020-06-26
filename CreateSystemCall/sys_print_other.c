#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<linux/linkage.h>
#include<linux/module.h>
SYSCALL_DEFINE1(print_other,int,pid)
{
	struct pid *target_pid;
	struct task_struct *task;
	target_pid = find_get_pid(pid);
	task = pid_task(target_pid, PIDTYPE_PID);
	printk("Procecss ID: %d\n",task->pid);
	printk("Process Name: %s\n",task->comm);
	printk("Start time: %llu",(unsigned long long)task->se.exec_start);
	printk("Virtual Runtime: %llu",(unsigned long long)task->se.vruntime);
	printk("Status: ");
	switch(task->state)
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
    	for(task=task;task!=&init_task;task=task->parent)
    	{
	    printk("%s %d\n",task->comm, task->pid);
    
    	}
	
  return 0;
}


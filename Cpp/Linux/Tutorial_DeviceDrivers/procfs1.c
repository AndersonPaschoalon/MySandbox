//BUG: it compiles, but insmod do not load it
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/fs.h> 

#define procfs_name "helloworld"

//information about the /proc file
struct proc_dir_entry *procFile;
//static ssize_t procfile_read(struct file*, char*, size_t, loff_t*);

static struct file_operations fileOpts = {  
    .owner = THIS_MODULE,
//    .read = procfile_read,
};

/*

 30 static inline struct proc_dir_entry *proc_create(                               
 31         const char *name, umode_t mode, struct proc_dir_entry *parent,          
 32         const struct file_operations *proc_fops) 
*/


int procfile_read(	char* buffer, //buffer whre the data is to be inserted
			char** buffer_location, //buffer, if we dont to use a buffer allocated by the kernel
			off_t offset, //current position in the file
			int buffer_lenght, //the size of the buffer in the first argument
			int *eof, //1 indicates EOF
			void* data //a pointer to data
)
{
    static int finished = 0;
    int ret = 0;

    printk(KERN_INFO "procfile_read (/proc/%s) called\n", procfs_name);

    if (finished) {
        printk(KERN_INFO "procfs_read: END\n");
        finished = 0;
        return 0;
    }   

    finished = 1;
    ret = sprintf(buffer, "Hello,world!\n");
    return ret;
}

int init_module()
{

	printk(KERN_DEBUG "init_module:\tok");
	// older kernel function, not supported anymore. use proc_create
	// @ proc_fs.h
	//procFile = create_proc_entry(procfs_name, 0644, NULL);
 	//30 static inline struct proc_dir_entry *proc_create(                               
	// 31         const char *name, umode_t mode, struct proc_dir_entry *parent,          
	// 32         const struct file_operations *proc_fops) 
	procFile = proc_create(procfs_name, 0644, NULL, &fileOpts);
	printk(KERN_DEBUG "proc_create:\tok");

	if( procFile == NULL)
	{
		remove_proc_entry(procfs_name, procFile);
		printk(KERN_ALERT "Error: Could not initialize /proc/%s\n", procfs_name);
		return -ENOMEM;
	}




// older kernel operations
//	procFile->read_proc 	= procfile_read;
//	procFile->owner		= THIS_MODULE;
//	procFile->mode		= S_IFREG | S_IRUGO;
//	procFile->		= 0;
//	procFile->		= 0;
//	procFile->		= 37;
	
	
	
	printk(KERN_INFO "/proc/%s created\n", procfs_name);
	return(0);
}

void cleanup_module()
{
	//proc_root not supported anymore
	//prototype: extern void proc_remove(struct proc_dir_entry *);
	//remove_proc_entry(procfs_name, &proc_root);
	remove_proc_entry(procfs_name, procFile);
	printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}



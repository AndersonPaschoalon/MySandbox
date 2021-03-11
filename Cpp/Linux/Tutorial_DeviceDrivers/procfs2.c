//source:
//https://blog.nyanpasu.me/a-proc-file-example/
//BUG: procfile_write() doesnt work propperly
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define PROCFS_MAX_SIZE	1024
#define PROCFS_NAME	"buffer1k"

//this structure hold information about the /proc file
struct proc_dir_entry *Our_Proc_File;

//the buffer used to store characters for this module
static char procfs_buffer[PROCFS_MAX_SIZE];

//size of the buffer
static unsigned long procfs_buffer_size = 0;

//this function is called with the /proc file is written
static ssize_t procfile_read(struct file*, char*, size_t, loff_t*);

//this function is called with the /procfile is written
static ssize_t procfile_write(struct file* file, const char* buffer, unsigned long count, void* data);

//file options
static struct file_operations cmd_file_ops = {  
    .owner = THIS_MODULE,
    .read = procfile_read,
};

//module init
int init_module()  
{
    //Our_Proc_File = proc_create(PROCFS_NAME, S_IFREG | S_IRUGO, NULL, &cmd_file_ops);
    Our_Proc_File = proc_create(PROCFS_NAME, 0666, NULL, &cmd_file_ops);

    if (Our_Proc_File == NULL) {
        remove_proc_entry(PROCFS_NAME, NULL);

        printk(KERN_ALERT "Error: Could not initialize /proc/%s\n", PROCFS_NAME);
        return -ENOMEM;
    }

    /*
     * KUIDT_INIT is a macro defined in the file 'linux/uidgid.h'. KGIDT_INIT also appears here.
     */
    proc_set_user(Our_Proc_File, KUIDT_INIT(0), KGIDT_INIT(0));
    proc_set_size(Our_Proc_File, 37);

    printk(KERN_INFO "/proc/%s created\n", PROCFS_NAME);
    return 0;
}

//module exit
void cleanup_module()  
{
    //remove_proc_entry(procfs_name, &proc_root);
    remove_proc_entry(PROCFS_NAME, NULL);
    printk(KERN_INFO "/proc/%s removed\n", PROCFS_NAME);
}

//this function is called, then the /proc file is read
static ssize_t procfile_read(struct file *file, char *buffer, size_t length, loff_t *offset)  
{
    static int finished = 0;
    int ret = 0;

    printk(KERN_INFO "procfile_read (/proc/%s) called\n", PROCFS_NAME);

    if (finished) {
        printk(KERN_INFO "procfs_read: END\n");
        finished = 0;
        return 0;
    }   

    finished = 1;
    ret = sprintf(buffer, "Hello,world!\n");
    return ret;
}

//this function is called with the /procfile is written
static ssize_t procfile_write(struct file* file, const char* buffer, 
				unsigned long count, void* data)
{

	printk(KERN_INFO "procfile_write (/proc/%s) called\n", PROCFS_NAME);
	procfs_buffer_size = count;
	
	//get buffer size
	if(procfs_buffer_size > PROCFS_MAX_SIZE)
	{
		procfs_buffer_size = PROCFS_MAX_SIZE;
	}

	//write data to the buffer
	//255 static inline long copy_from_user(void *to,                                     
	//256                 const void __user * from, unsigned long n)
	if( copy_from_user(procfs_buffer, buffer, procfs_buffer_size))
	{
		return(-EFAULT);
	}

	return(procfs_buffer_size);

}




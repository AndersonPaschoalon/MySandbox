#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h> // put_user()

/******************************************************************************
 * Prototypes 
 *****************************************************************************/ 

// called when the module is loaded 
int init_module(void);

// called when the module is unloaded
void cleanup_module(void);

// called when a process tries to open the device file, like
// cat /dev/mycharfile
static int device_open(struct inode * , struct file* );

// called when a process closes the device file
static int device_release(struct inode*, struct file*);

// called when a process, which already opened the dev file, attempts to 
// read from it
static ssize_t device_read(struct file*, char*, size_t, loff_t*);

// 
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);

#define SUCCESS 0
#define DEVICE_NAME "chardev"
#define BUF_LEN 80

/*
 * Global variables
 */
static int Major;
static int Device_Open = 0;
static char msg[BUF_LEN];
static char* msg_ptr;

static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

int init_module(void)
{
	Major = register_chrdev(0, DEVICE_NAME, &fops);
	
	if(Major < 0)
	{
		printk(KERN_ALERT "Registerion char device failed with %d\n", Major);
		return(Major);
	}

	printk(KERN_INFO "I was assigned major number %d. To talk to\n", Major);
	printk(KERN_INFO "the driver, create a dev file with\n");
	printk(KERN_INFO "'mknod /dev/%s c %d 0'.", DEVICE_NAME, Major);
	printk(KERN_INFO "Try various minor numbers. Try to cat and echo to\n");
	printk(KERN_INFO "the device gile.\n");
	printk(KERN_INFO "Remove the device file and module when done.\n");
	
	return(SUCCESS);
}

void cleanup_module(void)
{
	int ret = 0;
	unregister_chrdev(Major, DEVICE_NAME);

	if(ret < 0)
	{
		printk(KERN_ALERT "Error in unregister_chardev: %d\n", ret);
	}
}

static int device_open(struct inode* inode, struct file* file)
{
	static int counter = 0;
	
	if(Device_Open)
		return -EBUSY;

	Device_Open++;
	sprintf(msg, "I already told you %d times Hello!\n", counter++);
	msg_ptr = msg;
	try_module_get(THIS_MODULE);

	return(SUCCESS);
}

static int device_release(struct inode* inode, struct file* file)
{
	Device_Open--;
	module_put(THIS_MODULE);

	return(0);
}

static ssize_t device_read( struct file* filep,
				char* buffer,
				size_t length,
				loff_t* offset)
{
	int bytes_read = 0;

	if(*msg_ptr == 0) return 0;

	while(length && *msg_ptr)
	{
		put_user(*(msg_ptr++), buffer++);

		length--;
		bytes_read++;
	}

	return(bytes_read);
}

static ssize_t device_write(struct file* filp, const char *buff, size_t len, loff_t* off)
{
	printk(KERN_ALERT "Sorry, this operation isn't supported.\n");
	return(-EINVAL);
}


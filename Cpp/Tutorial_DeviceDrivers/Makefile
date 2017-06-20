obj-m += hello-1.o
obj-m += hello-2.o
obj-m += hello-5.o
obj-m += cdev.o
obj-m += procfs1.o
obj-m += procfs1.1.o
obj-m += procfs2.o
obj-m += chardev.o
obj-m += kbleds.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc -Wall -o hello hello_std.c
	gcc ioctl.c -o ioctl -I ./
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f hello
	rm -f ioctl



/*  
 *  Hello.c - Sample Hello World Device Driver
 *  Tested  on Ubuntu 10.10 Lucid Lynx (Kernel Ver 2.6.38)
 */

#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello, world 2\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Santhosh Pai");
MODULE_DESCRIPTION("Simple Device Driver");
MODULE_LICENSE("GPL");

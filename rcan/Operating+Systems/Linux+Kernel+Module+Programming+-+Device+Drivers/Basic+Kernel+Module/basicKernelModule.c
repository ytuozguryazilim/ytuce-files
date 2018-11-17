/*  
 *  basicKernelModule.c - Demonstrating the module_init() and module_exit() macros.
 *  This is preferred over using init_module() and cleanup_module().
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

static int __init basicKernelModule_init(void)
{
	printk(KERN_INFO "Hello, world \n");
	return 0;
}

static void __exit basicKernelModule_exit(void)
{
	printk(KERN_INFO "Goodbye world \n");
}

module_init(basicKernelModule_init);
module_exit(basicKernelModule_exit);

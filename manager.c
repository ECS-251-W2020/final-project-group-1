
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */


/*TODO: access data structre that contains required information
store inode in struct inode type and create struct address_space obj for inode
use find_get_page to find inode entry in cache
*/
int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Li");
MODULE_DESCRIPTION("A Simple Hello World module");

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello World!103213025\n");
    return 0;
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Bye World!Liiii\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

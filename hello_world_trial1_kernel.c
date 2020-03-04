/* AFTER 6 hours of HARD and not smart work.*/
/* Why can we just use printk and kmalloc? Why is there no other help in the universe?*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
/* Jayneel persisted! */
#define DEVICE_NAME “ecs251”
#define EXAMPLE_MSG “Hello!\n”
#define MSG_BUFFER_LEN 15 /* no idea why the tutorial kept the buffere length as 15!*/
/* just write the function definitions  */
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
/*read write functions*/
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);
static int major_num;
static int device_open_count = 0; /* what is open?*/
static char msg_buffer[MSG_BUFFER_LEN]; /* THE BUFFER!*/
static char *msg_ptr;
/* This structure points to all of the device functions */
static struct file_operations file_ops = {
 .read = device_read,
 .write = device_write,
 .open = device_open,
 .release = device_release
};
/* When a process reads from our device, this gets called. */
static ssize_t device_read(struct file *flip, char *buffer, size_t len, loff_t *offset) {
 int bytes_read = 0;
 /* If we’re at the end, loop back to the beginning */
 if (*msg_ptr == 0) {
 msg_ptr = msg_buffer;
 }
 /* Put data in the buffer */
 while (len && *msg_ptr) {
/* handle user data out of buffer*/
 put_user(*(msg_ptr++), buffer++);
 len--;
 bytes_read++;
 }
 return bytes_read;
}
/* write! */
static ssize_t device_write(struct file *flip, const char *buffer, size_t len, loff_t *offset) {
 /* error message- smthn goes wrong!*/
 printk(KERN_ALERT “Error! \n”);
 return -EINVAL;
}
/* handle a device open request*/
static int device_open(struct inode *inode, struct file *file) {
 /* If device is open, return busy */
 if (device_open_count) {
 return -EBUSY;
 }
 device_open_count++;
 try_module_get(THIS_MODULE);
 return 0;
}
/* device closed- handle*/
static int device_release(struct inode *inode, struct file *file) {
 /* Decrement the open counter and usage count. Without this, the module would not unload. */
 device_open_count--;
 module_put(THIS_MODULE);
 return 0;
}
static int __init ecs251_init(void) {
 /* enter message to buffer*/
 strncpy(msg_buffer, EXAMPLE_MSG, MSG_BUFFER_LEN);
 /* Set the msg_ptr to the buffer */
 msg_ptr = msg_buffer;
 /* character device registry */
 major_num = register_chrdev(0, “ecs251”, &file_ops);
 if (major_num < 0) {
 printk(KERN_ALERT “Could not register device: %d\n”, major_num);
 return major_num;
 } else {
     /*Succeesssssss*/
 printk(KERN_INFO “ecs251 module loaded with device major number %d\n”, major_num);
 return 0;
 }
}
static void __exit ecs251_exit(void) {
 /* MOST IMP! Cleanup! */
 unregister_chrdev(major_num, DEVICE_NAME);
 printk(KERN_INFO “Goodbye, World!\n”);
}
/* which functions to look at to start and exit */
module_init(ecs251_init);
module_exit(ecs251_exit);

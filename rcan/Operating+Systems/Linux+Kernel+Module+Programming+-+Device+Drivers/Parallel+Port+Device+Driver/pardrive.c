/*Required libraries for parallel port device driver */
#include <linux/init.h> /*init/exit functions*/
#include <linux/configfs.h>/*device driver file system*/
#include <linux/module.h>/*required for to compile as kernel module*/
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* kmalloc() */
#include <linux/fs.h> /*file operations*/
#include <linux/errno.h> 
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>/*proc file system constants*/
#include <linux/fcntl.h> /* O_ACCMODE */
#include <linux/ioport.h>
#include <asm/uaccess.h> /* copy_from/to_user */
#include <asm/io.h> /* inb, outb */
MODULE_LICENSE("Dual BSD/GPL");

/* pardrive.c  --> function defs*/
int parlelport_open(struct inode *inode, struct file *filp);
int parlelport_release(struct inode *inode, struct file *filp);
ssize_t parlelport_read(struct file *filp, char *buf,size_t count, loff_t *f_pos);
ssize_t parlelport_write(struct file *filp, char *buf,size_t count, loff_t *f_pos);
void parlelport_exit(void);
int parlelport_init(void);

/* device driver struct defs*/
/* file access functions*/

struct file_operations parlelport_fops = {
  read: parlelport_read,
  write: parlelport_write,
  open: parlelport_open,
  release: parlelport_release
};

/* Driver global variables */
/* Major number */
int parlelport_major = 61;
/* parallel port reservation*/
int port;

module_init(parlelport_init);
module_exit(parlelport_exit);

int parlelport_init(void) {
  int result;
  /* device registering */
  result = register_chrdev(parlelport_major, "parlelport",&parlelport_fops);
  if (result < 0) {
    printk("<1>parlelport: cannot obtain major number %d\n",parlelport_major);
    return result;
  }

request_region(0x378, 1, "parlelport");

  printk("<1>Inserting parlelport module\n");
  return 0;
  fail:
    parlelport_exit();
    return result;
}


void parlelport_exit(void) {
  /*major number release */
  unregister_chrdev(parlelport_major, "parlelport");
  /* port release! */
  if (!port) {

  release_region(0x378,1);
}

  printk("<1>Removing parlelport module\n");
}

int parlelport_open(struct inode *inode, struct file *filp) {
  return 0;

}

int parlelport_release(struct inode *inode, struct file *filp) {
  return 0;
}

ssize_t parlelport_read(struct file *filp, char *buf,size_t count, loff_t *f_pos) {
  /* buffer to read from device */
  char parlelport_buffer;
  /* port read */
  parlelport_buffer = inb(0x378);
  /*data transfered to user */
  copy_to_user(buf,&parlelport_buffer,2);
  /*change read position */
  if (*f_pos == 0) {
    	*f_pos+=1;
    	return 1;
    } else {
    	return 0;
    }
}
ssize_t parlelport_write( struct file *filp, char *buf,size_t count, loff_t *f_pos) {
  char *tmp;
  /* write to the device*/
  char parlelport_buffer;
  tmp=buf+count-2;
  copy_from_user(&parlelport_buffer,tmp,1);
  printk("Can parlelport buff Adress : %p\n",buf);
  printk("Can parlelport count : %d\n",count);
  printk("Can parlelport input : %d\n",parlelport_buffer);
 /* port data writing */
  outb(parlelport_buffer,0x378);

  return 1;
}


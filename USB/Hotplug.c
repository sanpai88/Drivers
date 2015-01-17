#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

/* Call back functions pen_probe and pen _disconnect for detecting the Hotplugging of the device 

*/
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "Pen drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}
 
static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Pen drive removed\n");
}


/* Structure for holding the vendor and product ID of the device 
   Tested for SEAGATE FREEAGENT 1TB Harddrive 
*/
static struct usb_device_id pen_table[] =
{
    { USB_DEVICE(0x0bc2,0x5021) },
    {} /* Terminating entry */
};

MODULE_DEVICE_TABLE (usb, pen_table);


/* USB structure specifying the nameof the driver and asking what all functions to call when the USB is inserted or removed 
 from the system */

static struct usb_driver pen_driver =
{
    .name = "pen_driver",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};

static int  pen_init(void)
{
     /* the device mustbe reggistered with the USB subsystem and this is done in the INIT module */

     return usb_register(&pen_driver);  

}

/* Deregistering of USB happens in the exit module 
*
*/
static void pen_exit(void)
{
    usb_deregister(&pen_driver);
}


module_init(pen_init);
module_exit(pen_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Santhosh Pai");
MODULE_DESCRIPTION("Sample USB hot plug driver ");

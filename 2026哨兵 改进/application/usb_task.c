/**
  * @file       usb_task.c
  * @brief      USB CDC binary protocol task for the sentry lower controller.
  */

#include "usb_task.h"

#include "cmsis_os.h"
#include "robot_comm.h"
#include "usb_device.h"

void usb_task(void const *argument)
{
    (void)argument;

    robot_comm_init();
    MX_USB_DEVICE_Init();

    while (1)
    {
        robot_comm_update();
        osDelay(1);
    }
}

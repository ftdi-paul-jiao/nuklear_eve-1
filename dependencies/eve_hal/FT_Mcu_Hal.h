#ifndef FT_MCU_HAL_H
#define FT_MCU_HAL_H
#include "FT_Platform.h"

extern const ft_uint8_t FT_DLCODE_BOOTUP[12];

#define Eve_BootupConfig EVE_Util_bootupConfig

ft_void_t Ft_Mcu_Init();

#if (defined(EVE_MODULE_PANL)) && !defined(ESD_SIMULATION)
uint8_t ucHeap[PANL_HEAP_SIZE];

void tfp_putc(void *p, char c)
{
	/*Placeholder for user code*/
	//uart_write((ft900_uart_regs_t*) p, (uint8_t) c);
}
void bacnet_notification_acked(uint8_t id)
{
	//Placeholder for user code
}
ft_bool_t bacnet_msg_received(uint8_t src, const uint8_t *indata, const size_t inlen, uint8_t *outdata, size_t *outlen)
{
	//Placeholder for user code
}
void bacnet_unconf_msg_received(uint8_t src, const uint8_t *indata, const size_t inlen)
{
	//Placeholder for user code
}
#endif /*(defined(EVE_MODULE_PANL)) && !defined(ESD_SIMULATION)*/

#endif

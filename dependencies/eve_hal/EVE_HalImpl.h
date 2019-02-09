/**
* This source code ("the Software") is provided by Bridgetek Pte Ltd
* ("Bridgetek") subject to the licence terms set out
*   http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
* You must read the Licence Terms before downloading or using the Software.
* By installing or using the Software you agree to the Licence Terms. If you
* do not agree to the Licence Terms then do not download or use the Software.
*
* Without prejudice to the Licence Terms, here is a summary of some of the key
* terms of the Licence Terms (and in the event of any conflict between this
* summary and the Licence Terms then the text of the Licence Terms will
* prevail).
*
* The Software is provided "as is".
* There are no warranties (or similar) in relation to the quality of the
* Software. You use it at your own risk.
* The Software should not be used in, or for, any medical device, system or
* appliance. There are exclusions of Bridgetek liability for certain types of loss
* such as: special loss or damage; incidental loss or damage; indirect or
* consequential loss or damage; loss of income; loss of business; loss of
* profits; loss of revenue; loss of contracts; business interruption; loss of
* the use of money or anticipated savings; loss of information; loss of
* opportunity; loss of goodwill or reputation; and/or loss of, damage to or
* corruption of data.
* There is a monetary cap on Bridgetek's liability.
* The Software may have subsequently been amended by another user and then
* distributed by that other user ("Adapted Software").  If so that user may
* have additional licence terms that apply to those amendments. However, Bridgetek
* has no liability in relation to those amendments.
*
* File Description:
*    This file defines the generic APIs of phost access layer for the FT800 or EVE compatible silicon.
*    Application shall access FT800 or EVE resources over these APIs,regardless of I2C or SPI protocol.
*    I2C and SPI is selected by compiler switch "FT_I2C_MODE"  and "FT_SPI_MODE". In addition, there are
*    some helper functions defined for FT800 coprocessor engine as well as phost commands.
*
*/

#ifndef EVE_HAL_IMPL__H
#define EVE_HAL_IMPL__H
#include "EVE_Hal.h"

extern EVE_HalPlatform g_HalPlatform;

/*********
** INIT **
*********/

/* Initialize HAL platform */
void EVE_HalImpl_initialize();

/* Release HAL platform */
void EVE_HalImpl_release();

/* Get the default configuration parameters */
void EVE_HalImpl_defaults(EVE_HalParameters *parameters);

/* Opens a new HAL context using the specified parameters */
bool EVE_HalImpl_open(EVE_HalContext *phost, EVE_HalParameters *parameters);

/* Close a HAL context */
void EVE_HalImpl_close(EVE_HalContext *phost);

/* Idle. Call regularly to update frequently changing internal state */
void EVE_HalImpl_idle(EVE_HalContext *phost);

/*************
** TRANSFER **
*************/

void EVE_Hal_startTransfer(EVE_HalContext *phost, EVE_TRANSFER_T rw, uint32_t addr);
void EVE_Hal_endTransfer(EVE_HalContext *phost);

uint8_t EVE_Hal_transfer8(EVE_HalContext *phost, uint8_t value);
uint16_t EVE_Hal_transfer16(EVE_HalContext *phost, uint16_t value);
uint32_t EVE_Hal_transfer32(EVE_HalContext *phost, uint32_t value);

/*********
** MISC **
*********/

void EVE_Millis_initialize();
void EVE_Millis_release();
uint32_t EVE_millis();

bool EVE_UtilImpl_prepareSpiMaster(EVE_HalContext *phost);
bool EVE_UtilImpl_postBootupConfig(EVE_HalContext *phost);

#endif /* #ifndef EVE_HAL_IMPL__H */

/* end of file */
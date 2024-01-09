////////////////////////////////////////////////////////////////////////////////
/// @file     hal_crc.c
/// @author   AE TEAM
/// @brief    THIS FILE PROVIDES ALL THE CRC FIRMWARE FUNCTIONS.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion
#define _HAL_CRC_C_

// Files includes
#include "hal_crc.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup CRC_HAL
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup CRC_Exported_Functions
/// @{


////////////////////////////////////////////////////////////////////////////////
/// @brief  Resets the CRC Data register (DR).
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void CRC_ResetDR()
{
    CRC->CR = CRC_CR_RESET;
}
//#pragma optimize(0)
////////////////////////////////////////////////////////////////////////////////
/// @brief  Computes the 32-bit CRC of a given data word(32-bit).
/// @param  Data: data word(32-bit) to compute its CRC
/// @retval 32-bit CRC
////////////////////////////////////////////////////////////////////////////////
u32 CRC_CalcCRC(u32 data)
{
    CRC->DR = data;
    __NOP();
    __NOP();
    return (CRC->DR);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Computes the 32-bit CRC of a given buffer of data word(32-bit).
/// @param  buffer: pointer to the buffer containing the data to be computed
/// @param  length: length of the buffer to be computed
/// @retval 32-bit CRC
////////////////////////////////////////////////////////////////////////////////
u32 CRC_CalcBlockCRC(u32* buffer, u32 length)
{
    u32 i;
    for (i = 0; i < length; i++) {
        CRC->DR = buffer[i];
    }
    return (CRC->DR);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Returns the current CRC value.
/// @param  None.
/// @retval 32-bit CRC
////////////////////////////////////////////////////////////////////////////////
u32 CRC_GetCRC(void)
{
    return (CRC->DR);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Stores a 8-bit data in the Independent Data(ID) register.
/// @param  id_value: 8-bit value to be stored in the ID register
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void CRC_SetIDRegister(u8 id_value)
{
    CRC->IDR = id_value;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Returns the 8-bit data stored in the Independent Data(ID) register
/// @param  None.
/// @retval 8-bit value of the ID register
////////////////////////////////////////////////////////////////////////////////
u8 CRC_GetIDRegister()
{
    return (CRC->IDR);
}

/// @}

/// @}

/// @}



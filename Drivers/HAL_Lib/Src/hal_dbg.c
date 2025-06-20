/***********************************************************************************************************************
    @file     hal_dbg.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE DBG FIRMWARE FUNCTIONS.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_dbg.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup DBG
  * @{
  */

/** @defgroup DBG_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup DBG_Private_Functions
  * @{
  */

/**
  * @brief  Enables or disables the specified DBG peripheral.
  * @param  periph: DBG peripheral.
  *     @arg DBG_SLEEP
  *     @arg DBG_STOP
  *     @arg DBG_STOP_FOR_LDO
  *     @arg DBG_IWDG_STOP
  *     @arg DBG_TIM1_STOP
  *     @arg DBG_TIM3_STOP
  *     @arg DBG_TIM1_PWM_OFF
  *     @arg DBG_TIM3_PWM_OFF
  *     @arg DBG_TIM14_STOP
  * @param  state: new state of the specified DBG peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void DBG_Configure(uint32_t periph, FunctionalState state)
{
    (state) ?             \
    (DBG->CR |= periph) : \
    (DBG->CR &= ~periph);
}

/**
  * @brief  Returns the device identifier..
  * @param  None.
  * @retval return the device Device identifier.
  */
uint32_t DBG_GetDeviceIDCode(void)
{
    return ((uint32_t)DBG->IDCODE);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */


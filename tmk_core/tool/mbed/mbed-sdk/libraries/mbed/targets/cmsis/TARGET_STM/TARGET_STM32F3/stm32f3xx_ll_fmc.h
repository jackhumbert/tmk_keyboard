/**
  ******************************************************************************
  * @file    stm32f3xx_ll_fmc.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    12-Sept-2014
  * @brief   Header file of FMC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F3xx_LL_FMC_H
#define __STM32F3xx_LL_FMC_H

#ifdef __cplusplus
 extern "C" {
#endif

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx)

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal_def.h"

/** @addtogroup STM32F3xx_HAL_Driver
  * @{
  */

/** @addtogroup FMC
  * @{
  */ 

/* Exported typedef ----------------------------------------------------------*/ 
#define FMC_NORSRAM_TypeDef            FMC_Bank1_TypeDef
#define FMC_NORSRAM_EXTENDED_TypeDef   FMC_Bank1E_TypeDef
#define FMC_NAND_TypeDef               FMC_Bank2_3_TypeDef
#define FMC_PCCARD_TypeDef             FMC_Bank4_TypeDef

#define FMC_NORSRAM_DEVICE             FMC_Bank1            
#define FMC_NORSRAM_EXTENDED_DEVICE    FMC_Bank1E   
#define FMC_NAND_DEVICE                FMC_Bank2_3             
#define FMC_PCCARD_DEVICE              FMC_Bank4             

/** 
  * @brief  FMC_NORSRAM Configuration Structure definition  
  */ 
typedef struct
{
  uint32_t NSBank;                       /*!< Specifies the NORSRAM memory device that will be used.
                                              This parameter can be a value of @ref FMC_NORSRAM_Bank                     */  
                                                    
  uint32_t DataAddressMux;               /*!< Specifies whether the address and data values are
                                              multiplexed on the data bus or not. 
                                              This parameter can be a value of @ref FMC_Data_Address_Bus_Multiplexing    */
  
  uint32_t MemoryType;                   /*!< Specifies the type of external memory attached to
                                              the corresponding memory device.
                                              This parameter can be a value of @ref FMC_Memory_Type                      */
                                              
  uint32_t MemoryDataWidth;              /*!< Specifies the external memory device width.
                                              This parameter can be a value of @ref FMC_NORSRAM_Data_Width               */
  
  uint32_t BurstAccessMode;              /*!< Enables or disables the burst access mode for Flash memory,
                                              valid only with synchronous burst Flash memories.
                                              This parameter can be a value of @ref FMC_Burst_Access_Mode                */
                                               
  uint32_t WaitSignalPolarity;           /*!< Specifies the wait signal polarity, valid only when accessing
                                              the Flash memory in burst mode.
                                              This parameter can be a value of @ref FMC_Wait_Signal_Polarity             */
  
  uint32_t WrapMode;                     /*!< Enables or disables the Wrapped burst access mode for Flash
                                              memory, valid only when accessing Flash memories in burst mode.
                                              This parameter can be a value of @ref FMC_Wrap_Mode                        */
  
  uint32_t WaitSignalActive;             /*!< Specifies if the wait signal is asserted by the memory one
                                              clock cycle before the wait state or during the wait state,
                                              valid only when accessing memories in burst mode. 
                                              This parameter can be a value of @ref FMC_Wait_Timing                      */
  
  uint32_t WriteOperation;               /*!< Enables or disables the write operation in the selected device by the FMC. 
                                              This parameter can be a value of @ref FMC_Write_Operation                  */
  
  uint32_t WaitSignal;                   /*!< Enables or disables the wait state insertion via wait
                                              signal, valid for Flash memory access in burst mode. 
                                              This parameter can be a value of @ref FMC_Wait_Signal                      */
  
  uint32_t ExtendedMode;                 /*!< Enables or disables the extended mode.
                                              This parameter can be a value of @ref FMC_Extended_Mode                    */
  
  uint32_t AsynchronousWait;             /*!< Enables or disables wait signal during asynchronous transfers,
                                              valid only with asynchronous Flash memories.
                                              This parameter can be a value of @ref FMC_AsynchronousWait                 */
  
  uint32_t WriteBurst;                   /*!< Enables or disables the write burst operation.
                                              This parameter can be a value of @ref FMC_Write_Burst                      */ 

  uint32_t ContinuousClock;              /*!< Enables or disables the FMC clock output to external memory devices.
                                              This parameter is only enabled through the FMC_BCR1 register, and don't care 
                                              through FMC_BCR2..4 registers.
                                              This parameter can be a value of @ref FMC_Continous_Clock                  */

}FMC_NORSRAM_InitTypeDef;

/** 
  * @brief  FMC_NORSRAM Timing parameters structure definition  
  */
typedef struct
{
  uint32_t AddressSetupTime;             /*!< Defines the number of HCLK cycles to configure
                                              the duration of the address setup time. 
                                              This parameter can be a value between Min_Data = 0 and Max_Data = 15.
                                              @note This parameter is not used with synchronous NOR Flash memories.      */
  
  uint32_t AddressHoldTime;              /*!< Defines the number of HCLK cycles to configure
                                              the duration of the address hold time.
                                              This parameter can be a value between Min_Data = 1 and Max_Data = 15. 
                                              @note This parameter is not used with synchronous NOR Flash memories.      */
  
  uint32_t DataSetupTime;                /*!< Defines the number of HCLK cycles to configure
                                              the duration of the data setup time.
                                              This parameter can be a value between Min_Data = 1 and Max_Data = 255.
                                              @note This parameter is used for SRAMs, ROMs and asynchronous multiplexed 
                                              NOR Flash memories.                                                        */
  
  uint32_t BusTurnAroundDuration;        /*!< Defines the number of HCLK cycles to configure
                                              the duration of the bus turnaround.
                                              This parameter can be a value between Min_Data = 0 and Max_Data = 15.
                                              @note This parameter is only used for multiplexed NOR Flash memories.      */
  
  uint32_t CLKDivision;                  /*!< Defines the period of CLK clock output signal, expressed in number of 
                                              HCLK cycles. This parameter can be a value between Min_Data = 2 and Max_Data = 16.
                                              @note This parameter is not used for asynchronous NOR Flash, SRAM or ROM 
                                              accesses.                                                                  */
  
  uint32_t DataLatency;                  /*!< Defines the number of memory clock cycles to issue
                                              to the memory before getting the first data.
                                              The parameter value depends on the memory type as shown below:
                                              - It must be set to 0 in case of a CRAM
                                              - It is don't care in asynchronous NOR, SRAM or ROM accesses
                                              - It may assume a value between Min_Data = 2 and Max_Data = 17 in NOR Flash memories
                                                with synchronous burst mode enable                                       */
  
  uint32_t AccessMode;                   /*!< Specifies the asynchronous access mode. 
                                              This parameter can be a value of @ref FMC_Access_Mode                      */

}FMC_NORSRAM_TimingTypeDef;

/** 
  * @brief  FMC_NAND Configuration Structure definition  
  */ 
typedef struct
{
  uint32_t NandBank;               /*!< Specifies the NAND memory device that will be used.
                                        This parameter can be a value of @ref FMC_NAND_Bank                    */           
  
  uint32_t Waitfeature;            /*!< Enables or disables the Wait feature for the NAND Memory device.
                                        This parameter can be any value of @ref FMC_Wait_feature               */
  
  uint32_t MemoryDataWidth;        /*!< Specifies the external memory device width.
                                        This parameter can be any value of @ref FMC_NAND_Data_Width            */
  
  uint32_t EccComputation;         /*!< Enables or disables the ECC computation.
                                        This parameter can be any value of @ref FMC_ECC                        */
  
  uint32_t ECCPageSize;            /*!< Defines the page size for the extended ECC.
                                        This parameter can be any value of @ref FMC_ECC_Page_Size              */
  
  uint32_t TCLRSetupTime;          /*!< Defines the number of HCLK cycles to configure the
                                        delay between CLE low and RE low.
                                        This parameter can be a value between Min_Data = 0 and Max_Data = 255  */
  
  uint32_t TARSetupTime;           /*!< Defines the number of HCLK cycles to configure the
                                        delay between ALE low and RE low.
                                        This parameter can be a number between Min_Data = 0 and Max_Data = 255 */
                                     
}FMC_NAND_InitTypeDef;  

/** 
  * @brief  FMC_NAND_PCCARD Timing parameters structure definition
  */
typedef struct
{
  uint32_t SetupTime;            /*!< Defines the number of HCLK cycles to setup address before
                                      the command assertion for NAND-Flash read or write access
                                      to common/Attribute or I/O memory space (depending on
                                      the memory space timing to be configured).
                                      This parameter can be a value between Min_Data = 0 and Max_Data = 255    */
  
  uint32_t WaitSetupTime;        /*!< Defines the minimum number of HCLK cycles to assert the
                                      command for NAND-Flash read or write access to
                                      common/Attribute or I/O memory space (depending on the
                                      memory space timing to be configured). 
                                      This parameter can be a number between Min_Data = 0 and Max_Data = 255   */
  
  uint32_t HoldSetupTime;        /*!< Defines the number of HCLK clock cycles to hold address
                                      (and data for write access) after the command de-assertion
                                      for NAND-Flash read or write access to common/Attribute
                                      or I/O memory space (depending on the memory space timing
                                      to be configured).
                                      This parameter can be a number between Min_Data = 0 and Max_Data = 255   */
  
  uint32_t HiZSetupTime;         /*!< Defines the number of HCLK clock cycles during which the
                                      data bus is kept in HiZ after the start of a NAND-Flash
                                      write access to common/Attribute or I/O memory space (depending
                                      on the memory space timing to be configured).
                                      This parameter can be a number between Min_Data = 0 and Max_Data = 255   */
  
}FMC_NAND_PCC_TimingTypeDef;

/** 
  * @brief  FMC_NAND Configuration Structure definition  
  */ 
typedef struct
{
  uint32_t Waitfeature;            /*!< Enables or disables the Wait feature for the PCCARD Memory device.
                                        This parameter can be any value of @ref FMC_Wait_feature               */
  
  uint32_t TCLRSetupTime;          /*!< Defines the number of HCLK cycles to configure the
                                        delay between CLE low and RE low.
                                        This parameter can be a value between Min_Data = 0 and Max_Data = 255  */
  
  uint32_t TARSetupTime;           /*!< Defines the number of HCLK cycles to configure the
                                        delay between ALE low and RE low.
                                        This parameter can be a number between Min_Data = 0 and Max_Data = 255 */
                                     
}FMC_PCCARD_InitTypeDef;  

/* Exported constants --------------------------------------------------------*/

/** @defgroup FMC_NOR_SRAM_Controller 
  * @{
  */ 
  
/** @defgroup FMC_NORSRAM_Bank 
  * @{
  */
#define FMC_NORSRAM_BANK1                       ((uint32_t)0x00000000)
#define FMC_NORSRAM_BANK2                       ((uint32_t)0x00000002)
#define FMC_NORSRAM_BANK3                       ((uint32_t)0x00000004)
#define FMC_NORSRAM_BANK4                       ((uint32_t)0x00000006)

#define IS_FMC_NORSRAM_BANK(BANK) (((BANK) == FMC_NORSRAM_BANK1) || \
                                   ((BANK) == FMC_NORSRAM_BANK2) || \
                                   ((BANK) == FMC_NORSRAM_BANK3) || \
                                   ((BANK) == FMC_NORSRAM_BANK4))
/**
  * @}
  */

/** @defgroup FMC_Data_Address_Bus_Multiplexing 
  * @{
  */
#define FMC_DATA_ADDRESS_MUX_DISABLE            ((uint32_t)0x00000000)
#define FMC_DATA_ADDRESS_MUX_ENABLE             ((uint32_t)0x00000002)

#define IS_FMC_MUX(MUX) (((MUX) == FMC_DATA_ADDRESS_MUX_DISABLE) || \
                         ((MUX) == FMC_DATA_ADDRESS_MUX_ENABLE))
/**
  * @}
  */

/** @defgroup FMC_Memory_Type 
  * @{
  */
#define FMC_MEMORY_TYPE_SRAM                    ((uint32_t)0x00000000)
#define FMC_MEMORY_TYPE_PSRAM                   ((uint32_t)0x00000004)
#define FMC_MEMORY_TYPE_NOR                     ((uint32_t)0x00000008)

#define IS_FMC_MEMORY(MEMORY) (((MEMORY) == FMC_MEMORY_TYPE_SRAM) || \
                               ((MEMORY) == FMC_MEMORY_TYPE_PSRAM)|| \
                               ((MEMORY) == FMC_MEMORY_TYPE_NOR))
/**
  * @}
  */

/** @defgroup FMC_NORSRAM_Data_Width 
  * @{
  */
#define FMC_NORSRAM_MEM_BUS_WIDTH_8             ((uint32_t)0x00000000)
#define FMC_NORSRAM_MEM_BUS_WIDTH_16            ((uint32_t)0x00000010)
#define FMC_NORSRAM_MEM_BUS_WIDTH_32            ((uint32_t)0x00000020)

#define IS_FMC_NORSRAM_MEMORY_WIDTH(WIDTH) (((WIDTH) == FMC_NORSRAM_MEM_BUS_WIDTH_8)  || \
                                            ((WIDTH) == FMC_NORSRAM_MEM_BUS_WIDTH_16) || \
                                            ((WIDTH) == FMC_NORSRAM_MEM_BUS_WIDTH_32))
/**
  * @}
  */

/** @defgroup FMC_NORSRAM_Flash_Access 
  * @{
  */
#define FMC_NORSRAM_FLASH_ACCESS_ENABLE         ((uint32_t)0x00000040)
#define FMC_NORSRAM_FLASH_ACCESS_DISABLE        ((uint32_t)0x00000000)
/**
  * @}
  */

/** @defgroup FMC_Burst_Access_Mode 
  * @{
  */
#define FMC_BURST_ACCESS_MODE_DISABLE           ((uint32_t)0x00000000) 
#define FMC_BURST_ACCESS_MODE_ENABLE            ((uint32_t)0x00000100)

#define IS_FMC_BURSTMODE(STATE) (((STATE) == FMC_BURST_ACCESS_MODE_DISABLE) || \
                                 ((STATE) == FMC_BURST_ACCESS_MODE_ENABLE))
/**
  * @}
  */
    

/** @defgroup FMC_Wait_Signal_Polarity 
  * @{
  */
#define FMC_WAIT_SIGNAL_POLARITY_LOW            ((uint32_t)0x00000000)
#define FMC_WAIT_SIGNAL_POLARITY_HIGH           ((uint32_t)0x00000200)

#define IS_FMC_WAIT_POLARITY(POLARITY) (((POLARITY) == FMC_WAIT_SIGNAL_POLARITY_LOW) || \
                                        ((POLARITY) == FMC_WAIT_SIGNAL_POLARITY_HIGH))
/**
  * @}
  */

/** @defgroup FMC_Wrap_Mode 
  * @{
  */
#define FMC_WRAP_MODE_DISABLE                   ((uint32_t)0x00000000)
#define FMC_WRAP_MODE_ENABLE                    ((uint32_t)0x00000400)

#define IS_FMC_WRAP_MODE(MODE) (((MODE) == FMC_WRAP_MODE_DISABLE) || \
                                ((MODE) == FMC_WRAP_MODE_ENABLE)) 
/**
  * @}
  */

/** @defgroup FMC_Wait_Timing 
  * @{
  */
#define FMC_WAIT_TIMING_BEFORE_WS               ((uint32_t)0x00000000)
#define FMC_WAIT_TIMING_DURING_WS               ((uint32_t)0x00000800)

#define IS_FMC_WAIT_SIGNAL_ACTIVE(ACTIVE) (((ACTIVE) == FMC_WAIT_TIMING_BEFORE_WS) || \
                                           ((ACTIVE) == FMC_WAIT_TIMING_DURING_WS)) 
/**
  * @}
  */

/** @defgroup FMC_Write_Operation 
  * @{
  */
#define FMC_WRITE_OPERATION_DISABLE             ((uint32_t)0x00000000)
#define FMC_WRITE_OPERATION_ENABLE              ((uint32_t)0x00001000)

#define IS_FMC_WRITE_OPERATION(OPERATION) (((OPERATION) == FMC_WRITE_OPERATION_DISABLE) || \
                                           ((OPERATION) == FMC_WRITE_OPERATION_ENABLE))                       
/**
  * @}
  */

/** @defgroup FMC_Wait_Signal 
  * @{
  */
#define FMC_WAIT_SIGNAL_DISABLE                 ((uint32_t)0x00000000)
#define FMC_WAIT_SIGNAL_ENABLE                  ((uint32_t)0x00002000)

#define IS_FMC_WAITE_SIGNAL(SIGNAL) (((SIGNAL) == FMC_WAIT_SIGNAL_DISABLE) || \
                                     ((SIGNAL) == FMC_WAIT_SIGNAL_ENABLE)) 
/**
  * @}
  */

/** @defgroup FMC_Extended_Mode 
  * @{
  */
#define FMC_EXTENDED_MODE_DISABLE               ((uint32_t)0x00000000)
#define FMC_EXTENDED_MODE_ENABLE                ((uint32_t)0x00004000)

#define IS_FMC_EXTENDED_MODE(MODE) (((MODE) == FMC_EXTENDED_MODE_DISABLE) || \
                                    ((MODE) == FMC_EXTENDED_MODE_ENABLE))
/**
  * @}
  */

/** @defgroup FMC_AsynchronousWait 
  * @{
  */
#define FMC_ASYNCHRONOUS_WAIT_DISABLE           ((uint32_t)0x00000000)
#define FMC_ASYNCHRONOUS_WAIT_ENABLE            ((uint32_t)0x00008000)

#define IS_FMC_ASYNWAIT(STATE) (((STATE) == FMC_ASYNCHRONOUS_WAIT_DISABLE) || \
                                ((STATE) == FMC_ASYNCHRONOUS_WAIT_ENABLE))
/**
  * @}
  */  

/** @defgroup FMC_Write_Burst 
  * @{
  */
#define FMC_WRITE_BURST_DISABLE                 ((uint32_t)0x00000000)
#define FMC_WRITE_BURST_ENABLE                  ((uint32_t)0x00080000)

#define IS_FMC_WRITE_BURST(BURST) (((BURST) == FMC_WRITE_BURST_DISABLE) || \
                                   ((BURST) == FMC_WRITE_BURST_ENABLE)) 
/**
  * @}
  */
  
/** @defgroup FMC_Continous_Clock 
  * @{
  */
#define FMC_CONTINUOUS_CLOCK_SYNC_ONLY          ((uint32_t)0x00000000)
#define FMC_CONTINUOUS_CLOCK_SYNC_ASYNC         ((uint32_t)0x00100000)

#define IS_FMC_CONTINOUS_CLOCK(CCLOCK) (((CCLOCK) == FMC_CONTINUOUS_CLOCK_SYNC_ONLY) || \
                                        ((CCLOCK) == FMC_CONTINUOUS_CLOCK_SYNC_ASYNC)) 
/**
  * @}
  */
  
/** @defgroup FMC_Address_Setup_Time 
  * @{
  */
#define IS_FMC_ADDRESS_SETUP_TIME(TIME) ((TIME) <= 15)
/**
  * @}
  */

/** @defgroup FMC_Address_Hold_Time 
  * @{
  */
#define IS_FMC_ADDRESS_HOLD_TIME(TIME) (((TIME) > 0) && ((TIME) <= 15))
/**
  * @}
  */

/** @defgroup FMC_Data_Setup_Time 
  * @{
  */
#define IS_FMC_DATASETUP_TIME(TIME) (((TIME) > 0) && ((TIME) <= 255))
/**
  * @}
  */

/** @defgroup FMC_Bus_Turn_around_Duration 
  * @{
  */
#define IS_FMC_TURNAROUND_TIME(TIME) ((TIME) <= 15)
/**
  * @}
  */

/** @defgroup FMC_CLK_Division 
  * @{
  */
#define IS_FMC_CLK_DIV(DIV) (((DIV) > 1) && ((DIV) <= 16))
/**
  * @}
  */

/** @defgroup FMC_Data_Latency 
  * @{
  */
#define IS_FMC_DATA_LATENCY(LATENCY) (((LATENCY) > 1) && ((LATENCY) <= 17))
/**
  * @}
  */  

/** @defgroup FMC_Access_Mode 
  * @{
  */
#define FMC_ACCESS_MODE_A                        ((uint32_t)0x00000000)
#define FMC_ACCESS_MODE_B                        ((uint32_t)0x10000000) 
#define FMC_ACCESS_MODE_C                        ((uint32_t)0x20000000)
#define FMC_ACCESS_MODE_D                        ((uint32_t)0x30000000)

#define IS_FMC_ACCESS_MODE(MODE) (((MODE) == FMC_ACCESS_MODE_A) || \
                                  ((MODE) == FMC_ACCESS_MODE_B) || \
                                  ((MODE) == FMC_ACCESS_MODE_C) || \
                                  ((MODE) == FMC_ACCESS_MODE_D))
/**
  * @}
  */
    
/**
  * @}
  */  

/** @defgroup FMC_NAND_Controller 
  * @{
  */

/** @defgroup FMC_NAND_Bank 
  * @{
  */  
#define FMC_NAND_BANK2                          ((uint32_t)0x00000010)
#define FMC_NAND_BANK3                          ((uint32_t)0x00000100)

#define IS_FMC_NAND_BANK(BANK) (((BANK) == FMC_NAND_BANK2) || \
                                ((BANK) == FMC_NAND_BANK3))  
/**
  * @}
  */

/** @defgroup FMC_Wait_feature 
  * @{
  */
#define FMC_NAND_PCC_WAIT_FEATURE_DISABLE           ((uint32_t)0x00000000)
#define FMC_NAND_PCC_WAIT_FEATURE_ENABLE            ((uint32_t)0x00000002)

#define IS_FMC_WAIT_FEATURE(FEATURE) (((FEATURE) == FMC_NAND_PCC_WAIT_FEATURE_DISABLE) || \
                                      ((FEATURE) == FMC_NAND_PCC_WAIT_FEATURE_ENABLE))                                              
/**
  * @}
  */

/** @defgroup FMC_PCR_Memory_Type 
  * @{
  */
#define FMC_PCR_MEMORY_TYPE_PCCARD        ((uint32_t)0x00000000)
#define FMC_PCR_MEMORY_TYPE_NAND          ((uint32_t)0x00000008)
/**
  * @}
  */

/** @defgroup FMC_NAND_Data_Width 
  * @{
  */
#define FMC_NAND_PCC_MEM_BUS_WIDTH_8                ((uint32_t)0x00000000)
#define FMC_NAND_PCC_MEM_BUS_WIDTH_16               ((uint32_t)0x00000010)

#define IS_FMC_NAND_MEMORY_WIDTH(WIDTH) (((WIDTH) == FMC_NAND_PCC_MEM_BUS_WIDTH_8) || \
                                         ((WIDTH) == FMC_NAND_PCC_MEM_BUS_WIDTH_16))
/**
  * @}
  */

/** @defgroup FMC_ECC 
  * @{
  */
#define FMC_NAND_ECC_DISABLE                    ((uint32_t)0x00000000)
#define FMC_NAND_ECC_ENABLE                     ((uint32_t)0x00000040)

#define IS_FMC_ECC_STATE(STATE) (((STATE) == FMC_NAND_ECC_DISABLE) || \
                                 ((STATE) == FMC_NAND_ECC_ENABLE))
/**
  * @}
  */

/** @defgroup FMC_ECC_Page_Size 
  * @{
  */
#define FMC_NAND_ECC_PAGE_SIZE_256BYTE          ((uint32_t)0x00000000)
#define FMC_NAND_ECC_PAGE_SIZE_512BYTE          ((uint32_t)0x00020000)
#define FMC_NAND_ECC_PAGE_SIZE_1024BYTE         ((uint32_t)0x00040000)
#define FMC_NAND_ECC_PAGE_SIZE_2048BYTE         ((uint32_t)0x00060000)
#define FMC_NAND_ECC_PAGE_SIZE_4096BYTE         ((uint32_t)0x00080000)
#define FMC_NAND_ECC_PAGE_SIZE_8192BYTE         ((uint32_t)0x000A0000)

#define IS_FMC_ECCPAGE_SIZE(SIZE) (((SIZE) == FMC_NAND_ECC_PAGE_SIZE_256BYTE)  || \
                                   ((SIZE) == FMC_NAND_ECC_PAGE_SIZE_512BYTE)  || \
                                   ((SIZE) == FMC_NAND_ECC_PAGE_SIZE_1024BYTE) || \
                                   ((SIZE) == FMC_NAND_ECC_PAGE_SIZE_2048BYTE) || \
                                   ((SIZE) == FMC_NAND_ECC_PAGE_SIZE_4096BYTE) || \
                                   ((SIZE) == FMC_NAND_ECC_PAGE_SIZE_8192BYTE))
/**
  * @}
  */

/** @defgroup FMC_TCLR_Setup_Time 
  * @{
  */
#define IS_FMC_TCLR_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_TAR_Setup_Time 
  * @{
  */
#define IS_FMC_TAR_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_Setup_Time 
  * @{
  */
#define IS_FMC_SETUP_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_Wait_Setup_Time 
  * @{
  */
#define IS_FMC_WAIT_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_Hold_Setup_Time 
  * @{
  */
#define IS_FMC_HOLD_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_HiZ_Setup_Time 
  * @{
  */
#define IS_FMC_HIZ_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */  
    
/**
  * @}
  */  

/** @defgroup FMC_NORSRAM_Device_Instance
  * @{
  */
#define IS_FMC_NORSRAM_DEVICE(INSTANCE) ((INSTANCE) == FMC_NORSRAM_DEVICE)
/**
  * @}
  */

/** @defgroup FMC_NORSRAM_EXTENDED_Device_Instance
  * @{
  */
#define IS_FMC_NORSRAM_EXTENDED_DEVICE(INSTANCE) ((INSTANCE) == FMC_NORSRAM_EXTENDED_DEVICE)
/**
  * @}
  */
  
/** @defgroup FMC_NAND_Device_Instance
  * @{
  */
#define IS_FMC_NAND_DEVICE(INSTANCE) ((INSTANCE) == FMC_NAND_DEVICE)
/**
  * @}
  */  

/** @defgroup FMC_PCCARD_Device_Instance
  * @{
  */
#define IS_FMC_PCCARD_DEVICE(INSTANCE) ((INSTANCE) == FMC_PCCARD_DEVICE)

/**
  * @}
  */ 

/** @defgroup FMC_Interrupt_definition 
  * @brief FMC Interrupt definition
  * @{
  */  
#define FMC_IT_RISING_EDGE                ((uint32_t)0x00000008)
#define FMC_IT_LEVEL                      ((uint32_t)0x00000010)
#define FMC_IT_FALLING_EDGE               ((uint32_t)0x00000020)
#define FMC_IT_REFRESH_ERROR              ((uint32_t)0x00004000)

#define IS_FMC_IT(IT) ((((IT) & (uint32_t)0xFFFFBFC7) == 0x00000000) && ((IT) != 0x00000000))

#define IS_FMC_GET_IT(IT) (((IT) == FMC_IT_RISING_EDGE)   || \
                           ((IT) == FMC_IT_LEVEL)         || \
                           ((IT) == FMC_IT_FALLING_EDGE)  || \
                           ((IT) == FMC_IT_REFRESH_ERROR)) 
/**
  * @}
  */
    
/** @defgroup FMC_Flag_definition 
  * @brief FMC Flag definition
  * @{
  */ 
#define FMC_FLAG_RISING_EDGE                    ((uint32_t)0x00000001)
#define FMC_FLAG_LEVEL                          ((uint32_t)0x00000002)
#define FMC_FLAG_FALLING_EDGE                   ((uint32_t)0x00000004)
#define FMC_FLAG_FEMPT                          ((uint32_t)0x00000040)

#define IS_FMC_GET_FLAG(FLAG) (((FLAG) == FMC_FLAG_RISING_EDGE)      || \
                               ((FLAG) == FMC_FLAG_LEVEL)            || \
                               ((FLAG) == FMC_FLAG_FALLING_EDGE)     || \
                               ((FLAG) == FMC_FLAG_FEMPT))

#define IS_FMC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFF8) == 0x00000000) && ((FLAG) != 0x00000000))                               
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup FMC_NOR_Macros
 *  @brief macros to handle NOR device enable/disable and read/write operations
 *  @{
 */
 
/**
  * @brief  Enable the NORSRAM device access.
  * @param  __INSTANCE__: FMC_NORSRAM Instance
  * @param  __BANK__: FMC_NORSRAM Bank     
  * @retval None
  */ 
#define __FMC_NORSRAM_ENABLE(__INSTANCE__, __BANK__)  ((__INSTANCE__)->BTCR[(__BANK__)] |= FMC_BCR1_MBKEN)

/**
  * @brief  Disable the NORSRAM device access.
  * @param  __INSTANCE__: FMC_NORSRAM Instance
  * @param  __BANK__: FMC_NORSRAM Bank   
  * @retval None
  */ 
#define __FMC_NORSRAM_DISABLE(__INSTANCE__, __BANK__) ((__INSTANCE__)->BTCR[(__BANK__)] &= ~FMC_BCR1_MBKEN)  

/**
  * @}
  */ 

/** @defgroup FMC_NAND_Macros
 *  @brief macros to handle NAND device enable/disable
 *  @{
 */
 
/**
  * @brief  Enable the NAND device access.
  * @param  __INSTANCE__: FMC_NAND Instance
  * @param  __BANK__: FMC_NAND Bank    
  * @retval None
  */  
#define __FMC_NAND_ENABLE(__INSTANCE__, __BANK__)  (((__BANK__) == FMC_NAND_BANK2)? ((__INSTANCE__)->PCR2 |= FMC_PCR2_PBKEN): \
                                                    ((__INSTANCE__)->PCR3 |= FMC_PCR3_PBKEN))                                        

/**
  * @brief  Disable the NAND device access.
  * @param  __INSTANCE__: FMC_NAND Instance
  * @param  __BANK__: FMC_NAND Bank  
  * @retval None
  */                                          
#define __FMC_NAND_DISABLE(__INSTANCE__, __BANK__) (((__BANK__) == FMC_NAND_BANK2)? ((__INSTANCE__)->PCR2 &= ~FMC_PCR2_PBKEN): \
                                                   ((__INSTANCE__)->PCR3 &= ~FMC_PCR3_PBKEN))                                                                                
/**
  * @}
  */ 
  
/** @defgroup FMC_PCCARD_Macros
 *  @brief macros to handle SRAM read/write operations 
 *  @{
 */

/**
  * @brief  Enable the PCCARD device access.
  * @param  __INSTANCE__: FMC_PCCARD Instance  
  * @retval None
  */ 
#define __FMC_PCCARD_ENABLE(__INSTANCE__)  ((__INSTANCE__)->PCR4 |= FMC_PCR4_PBKEN)

/**
  * @brief  Disable the PCCARD device access.
  * @param  __INSTANCE__: FMC_PCCARD Instance     
  * @retval None
  */ 
#define __FMC_PCCARD_DISABLE(__INSTANCE__) ((__INSTANCE__)->PCR4 &= ~FMC_PCR4_PBKEN)
/**
  * @}
  */
  
/** @defgroup FMC_Interrupt
 *  @brief macros to handle FMC interrupts
 * @{
 */ 

/**
  * @brief  Enable the NAND device interrupt.
  * @param  __INSTANCE__:  FMC_NAND Instance
  * @param  __BANK__:      FMC_NAND Bank     
  * @param  __INTERRUPT__: FMC_NAND interrupt 
  *         This parameter can be any combination of the following values:
  *            @arg FMC_IT_RISING_EDGE: Interrupt rising edge.
  *            @arg FMC_IT_LEVEL: Interrupt level.
  *            @arg FMC_IT_FALLING_EDGE: Interrupt falling edge.       
  * @retval None
  */  
#define __FMC_NAND_ENABLE_IT(__INSTANCE__, __BANK__, __INTERRUPT__)  (((__BANK__) == FMC_NAND_BANK2)? ((__INSTANCE__)->SR2 |= (__INTERRUPT__)): \
                                                                                                      ((__INSTANCE__)->SR3 |= (__INTERRUPT__)))

/**
  * @brief  Disable the NAND device interrupt.
  * @param  __INSTANCE__:  FMC_NAND Instance
  * @param  __BANK__:      FMC_NAND Bank    
  * @param  __INTERRUPT__: FMC_NAND interrupt
  *         This parameter can be any combination of the following values:
  *            @arg FMC_IT_RISING_EDGE: Interrupt rising edge.
  *            @arg FMC_IT_LEVEL: Interrupt level.
  *            @arg FMC_IT_FALLING_EDGE: Interrupt falling edge.   
  * @retval None
  */
#define __FMC_NAND_DISABLE_IT(__INSTANCE__, __BANK__, __INTERRUPT__)  (((__BANK__) == FMC_NAND_BANK2)? ((__INSTANCE__)->SR2 &= ~(__INTERRUPT__)): \
                                                                                                      ((__INSTANCE__)->SR3 &= ~(__INTERRUPT__))) 
                                                                                                                             
/**
  * @brief  Get flag status of the NAND device.
  * @param  __INSTANCE__: FMC_NAND Instance
  * @param  __BANK__:     FMC_NAND Bank      
  * @param  __FLAG__: FMC_NAND flag
  *         This parameter can be any combination of the following values:
  *            @arg FMC_FLAG_RISING_EDGE: Interrupt rising edge flag.
  *            @arg FMC_FLAG_LEVEL: Interrupt level edge flag.
  *            @arg FMC_FLAG_FALLING_EDGE: Interrupt falling edge flag.
  *            @arg FMC_FLAG_FEMPT: FIFO empty flag.   
  * @retval The state of FLAG (SET or RESET).
  */
#define __FMC_NAND_GET_FLAG(__INSTANCE__, __BANK__, __FLAG__)  (((__BANK__) == FMC_NAND_BANK2)? (((__INSTANCE__)->SR2 &(__FLAG__)) == (__FLAG__)): \
                                                                                                (((__INSTANCE__)->SR3 &(__FLAG__)) == (__FLAG__)))
/**
  * @brief  Clear flag status of the NAND device.
  * @param  __INSTANCE__: FMC_NAND Instance  
  * @param  __BANK__:     FMC_NAND Bank  
  * @param  __FLAG__: FMC_NAND flag
  *         This parameter can be any combination of the following values:
  *            @arg FMC_FLAG_RISING_EDGE: Interrupt rising edge flag.
  *            @arg FMC_FLAG_LEVEL: Interrupt level edge flag.
  *            @arg FMC_FLAG_FALLING_EDGE: Interrupt falling edge flag.
  *            @arg FMC_FLAG_FEMPT: FIFO empty flag.   
  * @retval None
  */
#define __FMC_NAND_CLEAR_FLAG(__INSTANCE__, __BANK__, __FLAG__)  (((__BANK__) == FMC_NAND_BANK2)? ((__INSTANCE__)->SR2 &= ~(__FLAG__)): \
                                                                                                  ((__INSTANCE__)->SR3 &= ~(__FLAG__))) 
/**
  * @brief  Enable the PCCARD device interrupt.
  * @param  __INSTANCE__: FMC_PCCARD Instance  
  * @param  __INTERRUPT__: FMC_PCCARD interrupt 
  *         This parameter can be any combination of the following values:
  *            @arg FMC_IT_RISING_EDGE: Interrupt rising edge.
  *            @arg FMC_IT_LEVEL: Interrupt level.
  *            @arg FMC_IT_FALLING_EDGE: Interrupt falling edge.       
  * @retval None
  */ 
#define __FMC_PCCARD_ENABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->SR4 |= (__INTERRUPT__))

/**
  * @brief  Disable the PCCARD device interrupt.
  * @param  __INSTANCE__: FMC_PCCARD Instance  
  * @param  __INTERRUPT__: FMC_PCCARD interrupt 
  *         This parameter can be any combination of the following values:
  *            @arg FMC_IT_RISING_EDGE: Interrupt rising edge.
  *            @arg FMC_IT_LEVEL: Interrupt level.
  *            @arg FMC_IT_FALLING_EDGE: Interrupt falling edge.       
  * @retval None
  */ 
#define __FMC_PCCARD_DISABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->SR4 &= ~(__INTERRUPT__)) 

/**
  * @brief  Get flag status of the PCCARD device.
  * @param  __INSTANCE__: FMC_PCCARD Instance  
  * @param  __FLAG__: FMC_PCCARD flag
  *         This parameter can be any combination of the following values:
  *            @arg  FMC_FLAG_RISING_EDGE: Interrupt rising edge flag.
  *            @arg  FMC_FLAG_LEVEL: Interrupt level edge flag.
  *            @arg  FMC_FLAG_FALLING_EDGE: Interrupt falling edge flag.
  *            @arg  FMC_FLAG_FEMPT: FIFO empty flag.   
  * @retval The state of FLAG (SET or RESET).
  */
#define __FMC_PCCARD_GET_FLAG(__INSTANCE__, __FLAG__)  (((__INSTANCE__)->SR4 &(__FLAG__)) == (__FLAG__))

/**
  * @brief  Clear flag status of the PCCARD device.
  * @param  __INSTANCE__: FMC_PCCARD Instance  
  * @param  __FLAG__: FMC_PCCARD flag
  *         This parameter can be any combination of the following values:
  *            @arg  FMC_FLAG_RISING_EDGE: Interrupt rising edge flag.
  *            @arg  FMC_FLAG_LEVEL: Interrupt level edge flag.
  *            @arg  FMC_FLAG_FALLING_EDGE: Interrupt falling edge flag.
  *            @arg  FMC_FLAG_FEMPT: FIFO empty flag.   
  * @retval None
  */
#define __FMC_PCCARD_CLEAR_FLAG(__INSTANCE__, __FLAG__)  ((__INSTANCE__)->SR4 &= ~(__FLAG__))
 
/**
  * @}
  */ 

/* Exported functions --------------------------------------------------------*/

/* FMC_NORSRAM Controller functions *******************************************/
/* Initialization/de-initialization functions */
HAL_StatusTypeDef  FMC_NORSRAM_Init(FMC_NORSRAM_TypeDef *Device, FMC_NORSRAM_InitTypeDef *Init);
HAL_StatusTypeDef  FMC_NORSRAM_Timing_Init(FMC_NORSRAM_TypeDef *Device, FMC_NORSRAM_TimingTypeDef *Timing, uint32_t Bank);
HAL_StatusTypeDef  FMC_NORSRAM_Extended_Timing_Init(FMC_NORSRAM_EXTENDED_TypeDef *Device, FMC_NORSRAM_TimingTypeDef *Timing, uint32_t Bank, uint32_t ExtendedMode);
HAL_StatusTypeDef  FMC_NORSRAM_DeInit(FMC_NORSRAM_TypeDef *Device, FMC_NORSRAM_EXTENDED_TypeDef *ExDevice, uint32_t Bank);

/* FMC_NORSRAM Control functions */
HAL_StatusTypeDef  FMC_NORSRAM_WriteOperation_Enable(FMC_NORSRAM_TypeDef *Device, uint32_t Bank);
HAL_StatusTypeDef  FMC_NORSRAM_WriteOperation_Disable(FMC_NORSRAM_TypeDef *Device, uint32_t Bank);

/* FMC_NAND Controller functions **********************************************/
/* Initialization/de-initialization functions */
HAL_StatusTypeDef  FMC_NAND_Init(FMC_NAND_TypeDef *Device, FMC_NAND_InitTypeDef *Init);
HAL_StatusTypeDef  FMC_NAND_CommonSpace_Timing_Init(FMC_NAND_TypeDef *Device, FMC_NAND_PCC_TimingTypeDef *Timing, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_AttributeSpace_Timing_Init(FMC_NAND_TypeDef *Device, FMC_NAND_PCC_TimingTypeDef *Timing, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_DeInit(FMC_NAND_TypeDef *Device, uint32_t Bank);

/* FMC_NAND Control functions */
HAL_StatusTypeDef  FMC_NAND_ECC_Enable(FMC_NAND_TypeDef *Device, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_ECC_Disable(FMC_NAND_TypeDef *Device, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_GetECC(FMC_NAND_TypeDef *Device, uint32_t *ECCval, uint32_t Bank, uint32_t Timeout);

/* FMC_PCCARD Controller functions ********************************************/
/* Initialization/de-initialization functions */
HAL_StatusTypeDef  FMC_PCCARD_Init(FMC_PCCARD_TypeDef *Device, FMC_PCCARD_InitTypeDef *Init);
HAL_StatusTypeDef  FMC_PCCARD_CommonSpace_Timing_Init(FMC_PCCARD_TypeDef *Device, FMC_NAND_PCC_TimingTypeDef *Timing);
HAL_StatusTypeDef  FMC_PCCARD_AttributeSpace_Timing_Init(FMC_PCCARD_TypeDef *Device, FMC_NAND_PCC_TimingTypeDef *Timing);
HAL_StatusTypeDef  FMC_PCCARD_IOSpace_Timing_Init(FMC_PCCARD_TypeDef *Device, FMC_NAND_PCC_TimingTypeDef *Timing); 
HAL_StatusTypeDef  FMC_PCCARD_DeInit(FMC_PCCARD_TypeDef *Device);

#endif /* STM32F302xE || STM32F303xE || STM32F398xx */
/**
  * @}
  */ 

/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM32F3xx_LL_FMC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

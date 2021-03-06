cmake_minimum_required(VERSION 3.15)
project(Embedded_Player C)

set(CMAKE_C_STANDARD 11)

include_directories(Drivers/BSP/Components/adv7533)
include_directories(Drivers/BSP/Components/ampire480272)
include_directories(Drivers/BSP/Components/ampire640480)
include_directories(Drivers/BSP/Components/Common)
include_directories(Drivers/BSP/Components/exc7200)
include_directories(Drivers/BSP/Components/ft5336)
include_directories(Drivers/BSP/Components/ft6x06)
include_directories(Drivers/BSP/Components/mfxstm32l152)
include_directories(Drivers/BSP/Components/mx25l512)
include_directories(Drivers/BSP/Components/n25q128a)
include_directories(Drivers/BSP/Components/n25q512a)
include_directories(Drivers/BSP/Components/otm8009a)
include_directories(Drivers/BSP/Components/ov9655)
include_directories(Drivers/BSP/Components/rk043fn48h)
include_directories(Drivers/BSP/Components/s5k5cag)
include_directories(Drivers/BSP/Components/st7735)
include_directories(Drivers/BSP/Components/st7789h2)
include_directories(Drivers/BSP/Components/stmpe811)
include_directories(Drivers/BSP/Components/ts3510)
include_directories(Drivers/BSP/Components/wm8994)
include_directories(Drivers/BSP/STM32746G-Discovery)
include_directories(Drivers/CMSIS/Device/ST/STM32F7xx/Include)
include_directories(Drivers/CMSIS/Include)
include_directories(Drivers/CMSIS/RTOS)
include_directories(Drivers/CMSIS/RTOS/Template)
include_directories(Drivers/STM32F7xx_HAL_Driver/Inc)
include_directories(Drivers/STM32F7xx_HAL_Driver/Inc/Legacy)
include_directories(Inc)
include_directories(Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc)
include_directories(Middlewares/ST/STM32_USB_Host_Library/Core/Inc)
include_directories(Middlewares/Third_Party/FatFs/src)
include_directories(Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS)
include_directories(Middlewares/Third_Party/FreeRTOS/Source/include)
include_directories(Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1)
include_directories(Middlewares/Third_Party/LwIP/src/include)
include_directories(Middlewares/Third_Party/LwIP/src/include/lwip)
include_directories(Middlewares/Third_Party/LwIP/src/include/lwip/apps)
include_directories(Middlewares/Third_Party/LwIP/src/include/lwip/priv)
include_directories(Middlewares/Third_Party/LwIP/src/include/lwip/prot)
include_directories(Middlewares/Third_Party/LwIP/src/include/netif)
include_directories(Middlewares/Third_Party/LwIP/src/include/netif/ppp)
include_directories(Middlewares/Third_Party/LwIP/src/include/posix)
include_directories(Middlewares/Third_Party/LwIP/src/include/posix/sys)
include_directories(Middlewares/Third_Party/LwIP/system/arch)
include_directories(Utilities/CPU)
include_directories(Utilities/Fonts)
include_directories(Utilities/Log)

add_executable(Embedded_Player
    Drivers/BSP/Components/adv7533/adv7533.c
    Drivers/BSP/Components/adv7533/adv7533.h
    Drivers/BSP/Components/ampire480272/ampire480272.h
    Drivers/BSP/Components/ampire640480/ampire640480.h
    Drivers/BSP/Components/Common/accelero.h
    Drivers/BSP/Components/Common/audio.h
    Drivers/BSP/Components/Common/camera.h
    Drivers/BSP/Components/Common/epd.h
    Drivers/BSP/Components/Common/gyro.h
    Drivers/BSP/Components/Common/idd.h
    Drivers/BSP/Components/Common/io.h
    Drivers/BSP/Components/Common/lcd.h
    Drivers/BSP/Components/Common/magneto.h
    Drivers/BSP/Components/Common/ts.h
    Drivers/BSP/Components/Common/tsensor.h
    Drivers/BSP/Components/exc7200/exc7200.c
    Drivers/BSP/Components/exc7200/exc7200.h
    Drivers/BSP/Components/ft5336/ft5336.c
    Drivers/BSP/Components/ft5336/ft5336.h
    Drivers/BSP/Components/ft6x06/ft6x06.c
    Drivers/BSP/Components/ft6x06/ft6x06.h
    Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.c
    Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.h
    Drivers/BSP/Components/mx25l512/mx25l512.h
    Drivers/BSP/Components/n25q128a/n25q128a.h
    Drivers/BSP/Components/n25q512a/n25q512a.h
    Drivers/BSP/Components/otm8009a/otm8009a.c
    Drivers/BSP/Components/otm8009a/otm8009a.h
    Drivers/BSP/Components/ov9655/ov9655.c
    Drivers/BSP/Components/ov9655/ov9655.h
    Drivers/BSP/Components/rk043fn48h/rk043fn48h.h
    Drivers/BSP/Components/s5k5cag/s5k5cag.c
    Drivers/BSP/Components/s5k5cag/s5k5cag.h
    Drivers/BSP/Components/st7735/st7735.c
    Drivers/BSP/Components/st7735/st7735.h
    Drivers/BSP/Components/st7789h2/st7789h2.c
    Drivers/BSP/Components/st7789h2/st7789h2.h
    Drivers/BSP/Components/stmpe811/stmpe811.c
    Drivers/BSP/Components/stmpe811/stmpe811.h
    Drivers/BSP/Components/ts3510/ts3510.c
    Drivers/BSP/Components/ts3510/ts3510.h
    Drivers/BSP/Components/wm8994/wm8994.c
    Drivers/BSP/Components/wm8994/wm8994.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.h
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c
    Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.h
    Drivers/CMSIS/Device/ST/STM32F7xx/Include/stm32f746xx.h
    Drivers/CMSIS/Device/ST/STM32F7xx/Include/stm32f7xx.h
    Drivers/CMSIS/Device/ST/STM32F7xx/Include/system_stm32f7xx.h
    Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c
    Drivers/CMSIS/Include/arm_common_tables.h
    Drivers/CMSIS/Include/arm_const_structs.h
    Drivers/CMSIS/Include/arm_math.h
    Drivers/CMSIS/Include/cmsis_armcc.h
    Drivers/CMSIS/Include/cmsis_armcc_V6.h
    Drivers/CMSIS/Include/cmsis_gcc.h
    Drivers/CMSIS/Include/core_cm7.h
    Drivers/CMSIS/Include/core_cmFunc.h
    Drivers/CMSIS/Include/core_cmInstr.h
    Drivers/CMSIS/Include/core_cmSimd.h
    Drivers/CMSIS/Include/core_sc000.h
    Drivers/CMSIS/Include/core_sc300.h
    Drivers/CMSIS/RTOS/Template/cmsis_os.h
    Drivers/STM32F7xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h
    Drivers/STM32F7xx_HAL_Driver/Inc/Legacy/stm32f7xx_hal_can_legacy.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32_assert_template.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_adc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_adc_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_can.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_cec.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_conf_template.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_cortex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_crc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_crc_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_cryp.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_cryp_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dac.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dac_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dcmi.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dcmi_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_def.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dfsdm.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dma.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dma2d.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dma_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_dsi.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_eth.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_flash.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_flash_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_gpio.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_gpio_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_hash.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_hash_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_hcd.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_i2c.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_i2c_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_i2s.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_irda.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_irda_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_iwdg.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_jpeg.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_lptim.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_ltdc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_ltdc_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_mdios.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_mmc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_nand.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_nor.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_pcd.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_pcd_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_pwr.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_pwr_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_qspi.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_rcc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_rcc_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_rng.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_rtc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_rtc_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_sai.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_sai_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_sd.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_sdram.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_smartcard.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_smartcard_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_smbus.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_spdifrx.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_spi.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_sram.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_tim.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_tim_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_uart.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_uart_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_usart.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_usart_ex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_hal_wwdg.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_adc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_bus.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_cortex.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_crc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_dac.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_dma.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_dma2d.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_exti.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_fmc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_gpio.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_i2c.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_iwdg.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_lptim.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_pwr.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_rcc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_rng.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_rtc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_sdmmc.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_spi.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_system.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_tim.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_usart.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_usb.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_utils.h
    Drivers/STM32F7xx_HAL_Driver/Inc/stm32f7xx_ll_wwdg.h
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cec.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cryp.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cryp_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dfsdm.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_eth.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hash.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hash_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hcd.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2s.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_irda.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_jpeg.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_lptim.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mdios.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mmc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_msp_template.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_nand.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_nor.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rng.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smartcard.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smartcard_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smbus.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spdifrx.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sram.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_timebase_rtc_alarm_template.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_timebase_rtc_wakeup_template.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_timebase_tim_template.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_usart.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_wwdg.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_adc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_crc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dac.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dma.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dma2d.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_exti.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_gpio.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_i2c.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_lptim.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_pwr.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rcc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rng.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rtc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_spi.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_tim.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usart.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c
    Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_utils.c
    Inc/ansi.h
    Inc/bsp_driver_sd.h
    Inc/dbgu.h
    Inc/ethernetif.h
    Inc/fatfs.h
    Inc/fatfs_platform.h
    Inc/ffconf.h
    Inc/FreeRTOSConfig.h
    Inc/lwip.h
    Inc/lwipopts.h
    Inc/main.h
    Inc/sd_diskio.h
    Inc/stm32f7_diskio_dma_rtos.h
    Inc/stm32f7xx_hal_conf.h
    Inc/stm32f7xx_it.h
    Inc/term_io.h
    Inc/usb_host.h
    Inc/usbh_conf.h
    Inc/usbh_diskio.h
    Inc/usbh_platform.h
    Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc/usbh_msc.h
    Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc/usbh_msc_bot.h
    Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc/usbh_msc_scsi.h
    Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c
    Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c
    Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c
    Middlewares/ST/STM32_USB_Host_Library/Core/Inc/usbh_conf_template.h
    Middlewares/ST/STM32_USB_Host_Library/Core/Inc/usbh_core.h
    Middlewares/ST/STM32_USB_Host_Library/Core/Inc/usbh_ctlreq.h
    Middlewares/ST/STM32_USB_Host_Library/Core/Inc/usbh_def.h
    Middlewares/ST/STM32_USB_Host_Library/Core/Inc/usbh_ioreq.h
    Middlewares/ST/STM32_USB_Host_Library/Core/Inc/usbh_pipes.h
    Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_conf_template.c
    Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c
    Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c
    Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c
    Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c
    Middlewares/Third_Party/FatFs/src/option/cc932.c
    Middlewares/Third_Party/FatFs/src/option/cc936.c
    Middlewares/Third_Party/FatFs/src/option/cc949.c
    Middlewares/Third_Party/FatFs/src/option/cc950.c
    Middlewares/Third_Party/FatFs/src/option/ccsbcs.c
    Middlewares/Third_Party/FatFs/src/option/syscall.c
    Middlewares/Third_Party/FatFs/src/option/unicode.c
    Middlewares/Third_Party/FatFs/src/diskio.c
    Middlewares/Third_Party/FatFs/src/diskio.h
    Middlewares/Third_Party/FatFs/src/ff.c
    Middlewares/Third_Party/FatFs/src/ff.h
    Middlewares/Third_Party/FatFs/src/ff_gen_drv.c
    Middlewares/Third_Party/FatFs/src/ff_gen_drv.h
    Middlewares/Third_Party/FatFs/src/ffconf_template.h
    Middlewares/Third_Party/FatFs/src/integer.h
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
    Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.h
    Middlewares/Third_Party/FreeRTOS/Source/include/croutine.h
    Middlewares/Third_Party/FreeRTOS/Source/include/deprecated_definitions.h
    Middlewares/Third_Party/FreeRTOS/Source/include/event_groups.h
    Middlewares/Third_Party/FreeRTOS/Source/include/FreeRTOS.h
    Middlewares/Third_Party/FreeRTOS/Source/include/FreeRTOSConfig_template.h
    Middlewares/Third_Party/FreeRTOS/Source/include/list.h
    Middlewares/Third_Party/FreeRTOS/Source/include/mpu_prototypes.h
    Middlewares/Third_Party/FreeRTOS/Source/include/mpu_wrappers.h
    Middlewares/Third_Party/FreeRTOS/Source/include/portable.h
    Middlewares/Third_Party/FreeRTOS/Source/include/projdefs.h
    Middlewares/Third_Party/FreeRTOS/Source/include/queue.h
    Middlewares/Third_Party/FreeRTOS/Source/include/semphr.h
    Middlewares/Third_Party/FreeRTOS/Source/include/StackMacros.h
    Middlewares/Third_Party/FreeRTOS/Source/include/task.h
    Middlewares/Third_Party/FreeRTOS/Source/include/timers.h
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/portmacro.h
    Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_1.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_2.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_3.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
    Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_5.c
    Middlewares/Third_Party/FreeRTOS/Source/croutine.c
    Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
    Middlewares/Third_Party/FreeRTOS/Source/list.c
    Middlewares/Third_Party/FreeRTOS/Source/queue.c
    Middlewares/Third_Party/FreeRTOS/Source/tasks.c
    Middlewares/Third_Party/FreeRTOS/Source/timers.c
    Middlewares/Third_Party/LwIP/src/api/api_lib.c
    Middlewares/Third_Party/LwIP/src/api/api_msg.c
    Middlewares/Third_Party/LwIP/src/api/err.c
    Middlewares/Third_Party/LwIP/src/api/netbuf.c
    Middlewares/Third_Party/LwIP/src/api/netdb.c
    Middlewares/Third_Party/LwIP/src/api/netifapi.c
    Middlewares/Third_Party/LwIP/src/api/sockets.c
    Middlewares/Third_Party/LwIP/src/api/tcpip.c
    Middlewares/Third_Party/LwIP/src/apps/mqtt/mqtt.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/dhcp6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ethip6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/icmp6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/inet6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ip6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_addr.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_frag.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/mld6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/nd6.c
    Middlewares/Third_Party/LwIP/src/core/def.c
    Middlewares/Third_Party/LwIP/src/core/dns.c
    Middlewares/Third_Party/LwIP/src/core/inet_chksum.c
    Middlewares/Third_Party/LwIP/src/core/init.c
    Middlewares/Third_Party/LwIP/src/core/ip.c
    Middlewares/Third_Party/LwIP/src/core/mem.c
    Middlewares/Third_Party/LwIP/src/core/memp.c
    Middlewares/Third_Party/LwIP/src/core/netif.c
    Middlewares/Third_Party/LwIP/src/core/pbuf.c
    Middlewares/Third_Party/LwIP/src/core/raw.c
    Middlewares/Third_Party/LwIP/src/core/stats.c
    Middlewares/Third_Party/LwIP/src/core/sys.c
    Middlewares/Third_Party/LwIP/src/core/tcp.c
    Middlewares/Third_Party/LwIP/src/core/tcp_in.c
    Middlewares/Third_Party/LwIP/src/core/tcp_out.c
    Middlewares/Third_Party/LwIP/src/core/timeouts.c
    Middlewares/Third_Party/LwIP/src/core/udp.c
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/fs.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/httpd.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/httpd_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/lwiperf.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/mdns.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/mdns_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/mdns_priv.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/mqtt.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/mqtt_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/netbiosns.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/netbiosns_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_core.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_mib2.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_scalar.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_table.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_threadsync.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmpv3.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/sntp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/sntp_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/tftp_opts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/apps/tftp_server.h
    Middlewares/Third_Party/LwIP/src/include/lwip/priv/api_msg.h
    Middlewares/Third_Party/LwIP/src/include/lwip/priv/memp_priv.h
    Middlewares/Third_Party/LwIP/src/include/lwip/priv/memp_std.h
    Middlewares/Third_Party/LwIP/src/include/lwip/priv/nd6_priv.h
    Middlewares/Third_Party/LwIP/src/include/lwip/priv/tcp_priv.h
    Middlewares/Third_Party/LwIP/src/include/lwip/priv/tcpip_priv.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/autoip.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/dhcp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/dns.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/etharp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/ethernet.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/icmp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/icmp6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/igmp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/ip.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/ip4.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/ip6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/mld6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/nd6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/tcp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/prot/udp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/api.h
    Middlewares/Third_Party/LwIP/src/include/lwip/arch.h
    Middlewares/Third_Party/LwIP/src/include/lwip/autoip.h
    Middlewares/Third_Party/LwIP/src/include/lwip/debug.h
    Middlewares/Third_Party/LwIP/src/include/lwip/def.h
    Middlewares/Third_Party/LwIP/src/include/lwip/dhcp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/dhcp6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/dns.h
    Middlewares/Third_Party/LwIP/src/include/lwip/err.h
    Middlewares/Third_Party/LwIP/src/include/lwip/errno.h
    Middlewares/Third_Party/LwIP/src/include/lwip/etharp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ethip6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/icmp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/icmp6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/igmp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/inet.h
    Middlewares/Third_Party/LwIP/src/include/lwip/inet_chksum.h
    Middlewares/Third_Party/LwIP/src/include/lwip/init.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip4.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip4_addr.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip4_frag.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip6_addr.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip6_frag.h
    Middlewares/Third_Party/LwIP/src/include/lwip/ip_addr.h
    Middlewares/Third_Party/LwIP/src/include/lwip/mem.h
    Middlewares/Third_Party/LwIP/src/include/lwip/memp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/mld6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/nd6.h
    Middlewares/Third_Party/LwIP/src/include/lwip/netbuf.h
    Middlewares/Third_Party/LwIP/src/include/lwip/netdb.h
    Middlewares/Third_Party/LwIP/src/include/lwip/netif.h
    Middlewares/Third_Party/LwIP/src/include/lwip/netifapi.h
    Middlewares/Third_Party/LwIP/src/include/lwip/opt.h
    Middlewares/Third_Party/LwIP/src/include/lwip/pbuf.h
    Middlewares/Third_Party/LwIP/src/include/lwip/raw.h
    Middlewares/Third_Party/LwIP/src/include/lwip/sio.h
    Middlewares/Third_Party/LwIP/src/include/lwip/snmp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/sockets.h
    Middlewares/Third_Party/LwIP/src/include/lwip/stats.h
    Middlewares/Third_Party/LwIP/src/include/lwip/sys.h
    Middlewares/Third_Party/LwIP/src/include/lwip/tcp.h
    Middlewares/Third_Party/LwIP/src/include/lwip/tcpip.h
    Middlewares/Third_Party/LwIP/src/include/lwip/timeouts.h
    Middlewares/Third_Party/LwIP/src/include/lwip/udp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ccp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/chap-md5.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/chap-new.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/chap_ms.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/eap.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ecp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/eui64.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/fsm.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ipcp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ipv6cp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/lcp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/magic.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/mppe.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ppp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ppp_impl.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/ppp_opts.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppapi.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppcrypt.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppdebug.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppoe.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppol2tp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppos.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/upap.h
    Middlewares/Third_Party/LwIP/src/include/netif/ppp/vj.h
    Middlewares/Third_Party/LwIP/src/include/netif/etharp.h
    Middlewares/Third_Party/LwIP/src/include/netif/ethernet.h
    Middlewares/Third_Party/LwIP/src/include/netif/lowpan6.h
    Middlewares/Third_Party/LwIP/src/include/netif/lowpan6_opts.h
    Middlewares/Third_Party/LwIP/src/include/netif/slipif.h
    Middlewares/Third_Party/LwIP/src/include/posix/sys/socket.h
    Middlewares/Third_Party/LwIP/src/include/posix/errno.h
    Middlewares/Third_Party/LwIP/src/include/posix/netdb.h
    Middlewares/Third_Party/LwIP/src/netif/ppp/auth.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ccp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/chap-md5.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/chap-new.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/chap_ms.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/demand.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/eap.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ecp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/eui64.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/fsm.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ipcp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ipv6cp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/lcp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/magic.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/mppe.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/multilink.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ppp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppapi.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppcrypt.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppoe.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppol2tp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppos.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/upap.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/utils.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/vj.c
    Middlewares/Third_Party/LwIP/src/netif/ethernet.c
    Middlewares/Third_Party/LwIP/src/netif/ethernetif_template.c
    Middlewares/Third_Party/LwIP/src/netif/lowpan6.c
    Middlewares/Third_Party/LwIP/src/netif/slipif.c
    Middlewares/Third_Party/LwIP/system/arch/bpstruct.h
    Middlewares/Third_Party/LwIP/system/arch/cc.h
    Middlewares/Third_Party/LwIP/system/arch/cpu.h
    Middlewares/Third_Party/LwIP/system/arch/epstruct.h
    Middlewares/Third_Party/LwIP/system/arch/init.h
    Middlewares/Third_Party/LwIP/system/arch/lib.h
    Middlewares/Third_Party/LwIP/system/arch/perf.h
    Middlewares/Third_Party/LwIP/system/arch/sys_arch.h
    Middlewares/Third_Party/LwIP/system/OS/sys_arch.c
    Src/bsp_driver_sd.c
    Src/dbgu.c
    Src/ethernetif.c
    Src/fatfs.c
    Src/fatfs_platform.c
    Src/freertos.c
    Src/lwip.c
    Src/sd_diskio.c
    Src/sd_diskio_dma_rtos.c
    Src/stm32f7_board_sd.c
    Src/stm32f7xx_hal_msp.c
    Src/stm32f7xx_hal_timebase_TIM.c
    Src/stm32f7xx_it.c
    Src/syscalls.c
    Src/system_stm32f7xx.c
    Src/term_io.c
    Src/usb_host.c
    Src/usbh_conf.c
    Src/usbh_diskio.c
    Src/usbh_platform.c
    Utilities/CPU/cpu_utils.c
    Utilities/CPU/cpu_utils.h
    Utilities/Fonts/font12.c
    Utilities/Fonts/font16.c
    Utilities/Fonts/font20.c
    Utilities/Fonts/font24.c
    Utilities/Fonts/font8.c
    Utilities/Fonts/fonts.h
    Utilities/Log/lcd_log.c
    Utilities/Log/lcd_log.h
    Utilities/Log/lcd_log_conf_template.h
    main.c Modules/gui.c Modules/gui.h Modules/controls.c Modules/controls.h Modules/audio_loader.c Modules/audio_loader.h Modules/gui_colors.h main.h Modules/audio_player.c Modules/audio_player.h Modules/effect_converter.c Modules/effect_converter.h)

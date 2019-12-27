##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [2.30.0] date: [Thu Oct 04 20:15:23 CEST 2018]
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
# ------------------------------------------------

######################################
# target
######################################
TARGET = f7project


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
main.c \
Src/bsp_driver_sd.c \
Src/sd_diskio.c \
Src/fatfs.c \
Src/fatfs_platform.c \
Src/usbh_diskio.c \
Src/freertos.c \
Src/lwip.c \
Src/ethernetif.c \
Src/syscalls.c \
Src/usb_host.c \
Src/usbh_conf.c \
Src/usbh_platform.c \
Src/stm32f7xx_it.c \
Src/stm32f7xx_hal_msp.c \
Src/stm32f7xx_hal_timebase_TIM.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_eth.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hcd.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spdifrx.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
Src/system_stm32f7xx.c \
Middlewares/Third_Party/FatFs/src/option/syscall.c \
Middlewares/Third_Party/FatFs/src/option/ccsbcs.c \
Middlewares/Third_Party/FatFs/src/ff.c \
Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
Middlewares/Third_Party/FatFs/src/diskio.c \
Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c \
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c \
Middlewares/Third_Party/FreeRTOS/Source/queue.c \
Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
Middlewares/Third_Party/FreeRTOS/Source/timers.c \
Middlewares/Third_Party/FreeRTOS/Source/list.c \
Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/auth.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/ccp.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/chap_ms.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/chap-md5.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/chap-new.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/demand.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/eap.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/eui64.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/fsm.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/ipcp.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/ipv6cp.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/lcp.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/magic.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/mppe.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/multilink.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/ppp.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/pppapi.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/pppcrypt.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/pppoe.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/pppol2tp.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/pppos.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/upap.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/utils.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/vj.c \
Middlewares/Third_Party/LwIP/src/netif/ethernet.c \
Middlewares/Third_Party/LwIP/src/netif/slipif.c \
Middlewares/Third_Party/LwIP/src/netif/lowpan6.c \
Middlewares/Third_Party/LwIP/src/netif/ppp/ecp.c \
Middlewares/Third_Party/LwIP/src/api/err.c \
Middlewares/Third_Party/LwIP/src/api/netbuf.c \
Middlewares/Third_Party/LwIP/src/api/sockets.c \
Middlewares/Third_Party/LwIP/src/api/tcpip.c \
Middlewares/Third_Party/LwIP/src/api/api_lib.c \
Middlewares/Third_Party/LwIP/src/api/api_msg.c \
Middlewares/Third_Party/LwIP/src/api/netdb.c \
Middlewares/Third_Party/LwIP/src/api/netifapi.c \
Middlewares/Third_Party/LwIP/src/core/inet_chksum.c \
Middlewares/Third_Party/LwIP/src/core/ip.c \
Middlewares/Third_Party/LwIP/src/core/mem.c \
Middlewares/Third_Party/LwIP/src/core/def.c \
Middlewares/Third_Party/LwIP/src/core/timeouts.c \
Middlewares/Third_Party/LwIP/src/core/init.c \
Middlewares/Third_Party/LwIP/src/core/tcp_in.c \
Middlewares/Third_Party/LwIP/src/core/pbuf.c \
Middlewares/Third_Party/LwIP/src/core/udp.c \
Middlewares/Third_Party/LwIP/src/core/tcp.c \
Middlewares/Third_Party/LwIP/src/core/tcp_out.c \
Middlewares/Third_Party/LwIP/src/core/stats.c \
Middlewares/Third_Party/LwIP/src/core/raw.c \
Middlewares/Third_Party/LwIP/src/core/memp.c \
Middlewares/Third_Party/LwIP/src/core/netif.c \
Middlewares/Third_Party/LwIP/src/core/dns.c \
Middlewares/Third_Party/LwIP/src/core/sys.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c \
Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/ip6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/ethip6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_addr.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/nd6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/mld6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/inet6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/icmp6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/dhcp6.c \
Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_frag.c \
Middlewares/Third_Party/LwIP/system/OS/sys_arch.c \
Middlewares/Third_Party/LwIP/src/apps/mqtt/mqtt.c \
Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c \
Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c \
Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c \
Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c \
Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c \
Modules/audio_loader.c \
Modules/audio_player.c \
Modules/effect_converter.c \
Modules/controls.c \
Modules/gui.c


PROJECT_SRC = \
Src/dbgu.c \
Src/term_io.c \
Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c \
Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c \
Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c \
Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c \
Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c \
Drivers/BSP/Components/wm8994/wm8994.c \
Drivers/BSP/Components/ft5336/ft5336.c

PROJECT_SRC += Src/sd_diskio_dma_rtos.c
PROJECT_SRC += Src/stm32f7_board_sd.c


C_SOURCES += $(PROJECT_SRC)

# ASM sources
ASM_SOURCES =  \
startup_stm32f746xx.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m7

# fpu
FPU = -mfpu=fpv5-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS =

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F746xx


# AS includes
AS_INCLUDES =  \
-I/Inc

# C includes
C_INCLUDES =  \
-IInc \
-IMiddlewares/Third_Party/LwIP/src/include \
-IMiddlewares/Third_Party/LwIP/system \
-IDrivers/STM32F7xx_HAL_Driver/Inc \
-IDrivers/BSP/STM32746G-Discovery \
-IDrivers/BSP/Components \
-I. \
-IDrivers/STM32F7xx_HAL_Driver/Inc/Legacy \
-IMiddlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 \
-IMiddlewares/Third_Party/LwIP/src/include/netif/ppp \
-IMiddlewares/ST/STM32_USB_Host_Library/Core/Inc \
-IMiddlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc \
-IDrivers/CMSIS/Device/ST/STM32F7xx/Include \
-IMiddlewares/Third_Party/FatFs/src \
-IMiddlewares/Third_Party/FreeRTOS/Source/include \
-IMiddlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS \
-IMiddlewares/Third_Party/LwIP/src/include/lwip \
-IMiddlewares/Third_Party/LwIP/src/include/lwip/apps \
-IMiddlewares/Third_Party/LwIP/src/include/lwip/priv \
-IMiddlewares/Third_Party/LwIP/src/include/lwip/prot \
-IMiddlewares/Third_Party/LwIP/src/include/netif \
-IMiddlewares/Third_Party/LwIP/src/include/posix \
-IMiddlewares/Third_Party/LwIP/src/include/posix/sys \
-IMiddlewares/Third_Party/LwIP/system/arch \
-IDrivers/CMSIS/Include \
-IMiddlewares/ST/STM32_Audio/Addons/BAM/Inc \
-IMiddlewares/ST/STM32_Audio/Addons/GREQ/Inc \
-IMiddlewares/ST/STM32_Audio/Addons/SRC441/Inc \
-IMiddlewares/ST/STM32_Audio/Addons/SRC236/Inc \
-IMiddlewares/ST/STM32_Audio/Addons/Common/Inc

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F746NGHx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
STATIC_LIBS = Middlewares/ST/STM32_Audio/Addons/BAM/Lib/BAM_32b_CM7_GCC.a \
			  Middlewares/ST/STM32_Audio/Addons/GREQ/Lib/GrEq_32b_CM7_GCC.a \
			  Middlewares/ST/STM32_Audio/Addons/SRC236/Lib/SRC236_32b_CM7_GCC.a \
			  Middlewares/ST/STM32_Audio/Addons/SRC441/Lib/SRC441_32b_CM7_GCC.a
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections $(STATIC_LIBS)

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)

program_linux:
	openocd -f "board/stm32f7discovery.cfg" -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

program:
	openocd -f "board/stm32f7discovery.cfg" -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"



#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***

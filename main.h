//
// Created by olliekrk on 02.11.2019.
//

#ifndef EMBEDDED_PLAYER_MAIN_H
#define EMBEDDED_PLAYER_MAIN_H

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "fatfs.h"
#include "lwip.h"
#include "usb_host.h"

#include  <errno.h>
#include  <sys/unistd.h>

#include "stm32746g_discovery_lcd.h"
#include "Utilities/Fonts/fonts.h"
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_audio.h"
#include "term_io.h"
#include "dbgu.h"
#include "ansi.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/apps/fs.h"
#include "lwip/dhcp.h"
#include "lwip/tcpip.h"
#include "lwip/netdb.h"
#include "lwip/sockets.h"

#include "lwip.h"

#include "wm8994/wm8994.h"

/* Modules imports */
#include "Modules/gui.h"
#include "Modules/controls.h"
#include "Modules/audio_loader.h"
#include "Modules/audio_player.h"

ADC_HandleTypeDef hadc3;

CRC_HandleTypeDef hcrc;

DCMI_HandleTypeDef hdcmi;

DMA2D_HandleTypeDef hdma2d;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c3;

LTDC_HandleTypeDef hltdc;

QSPI_HandleTypeDef hqspi;

RTC_HandleTypeDef hrtc;

SAI_HandleTypeDef hsai_BlockA2;
SAI_HandleTypeDef hsai_BlockB2;

SD_HandleTypeDef hsd1;

SPDIFRX_HandleTypeDef hspdif;

SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim8;
TIM_HandleTypeDef htim12;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart6;

SDRAM_HandleTypeDef hsdram1;

osThreadId defaultTaskHandle;
osThreadId touchscreenTaskHandle;
osThreadId guiTaskHandle;
osThreadId audioPlayerTaskHandle;

void SystemClock_Config(void);

static void MX_GPIO_Init(void);

static void MX_ADC3_Init(void);

static void MX_CRC_Init(void);

static void MX_DCMI_Init(void);

static void MX_DMA2D_Init(void);

static void MX_FMC_Init(void);

static void MX_I2C1_Init(void);

static void MX_I2C3_Init(void);

static void MX_LTDC_Init(void);

static void MX_QUADSPI_Init(void);

static void MX_RTC_Init(void);

static void MX_SAI2_Init(void);

static void MX_SDMMC1_SD_Init(void);

static void MX_SPDIFRX_Init(void);

static void MX_SPI2_Init(void);

static void MX_TIM1_Init(void);

static void MX_TIM2_Init(void);

static void MX_TIM3_Init(void);

static void MX_TIM5_Init(void);

static void MX_TIM8_Init(void);

static void MX_TIM12_Init(void);

static void MX_USART1_UART_Init(void);

static void MX_USART6_UART_Init(void);

static void MX_TIM7_Init(void);

/* TASKS */

void StartDefaultTask(void const *argument);

void StartAudioPlayerTask(void const *argument);

void StartTouchscreenTask(void const *argument);

void StartGuiTask(void const *argument);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);


#define LCD_X_SIZE      RK043FN48H_WIDTH
#define LCD_Y_SIZE      RK043FN48H_HEIGHT

#define PRINTF_USES_HAL_TX    0

#define ALL_THREADS_STACK_SIZE 4096

typedef enum BufferState {
    BUFFER_OFFSET_NONE = 0,
    BUFFER_OFFSET_HALF,
    BUFFER_OFFSET_FULL,
} BufferState;

extern ApplicationTypeDef Appli_state;
static uint8_t player_state = 0;
static uint8_t buf_offs = BUFFER_OFFSET_NONE;
//static uint32_t fpos = 0;

static uint32_t lcd_image_fg[LCD_Y_SIZE][LCD_X_SIZE] __attribute__((section(".sdram"))) __attribute__((unused));
static uint32_t lcd_image_bg[LCD_Y_SIZE][LCD_X_SIZE] __attribute__((section(".sdram"))) __attribute__((unused));

static TS_StateTypeDef TS_State;

#endif //EMBEDDED_PLAYER_MAIN_H

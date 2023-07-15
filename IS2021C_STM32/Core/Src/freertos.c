/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Get_Shot */
osThreadId_t Get_ShotHandle;
const osThreadAttr_t Get_Shot_attributes = {
  .name = "Get_Shot",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal4,
};
/* Definitions for Time_Out */
osThreadId_t Time_OutHandle;
const osThreadAttr_t Time_Out_attributes = {
  .name = "Time_Out",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Inform_UARTHMI */
osThreadId_t Inform_UARTHMIHandle;
const osThreadAttr_t Inform_UARTHMI_attributes = {
  .name = "Inform_UARTHMI",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Compute_Point */
osThreadId_t Compute_PointHandle;
const osThreadAttr_t Compute_Point_attributes = {
  .name = "Compute_Point",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityNormal3,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void Get_Shot_Func(void *argument);
void Time_Out_No_Shot_Func(void *argument);
void Inform_UARTHMI_Func(void *argument);
void Compute_Shot_Point_Func(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of Get_Shot */
  Get_ShotHandle = osThreadNew(Get_Shot_Func, NULL, &Get_Shot_attributes);

  /* creation of Time_Out */
  Time_OutHandle = osThreadNew(Time_Out_No_Shot_Func, NULL, &Time_Out_attributes);

  /* creation of Inform_UARTHMI */
  Inform_UARTHMIHandle = osThreadNew(Inform_UARTHMI_Func, NULL, &Inform_UARTHMI_attributes);

  /* creation of Compute_Point */
  Compute_PointHandle = osThreadNew(Compute_Shot_Point_Func, NULL, &Compute_Point_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Get_Shot_Func */
/**
* @brief Function implementing the Get_Shot thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Get_Shot_Func */
void Get_Shot_Func(void *argument)
{
  /* USER CODE BEGIN Get_Shot_Func */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Get_Shot_Func */
}

/* USER CODE BEGIN Header_Time_Out_No_Shot_Func */
/**
* @brief Function implementing the Time_Out_No_Sho thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Time_Out_No_Shot_Func */
void Time_Out_No_Shot_Func(void *argument)
{
  /* USER CODE BEGIN Time_Out_No_Shot_Func */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Time_Out_No_Shot_Func */
}

/* USER CODE BEGIN Header_Inform_UARTHMI_Func */
/**
* @brief Function implementing the Inform_UARTHMI thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Inform_UARTHMI_Func */
void Inform_UARTHMI_Func(void *argument)
{
  /* USER CODE BEGIN Inform_UARTHMI_Func */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Inform_UARTHMI_Func */
}

/* USER CODE BEGIN Header_Compute_Shot_Point_Func */
/**
* @brief Function implementing the Compute_Shot_Po thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Compute_Shot_Point_Func */
void Compute_Shot_Point_Func(void *argument)
{
  /* USER CODE BEGIN Compute_Shot_Point_Func */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Compute_Shot_Point_Func */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */


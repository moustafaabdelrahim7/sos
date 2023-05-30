/*
 * sos.h
 *
 * Created: 27/05/2023 10:56:16 
 *  Author: Moustafa Abdelrahim
 */ 


#ifndef SOS_H_
#define SOS_H_
/****************************************************************************Macros*****************************************************************************/
#define sos_task_arr_Max_Length		10


/****************************************************************************Enums & Structs*********************************************************************/
typedef enum {
	sos_system_status_Success_operation=0,
	sos_system_status_failed_operation
	
}enu_sos_system_status_t;


typedef enum {
	sos_status_Running=0,
	sos_status_stopped,
	sos_status_idle
	
}enu_sos_status_t;

typedef struct  {
	uint8_t u8_task_id;
	uint8_t u8_task_priority;
	uint16_t u16_task_periodicity;
	void (*pfTask)(void);
}str_sos_task_config_t;


/*****************DataBase***********/
str_sos_task_config_t*str_sos_task_arr[sos_task_arr_Max_Length];


/***************************************************************Prototypes***************************************************************************************/

enu_sos_status_t sos_Init(void);

enu_sos_status_t sos_DeInit(void);

enu_sos_status_t sos_Create_Task(str_sos_task_config_t*SPTR_str_sos_task_config);

enu_sos_status_t sos_Delete_Task(uint8_t u8_task_id);

enu_sos_status_t sos_Modify_Task(uint8_t u8_task_id,str_sos_task_config_t*SPTR_str_sos_task_config);

enu_sos_status_t sos_Run(void);

enu_sos_status_t sos_Disable(void);

#endif /* SOS_H_ */
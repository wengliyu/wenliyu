//��48�е��������һ�д���

//��ֵ��Ϊ10.

uint16_t duty_num = 10;
//��93��������ӣ�

//���룺

HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
//��98���������

//main�����д���

while (1) 
{ /* USER CODE END WHILE */ /* USER CODE BEGIN 3 */ 
HAL_Delay(50); duty_num = duty_num + 10; 
if(duty_num > 500) 
{ duty_num = 0; } 
__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,duty_num); 
} 


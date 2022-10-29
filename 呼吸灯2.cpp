//在48行的下面添加一行代码

//初值设为10.

uint16_t duty_num = 10;
//在93行下面添加：

//代码：

HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
//在98行下面添加

//main函数中代码

while (1) 
{ /* USER CODE END WHILE */ /* USER CODE BEGIN 3 */ 
HAL_Delay(50); duty_num = duty_num + 10; 
if(duty_num > 500) 
{ duty_num = 0; } 
__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,duty_num); 
} 


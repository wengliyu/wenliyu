//位置97行下一行：
HAL_TIM_Base_Start_IT(&htim2);
//位置162行下一行：

//代码如下：

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)

{ static uint32_t time_cnt =0;

if(htim->Instance == TIM2)

{? ?if(++time_cnt >= 100)

? { time_cnt =0; HAL_GPIO_TogglePin(D1_GPIO_Port,D1_Pin);

? }

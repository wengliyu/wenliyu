//λ��97����һ�У�
HAL_TIM_Base_Start_IT(&htim2);
//λ��162����һ�У�

//�������£�

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)

{ static uint32_t time_cnt =0;

if(htim->Instance == TIM2)

{? ?if(++time_cnt >= 100)

? { time_cnt =0; HAL_GPIO_TogglePin(D1_GPIO_Port,D1_Pin);

? }

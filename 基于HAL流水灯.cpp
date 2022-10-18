SystemClock_Config();//œµÕ≥ ±÷”≥ı ºªØ
  MX_GPIO_Init();//gpio≥ı ºªØ
  while (1)
  {		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);//PA7¡¡µ∆
		HAL_Delay(500);//—” ±0.5s
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);//PA7œ®µ∆
		HAL_Delay(500);//—” ±0.5s
		
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET);//PB9¡¡µ∆
		HAL_Delay(500);//—” ±0.5s
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);//PB9œ®µ∆
		HAL_Delay(500);//—” ±0.5s
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_RESET);//PC15¡¡µ∆
		HAL_Delay(500);//—” ±0.5s
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_SET);//PC15œ®µ∆
		HAL_Delay(500);//—” ±0.5s
		
  } 


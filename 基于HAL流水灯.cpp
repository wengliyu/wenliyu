SystemClock_Config();//ϵͳʱ�ӳ�ʼ��
  MX_GPIO_Init();//gpio��ʼ��
  while (1)
  {		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);//PA7����
		HAL_Delay(500);//��ʱ0.5s
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);//PA7Ϩ��
		HAL_Delay(500);//��ʱ0.5s
		
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET);//PB9����
		HAL_Delay(500);//��ʱ0.5s
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);//PB9Ϩ��
		HAL_Delay(500);//��ʱ0.5s
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_RESET);//PC15����
		HAL_Delay(500);//��ʱ0.5s
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_SET);//PC15Ϩ��
		HAL_Delay(500);//��ʱ0.5s
		
  } 


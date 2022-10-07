
#define GPIOB_BASE 0x40010C00
#define GPIOC_BASE 0x40011000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR (*(unsigned int *)0x40021018)

#define GPIOB_CRH (*(unsigned int *)0x40010C04)
#define GPIOC_CRH (*(unsigned int *)0x40011004)
#define GPIOA_CRL (*(unsigned int *)0x40010800)

#define GPIOB_ODR (*(unsigned int *)0x40010C0C)
#define GPIOC_ODR (*(unsigned int *)0x4001100C)
#define GPIOA_ODR (*(unsigned int *)0x4001080C)
	


void SystemInit(void);
void Delay_ms(volatile  unsigned  int);
void A_LED_LIGHT(void);
void B_LED_LIGHT(void);
void C_LED_LIGHT(void);
void Delay_ms( volatile  unsigned  int  t)
{
     unsigned  int  i;
     while(t--)
         for (i=0;i<800;i++);
}

void A_LED_LIGHT(){
	GPIOA_ODR=0x0<<4;		//PA4�͵�ƽ
	GPIOB_ODR=0x1<<9;		//PB9�ߵ�ƽ
	GPIOC_ODR=0x1<<15;		//PC15�ߵ�ƽ
}
void B_LED_LIGHT(){
	GPIOA_ODR=0x1<<4;		//PA4�ߵ�ƽ
	GPIOB_ODR=0x0<<9;		//PB9�͵�ƽ
	GPIOC_ODR=0x1<<15;		//PC15�ߵ�ƽ
}
void C_LED_LIGHT(){
	GPIOA_ODR=0x1<<4;		//PA4�ߵ�ƽ
	GPIOB_ODR=0x1<<9;		//PB9�ߵ�ƽ
	GPIOC_ODR=0x0<<15;		//PC15�͵�ƽ	
}

int main(){
	int j=100;
	// ����ʱ��
	RCC_APB2ENR |= (1<<3); // ���� GPIOB ʱ��
	RCC_APB2ENR |= (1<<4); // ���� GPIOC ʱ��
	RCC_APB2ENR |= (1<<2); // ���� GPIOA ʱ��
	
	
	// ���� GPIO Ϊ�������
	GPIOB_CRH&= 0xffffff0f;	//����λ ����		
	GPIOB_CRH|=0x00000020;  //PB9�������

	GPIOC_CRH &= 0x0fffffff; //����λ ����		
	GPIOC_CRH|=0x30000000;  //PC15�������


	GPIOA_CRL &= 0xfff0ffff; //����λ ����		
	GPIOA_CRL|=0x00010000; //PA4�������

	// 3��LED��ʼ��Ϊ���������ߵ�λ��
	GPIOB_ODR |= (1<<9); 
	GPIOC_ODR |= (1<<15); 
	GPIOA_ODR |= (1<<4);  
	
	while(j){
		
		B_LED_LIGHT();
		Delay_ms(1000000);

		C_LED_LIGHT();
		Delay_ms(1000000);

		A_LED_LIGHT();
		Delay_ms(1000000);
	}
	
}


void SystemInit(){
	
}


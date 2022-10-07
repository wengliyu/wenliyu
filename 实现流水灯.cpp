
void  Delay_wxc( volatile  unsigned  int  t)
{
     unsigned  int  i;
     while(t--)
         for (i=0;i<800;i++);
}
//------------------------???--------------------------
int main()
{
	int j=100;
	RCC_AP2ENR|=1<<2;			//APB2-GPIOA??????
	RCC_AP2ENR|=1<<3;			//APB2-GPIOB??????	
	RCC_AP2ENR|=1<<4;			//APB2-GPIOC??????
	//????????? RCC_APB2ENR|=1<<3|1<<4;
	GPIOA_CRL&=0x0FFFFFFF;		//??? ??	
	GPIOA_CRL|=0x20000000;		//PA7????
	GPIOA_ORD|=1<<7;			//???????
	
	GPIOB_CRH&=0xFFFFFF0F;		//??? ??	
	GPIOB_CRH|=0x00000020;		//PB9????
	GPIOB_ORD|=1<<9;			//???????
	
	GPIOC_CRH&=0x0FFFFFFF;		//??? ??
	GPIOC_CRH|=0x30000000;   	//PC15????
	GPIOC_ORD|=0x1<<15;			//???????	
	while(j)
	{	
		GPIOA_ORD=0x0<<0;		//PB0???	
		Delay_wxc(1000000);
		GPIOA_ORD=0x1<<0;		//PB0???
		Delay_wxc(1000000);
		
		GPIOB_ORD=0x0<<9;		//PB9???	
		Delay_wxc(1000000);
		GPIOB_ORD=0x1<<9;		//PB9???
		Delay_wxc(1000000);
		
		GPIOC_ORD=0x0<<15;		//PC15???	
		Delay_wxc(1000000);
		GPIOC_ORD=0x1<<15;		//PC15???
		Delay_wxc(1000000);
	}
}


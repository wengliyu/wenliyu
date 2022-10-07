    int main(void)
    {
        unsigned int *pRCC_APB2ENR = (unsigned int *)0x40021018;
        unsigned int *pGPIOB_CRH = (unsigned int *)0x40010c04;
        unsigned int *pGPIOB_ODR = (unsigned int *)0x40010c0c;
        *pRCC_APB2ENR = 0x00000008;
        *pGPIOB_CRH = 0x44444443;
        *pGPIOB_ODR = 0x00000000;
         return 0;             
    }


RCC_APB2ENR EQU 0x40021018;配置RCC寄存器,时钟,0x40021018为时钟地址

GPIOB_BASE EQU 0x40010C00
GPIOC_BASE EQU 0x40011000
GPIOA_BASE EQU 0x40010800
	
GPIOB_CRL EQU 0x40010C00
GPIOC_CRH EQU 0x40011004
GPIOA_CRL EQU 0x40010800
	
GPIOB_ODR EQU 0x40010C0C
GPIOC_ODR EQU 0x4001100C
GPIOA_ODR EQU 0x4001080C

Stack_Size EQU  0x00000400;栈的大小
	
                AREA    STACK, NOINIT, READWRITE, ALIGN=3 ;NOINIT： = NO Init，不初始化。READWRITE : 可读，可写。ALIGN =3 : 2^3 对齐，即8字节对齐。
Stack_Mem       SPACE   Stack_Size
__initial_sp




                AREA    RESET, DATA, READONLY

__Vectors       DCD     __initial_sp               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler
                    
                    
                AREA    |.text|, CODE, READONLY
                    
                THUMB
                REQUIRE8
                PRESERVE8
                    
                ENTRY
Reset_Handler 
				bl LED_Init;bl：带链接的跳转指令。当使用该指令跳转时，当前地址(PC)会自动送入LR寄存器
MainLoop        BL LED_ON_C
                BL Delay
                BL LED_OFF_C
                BL Delay
				BL LED_ON_A
                BL Delay
                BL LED_OFF_A
                BL Delay
				BL LED_ON_B
                BL Delay
                BL LED_OFF_B
                BL Delay
                
                B MainLoop;B:无条件跳转。
LED_Init;LED初始化
                PUSH {R0,R1, LR};R0,R1,LR中的值放入堆栈
                ;控制时钟
                LDR R0,=RCC_APB2ENR;LDR是把地址装载到寄存器中(比如R0)。
                ORR R0,R0,#0x1c
                LDR R1,=RCC_APB2ENR
                STR R0,[R1]
				
				
                ;初始化GPIOA_CRL
                LDR R0,=GPIOA_CRL
                BIC R0,R0,#0x0fffffff;BIC 先把立即数取反，再按位与
                LDR R1,=GPIOA_CRL
                STR R0,[R1]
				
                LDR R0,=GPIOA_CRL
                ORR R0,#0x00000001
                LDR R1,=GPIOA_CRL
                STR R0,[R1]
                ;将PA0置1
                MOV R0,#0x01
                LDR R1,=GPIOA_ORD
                STR R0,[R1]
				
				
                ;初始化GPIOB_CRL
                LDR R0,=GPIOB_CRL
                BIC R0,R0,#0x0fffffff;BIC 先把立即数取反，再按位与
                LDR R1,=GPIOB_CRL
                STR R0,[R1]
				
                LDR R0,=GPIOB_CRL
                ORR R0,#0x00000001
                LDR R1,=GPIOB_CRL
                STR R0,[R1]
                ;将PB0置1
                MOV R0,#0x01
                LDR R1,=GPIOA_ORD
                STR R0,[R1]
				
				
				 ;初始化GPIOC
                LDR R0,=GPIOC_CRH
                BIC R0,R0,#0x0fffffff
                LDR R1,=GPIOC_CRH
                STR R0,[R1]
				
                LDR R0,=GPIOC_CRH
                ORR R0,#0x01000000
                LDR R1,=GPIOC_CRH
                STR R0,[R1]
                ;将PC15置1
                MOV R0,#0x8000
                LDR R1,=GPIOC_ORD
                STR R0,[R1]
             
                POP {R0,R1,PC};将栈中之前存的R0，R1，LR的值返还给R0，R1，PC
LED_ON_A
                PUSH {R0,R1, LR}    
                
                MOV R0,#0x00
                LDR R1,=GPIOA_ORD 
                STR R0,[R1]
             
                POP {R0,R1,PC}
             
LED_OFF_A
                PUSH {R0,R1, LR}    
                
                MOV R0,#0x01
                LDR R1,=GPIOA_ORD 
                STR R0,[R1]
             
                POP {R0,R1,PC}  
LED_ON_B;亮灯
                PUSH {R0,R1, LR}    
                
                MOV R0,#0x00
                LDR R1,=GPIOB_ORD
                STR R0,[R1]
             
                POP {R0,R1,PC}
             
LED_OFF_B;熄灯
                PUSH {R0,R1, LR}    
                
                MOV R0,#0x01
                LDR R1,=GPIOB_ORD
                STR R0,[R1]
             
                POP {R0,R1,PC}  
LED_ON_C;亮灯
                PUSH {R0,R1, LR}    
                
                MOV R0,#0x00
                LDR R1,=GPIOC_ORD
                STR R0,[R1]
             
                POP {R0,R1,PC}
             
LED_OFF_C;熄灯
                PUSH {R0,R1, LR}    
                
                MOV R0,#0x0100
                LDR R1,=GPIOC_ORD
                STR R0,[R1]
             
                POP {R0,R1,PC}             
             
Delay
                PUSH {R0,R1, LR}
                
                MOVS R0,#0
                MOVS R1,#0
                MOVS R2,#0
                
DelayLoop0        
                ADDS R0,R0,#1

                CMP R0,#330
                BCC DelayLoop0
                
                MOVS R0,#0
                ADDS R1,R1,#1
                CMP R1,#330
                BCC DelayLoop0

                MOVS R0,#0
                MOVS R1,#0
                ADDS R2,R2,#1
                CMP R2,#15
                BCC DelayLoop0
                
                
                POP {R0,R1,PC}    
                NOP
				END


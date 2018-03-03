#include "stm32f10x.h"            
#include "stm32f10x_gpio.h"        
#include "stm32f10x_rcc.h"         

GPIO_InitTypeDef Initialize;
//this is the code for the line tracker using ARM_STM32F103 microcontroller wrote on Keil uvision IDE
//the black/white sensors will be connected to PA0 to PA4 (5 sensors)
//The motor drive module (L298N) will be connected to PA8 to PA13  (for their 5V tolerance)
//For now i will use a manual function for the PWM and delay untill figuring out the actual function in the library

void Initializtion()
{
	//initializing timer to pins A
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//initializing pins from PA0 to PA4 as input active low (IPU) for the sensors
	
	Initialize.GPIO_Speed = GPIO_Speed_2MHz;		 //setting freq to 2MHZ   ,     input Mode
	Initialize.GPIO_Mode = GPIO_Mode_IPU;
	
	Initialize.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &Initialize);
	
	//initializing from PA8 to PA13 for the motor drive module
	//PA8 for ENA , PA9 for ENB , PA10/PA11 for IN1/IN2
	
	Initialize.GPIO_Mode = GPIO_Mode_Out_OD; 		//the pins will be output mode
	
	Initialize.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_12;
	GPIO_Init(GPIOA, &Initialize);
	
	Initialize.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOA, &Initialize);
	
}
//delay function for 2MHZ freq
void delay(unsigned int microSec)
{
	unsigned int i , j;
	for (i=0;i<microSec;i++)
	for (j=0;j<0x2AFF;j++);		//number of commands excuted in 1 micro second
}

//manual PWM functions for PA8 , PA9
void PWMA8(unsigned int duty_cycleX1000,unsigned int period_tim)		//takes duty cycle *1000 (from 0 to 1000)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	delay(period_tim*(duty_cycleX1000/1000));
	GPIO_SetBits(GPIOA, GPIO_Pin_8);
	delay(period_tim*((1000-duty_cycleX1000)/1000));
}

void PWMA9(unsigned int duty_cycleX1000,unsigned int period_tim)		
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	delay(period_tim*(duty_cycleX1000/1000));
	GPIO_SetBits(GPIOA, GPIO_Pin_9);
	delay(period_tim*((1000-duty_cycleX1000)/1000));
}

//the motor drive function , takes the speed percent and direction , turning percent and direction
void motorDrive(unsigned int speed , bool forward_direction, unsigned int turn , bool right_direction)
{
  unsigned int speedA , speedB;   //variables to control speeds of motor A & B respectivelly
  
  
}


int main(void)
{
	
}

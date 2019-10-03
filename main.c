/*
 * Motor_test.c
 *
 * Created: 10/2/2019 12:22:14 PM
 * Author : M_Moawad
 */ 

/*#include <avr/io.h>*/
 #include "MOTOR.h"
 #include "DIO.h"
 #include "Timers.h"

void car_forward (void)
{
	motor_On(LEFT_MOTOR,FORWARD);
	motor_On(RIGHT_MOTOR,FORWARD);
}

void car_backward (void)
{
	motor_On(LEFT_MOTOR,BACKWARD);
	motor_On(RIGHT_MOTOR,BACKWARD);
}

void car_rotate_left (void)
{
	motor_Off(LEFT_MOTOR);
	motor_On(RIGHT_MOTOR,FORWARD);
}

void car_rotate_right (void)
{
	motor_On(LEFT_MOTOR,FORWARD);
	motor_Off(RIGHT_MOTOR);
}
void car_stop (void)
{
	motor_Off(RIGHT_MOTOR);
	motor_Off(LEFT_MOTOR);
}




int main(void)
{
	DIO_init();
	timer_init();
	uint8_t state = 0, duty_cycle;
	
	while (1) 
    {
		switch(state)
		{
			case 0:
				car_forward ();
				duty_cycle = 80;
				state++;
			break;
			
			case 1:
				duty_cycle = 90;
				state++;			
			break; 
			
			case 2:
				duty_cycle = 100;
				state++;
			break;
				duty_cycle = 90;
				state++;
			case 3:
				duty_cycle = 80;
				state++;
			break;
			
			default:
				duty_cycle = 0;
				car_stop();
			break;	
		}
		
		TIMER_PWM (Timer1, duty_cycle);
		Delay_ms(5000, Timer0);
  		

// 		car_forward ();
// 		TIMER_PWM (Timer1, 100);
// 		Delay_ms(5000, Timer0);
// 		car_stop();
// 		Delay_ms(5000, Timer0);
	}
}


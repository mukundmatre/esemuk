//This is the main function for executing all features in the project
#include "MKL25Z4.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "uart.h"
#include "pwm.h"
#include "rxtestled.h"
#include "logger.h"
#include "cbuff.h"
#define FRDM
//#define LOG           //compile time switch to enable LOG
//#define TXTEST        //for UART transmit test
//#define RXTEST        //for UART receive test
//#define BUFFER        //FOR BUFFER
//#define PROFILER      // FOR PROFILER
//#define PWM           // FOR PWM
void main()
{
#ifdef TXTEST
	UART0_init();
	  send_string("Transmission is successful by Mukund and Anirudh");
#endif


#ifdef RXTEST
  char c;
  __disable_irq();
  UART0_init();
  LED_in();
  __enable_irq();

  while(1)
  {

  }

#endif


#ifdef PWM
    char c;
	__disable_irq();
	UART0_init();
	LED_in();
	__enable_irq();

	while(1)
	{
      LED_ctrl(c);
	}


#endif

#ifdef LOG
    char string1[] = "Testing123,Serial Print Test, no params";
    char string2[] = "This is an integer number: ";
    float number2 = 200;
    char string3[] = "This is an integer number: ";
    float number3 = 4096;
    char string4[] = "This is an integer number: ";
    float number4 = 123456;
    char string5[] = "This is a floating point number: ";
    float number5 = 1543.321;
#ifdef FRDM
	UART0_init();
    LOG_0(string1,strlen(string1));

    send_string("\r\n");

    LOG_1(string2,number2,0);

    send_string("\r\n");

    LOG_1(string3,number3,0);

    send_string("\r\n");

    LOG_1(string4,number4,0);

    send_string("\r\n");

    LOG_1(string5,number5,3);
    delayMs(200);
#endif

#ifdef BBB
    LOG_0(string1,strlen(string1));

    LOG_1(string2,number2,3);

    LOG_1(string3,number3,3);

    LOG_1(string4,number4,3);

    LOG_1(string5,number5,3);
#endif
#endif

#ifdef BUFFER
    int i,full,empty;
    cb_t struc_ptr;
    char *buff_ptr, dout;
    mem_allocate(100);
    struc_ptr.length = 100;
    struc_ptr.buffer = buff_ptr;
    struc_ptr.head = buff_ptr;
    struc_ptr.tail = buff_ptr;
    //full = buff_full();
    //empty = buff_empty();
    char string1[] = "Testing123,Serial Print Test, no params";

      for(i=0;i< strlen(string1);i++ )
      {
        add_item(string1[i]);
      }
    UART0_init();
      for(i=0; i< strlen(string1); i++ )
      {
    	dout = remove_item();
        send_char(dout);
      }


#endif


#ifdef PROFILER

  void initialize_counter()
  {

  SIM->SCGC6 = 0x01000000;
  SIM->SOPT2 |= 0x01000000;
  TPM0->SC = 0x0;
  TPM0->MOD = 0x0000FFFF;
  TPM0->CNT = 0x0;
  TPM0->SC = 0X00000080;
  }

  void counter_start()
  {
  TPM0->CNT = 0x0;
  TPM0->SC = 0x00000008;
  }

  void counter_stop()
  {
  TPM0->SC = 0x0;
  }

  double system_clock= 0.047;
  double time_elapsed1;
  double time_elapsed2;
  double time_elapsed3;
  double time_elapsed4;
  double time_elapsed5;
  double time_elapsed6;
  double cpu_ticks;


  initialize_counter();
  counter_start();
  int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length){
   uint32_t i=0;
   uint8_t temp[100];

   if(src != NULL){
      for(i=0;i<length;i++){
         *(temp+i)=*(src+i);
       }

      for(i=0;i<length;i++){
         *(dst+i)=*(temp+i);
       }

      return 0;
   }

   else
      return 1;

  }
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed1= cpu_ticks*system_clock;


  initialize_counter();
  counter_start();
  void *memmove(void *str1, const void *str2, size_t n);
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed2= cpu_ticks*system_clock;



  initialize_counter();
  counter_start();
  int8_t my_memzero (uint8_t *src,uint32_t length){

   if(src != NULL){
       unsigned char *p;

        for(p = src; 0 < length ; ++p, --length)
           *p = 0;

         return 0;
      }

    else
    return 1;
   }
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed3= cpu_ticks*system_clock;

  initialize_counter();
  counter_start();
  void *memset(void *str,int c , size_t n);
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed4= cpu_ticks*system_clock;

  initialize_counter();
  counter_start();
  char strrev(char a[]);
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed5= cpu_ticks*system_clock;


  initialize_counter();
  counter_start();
  int8_t my_reverse(uint8_t *src, int length)
  {
   uint16_t j;

   if(src != NULL){
     int8_t temp;

     for(j=0;j<(length/2);j++){
        temp=*(src+j);
        *(src+j)=*(src+length-j-1);
        *(src+length-j-1)=temp;
      }

      return 0;
   }

   else
      return 1;

  }
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed6= cpu_ticks*system_clock;

#endif


}

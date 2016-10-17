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
      UART0_init();
      uint8_t i,j,data,full,empty,l;
      int addrem;
      l=5;
      mem_allocate(l);
      struc_ptr->length = l;
      struc_ptr->buffer = buff_ptr;
      struc_ptr->head = buff_ptr;
      struc_ptr->tail = buff_ptr;

      uint8_t string1[] = "Hey UART! This is the Circular buffer talking! But one character at a time";


      for(i=0;i<strlen(string1);++i)
      {
      	add_item(string1[i]);
        if (buff_full()==1)
        {
        	continue;
    	}

      for(j=0;j<struc_ptr->length;++j)
      {
      	send_char(remove_item());
        if (buff_empty()==1)
        {
        	break;
    	}
      }
      }
    void mem_free();
#endif


#ifdef PROFILER
//initializing profiler
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

//profiling for my_memmove
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

//profiling for library function memmove
  initialize_counter();
  counter_start();
  void *memmove(void *str1, const void *str2, size_t n);
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed2= cpu_ticks*system_clock;


//profiling for my_memzero
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

//profiling for library function memset
  initialize_counter();
  counter_start();
  void *memset(void *str,int c , size_t n);
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed4= cpu_ticks*system_clock;

//profiling for library function strrev
  initialize_counter();
  counter_start();
  char strrev(char a[]);
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed5= cpu_ticks*system_clock;

//profiling for my_reverse
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

//profiling for my_itoa
  initialize_counter();
  counter_start();
  int8_t* my_itoa(int32_t intnum, int8_t *string,  int32_t base)
  {
    int8_t index[]="0123456789ABCDEF";
    uint32_t numb;
    int i=0,j,k;
    char temp;
    //transfer to unsinged
    if(base==10&&intnum<0)//if it is a decimal negative number
    {
    numb=(uint32_t)-intnum;
    *(string+(i++))='-';
    }
    else numb=(uint32_t)intnum;
    //transfer
    do{
      *(string+(i++))=index[numb%(uint32_t)base];
      numb/=base;
    }while(numb);

    *(string+i)='\0';

    if(*string=='-')
      k=1;
    else
      k=0;


    for(j=k;j<=(i-1)/2;j++)
    {
      temp=*(string+j);
      *(string+j)=*(string+i-1+k-j);
      *(string+i-1+k-j)=temp;
    }
    return string;
  }
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed7= cpu_ticks*system_clock;

//profiling for my_atoi
  initialize_counter();
  counter_start();
  int32_t my_atoi(int8_t *str)
  {
    int32_t range;
    int32_t sign;

    range = 0;
    sign = 1;
    //handling space, tab, newline, form feed and carriage return
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\r')
    str++;
    //handling negative numbers
    if (*str == '-')
      sign = -1;
    if (*str == '-' || *str == '+')
      str++;
    while (*str >= '0' && *str <= '9')
    {
      range = range * 10 + *str - '0';
      str++;
    }
    return (sign * range);
  }
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed8= cpu_ticks*system_clock;

//profiling for my ftoa
  initialize_counter();
  counter_start();
  void reverse(char *str, int len)
  {
  	int i=0, j=len-1, temp;
  	while (i<j)
  	{
  		temp = str[i];
  		str[i] = str[j];
  		str[j] = temp;
  		i++; j--;
  	}
  }

  // Converts a given integer x to string str[]. d is the number
  // of digits required in output. If d is more than the number
  // of digits in x, then 0s are added at the beginning.
  int intToStr(int x, char str[], int d)
  {
  	int i = 0;
  	while (x)
  	{
  		str[i++] = (x%10) + '0';
  		x = x/10;
  	}

  	// If number of digits required is more, then
  	// add 0s at the beginning
  	while (i < d)
  		str[i++] = '0';

  	reverse(str, i);
  	str[i] = '\0';
  	return i;
  }

  // Converts a floating point number to string.
  void ftoa(float n, char *res, int afterpoint)
  {
  	// Extract integer part
  	int ipart = (int)n;

  	// Extract floating part
  	float fpart = n - (float)ipart;

  	// convert integer part to string
  	int i = intToStr(ipart, res, 0);

  	// check for display option after point
  	if (afterpoint != 0)
  	{
  		res[i] = '.'; // add dot

  		// Get the value of fraction part upto given no.
  		// of points after dot. The third parameter is needed
  		// to handle cases like 233.007
  		fpart = fpart * pow(10, afterpoint);

  		intToStr((int)fpart, res + i + 1, afterpoint);
  	}
  }

  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed9= cpu_ticks*system_clock;

//profiling for logger
  initialize_counter();
  counter_start();
  char string1[] = "Testing123,Serial Print Test, no params";
  char string2[] = "This is an integer number: ";
  float number2 = 200;
  char string3[] = "This is an integer number: ";
  float number3 = 4096;
  char string4[] = "This is an integer number: ";
  float number4 = 123456;
  char string5[] = "This is a floating point number: ";
  float number5 = 1543.321;
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
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed10= cpu_ticks*system_clock;

//profiling for circular buffer
  initialize_counter();
  counter_start();
  UART0_init();
  uint8_t i,j,data,full,empty,l;
  int addrem;
  l=5;
  mem_allocate(l);
  struc_ptr->length = l;
  struc_ptr->buffer = buff_ptr;
  struc_ptr->head = buff_ptr;
  struc_ptr->tail = buff_ptr;

  uint8_t string1[] = "Hey UART! This is the Circular buffer talking! But one character at a time";


  for(i=0;i<strlen(string1);++i)
  {
  	add_item(string1[i]);
    if (buff_full()==1)
    {
    	continue;
	}

  for(j=0;j<struc_ptr->length;++j)
  {
  	send_char(remove_item());
    if (buff_empty()==1)
    {
    	break;
	}
  }
  }
  void mem_free();
  counter_stop();
  cpu_ticks = TPM0->CNT;
  time_elapsed11= cpu_ticks*system_clock;

#endif


}

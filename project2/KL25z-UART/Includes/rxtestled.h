#ifndef __RXTESTLED_H_
#define __RXTESTLED_H_

void UART0_init(void);
void delayin(int n);
void LED_in(void);
void LED_set(char value);
void send_char(char c);
void UART0_IRQHandler();

#endif

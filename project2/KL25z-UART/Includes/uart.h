//header file for UART
#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_
void UART0_init(void);
void send_char(char c);
void send_string(char s[]);
void delayMs(int n);

#endif

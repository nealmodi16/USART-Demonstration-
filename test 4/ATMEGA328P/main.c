#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define BAUD  9600UL
#define BRC   ((F_CPU / (16*BAUD)) - 1)
 
char RXbyte,c,n;
char str[5];
void USART_Init(void)
{
   UBRR0 = BRC;
   UCSR0B = (1<<TXEN0)|(1<<RXEN0);
   UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);  
}
void USART_Transmit( unsigned char data )
{
   while ( !( UCSR0A & (1<<UDRE0)) ) ;  /* Wait for empty transmit buffer */
   UDR0 = data;                         /* Put data into buffer, sends the data */
}
int main(void)
{
	int i=0;
   USART_Init();
	while(1)
	{
	 while ( !(UCSR0A & (1<<RXC0)) );  	 
		str[i]= UDR0;
		n=UDR0;
		if(n =='\n')
					{
						str[i]='\0';
						break ;
					}
			else{i++;} 
	}
   do{
			c=str[h];
			USART_Transmit(c);
			_delay_ms(100);
			h++;
	}while(str[h]!='\0');
}
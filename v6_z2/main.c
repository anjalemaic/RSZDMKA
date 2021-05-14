#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include "../usart/usart.h"

int main() {

	char tekst[64];
	int duzina;
	usartInit(9600);

	while(1) {

		usartPutString("Unesite string:\r\n ");
		while(!usartAvailable());
		_delay_ms(100);

		usartGetString(tekst);

		for (duzina=0; tekst[duzina] != '\0'; duzina++);
		for (int i=0; i < duzina; i++) {

			if(tekst[i] >= 'a' && tekst[i] <= 'z')
				tekst[i] += 'A' - 'a';
		}
		usartPutString_P(PSTR("Kapitalizovan tekst: "));
		usartPutString(tekst);
		usartPutString_P(PSTR("\r\n"));
	}
	return 0;
}

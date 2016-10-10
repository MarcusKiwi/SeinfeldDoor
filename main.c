#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include <serial.h>
#include <sr04.h>

#define STATUS_LED 5
#define JQ6500_BUSY 7

void main() {

	// sr04
	uint8_t time;
	struct sr04_conf conf;
	sr04_init(&conf,&DDRC,&PINC,&PORTC,1,0,PRESCALE_1024);

	// jq6500
	DDRD = 0;
	PORTD = 0;
	serial_init();

	// led
	DDRC |= (1<<STATUS_LED);
	PORTC &= ~(1<<STATUS_LED);

	// loop
	while(1) {

		_delay_ms(80);
		time=sr04_read(&conf);

		//serial_tx_chr(time);

		if((time>0)&&(time<9)) {
			PORTC |= (1<<STATUS_LED);
			// next track
			serial_tx_chr(0x7E);
			serial_tx_chr(0x02);
			serial_tx_chr(0x01);
			serial_tx_chr(0xEF);
			// allow time for music to start
			_delay_ms(500);
			// wait for music to end
			while((PIND & (1<<JQ6500_BUSY))!=0);
			// wait 2 secs
			_delay_ms(2000);
			PORTC &= ~(1<<STATUS_LED);
		}
	}
}

/*
 * AtCmdWrapper.c
 *
 * Created: 26-12-2016 07:39:14 PM
 *  Author: K8
 */ 
 #include "AtCmdWrapper.h"
 #include "delay.h"
 
 //uint16_t timeout = FONA_DEFAULT_TIMEOUT_MS;
 
 uint16_t readline(uint16_t timeout, uint8_t multiline) 
  {
	 uint16_t temp;
	 uint16_t replyidx = 0;

	 while (timeout--) {
		 if (replyidx >= 254) {
			 //DEBUG_PRINTLN(F("SPACE"));
			 break;
		 }
		 while (usart_read_wait(&usart_instance_one, &temp) == 0)
		 {
			 if (temp == '\r')
			 { 
				  continue;
			 }
			 if (temp == 0xA)
			 {
				 if(replyidx == 0)
				 {
					  continue;
				 }
				 if (!multiline)
				 {
					 timeout = 0;
					 break;
				 }
			 }
			 replybuffer[replyidx] = temp;
			 //while (usart_write_wait(&usart_instance_two, temp) != STATUS_OK) {}
			 replyidx++;
		 }
		 
		 if (timeout == 0) {
			 //DEBUG_PRINTLN(F("TIMEOUT"));
			 break;
		 }
		 delay_ms(1);
	 }
	 replybuffer[replyidx] = 0;  // null term
	 printf("given value is %s\r\n", replybuffer);
	 //puts(replybuffer);
	 return replyidx;
 }
 
 
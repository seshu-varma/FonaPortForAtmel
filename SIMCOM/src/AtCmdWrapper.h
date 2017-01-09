/*
 * AtCmdWrapper.h
 *
 * Created: 26-12-2016 07:38:18 PM
 *  Author: K8
 */ 
 #include <compiler.h>
 #include <status_codes.h>
 #include "sim_usart.h"

#ifndef ATCMDWRAPPER_H_
#define ATCMDWRAPPER_H_

#define FONA_DEFAULT_TIMEOUT_MS 1000
uint8_t replybuffer[255];


//function prototypes

uint16_t readline(uint16_t timeout, uint8_t multiline);




#endif /* ATCMDWRAPPER_H_ */


#include "asf.h"
#include "sim_usart.h"
#include "AtCmdWrapper.h"


#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{

	system_init();
	/*Initialize the delay driver*/
	delay_init();
	sim_usart_init();
	uint8_t string[] = "ATE0\r\n";
	uint8_t string1[] = "ATI\r\n";
	usart_write_buffer_wait(&usart_instance_one, string, sizeof(string));
	delay_ms(100);
	
	//! [main_loop]
	while (true) {
		usart_write_buffer_wait(&usart_instance_one, string1, sizeof(string));
		readline(5000, 0);
		delay_s(2);
		
	}

}

#ifdef __cplusplus
}
#endif

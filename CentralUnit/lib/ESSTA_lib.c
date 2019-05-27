#include "ESSTA_lib.h"

struct room_struct rooms[MAX_ROOMS] = {0,0,{0,0},{0,0},{0,0,0}};

void init_rooms(){
	uint8_t i = 0;
	for(i=0;i<MAX_ROOMS;i++){
		rooms[i].id=-1;
		rooms[i].eco=0;
		rooms[i].temperature.value=0.0;
		rooms[i].temperature.format='?';
		rooms[i].humidity.value=0.0;
		rooms[i].humidity.format='?';
		rooms[i].net_par.response = false;
		rooms[i].net_par.resend = 0;
		rooms[i].net_par.error = false;
	}
}

void log_room(struct room_struct my_room){
	char tmp[16];
	LCD_UsrLog("\r\n-----------------------");
	memset(tmp, '\0', 16);
	sprintf(tmp, "\r\n Id:%d", my_room.id);
	LCD_UsrLog(tmp);

	memset(tmp, '\0', 16);
	sprintf(tmp, "\r\n eco:%d", my_room.eco);
	LCD_UsrLog(tmp);

	memset(tmp, '\0', 16);
	sprintf(tmp, "\r\n Temp:%2.2f %c", my_room.temperature.value, my_room.temperature.format);
	LCD_UsrLog(tmp);

	memset(tmp, '\0', 16);
	sprintf(tmp, "\r\n Hum:%2.2f %c", my_room.humidity.value, my_room.humidity.format);
	LCD_UsrLog(tmp);

}

void print_rooms(){
	uint8_t i = 0;
	for(i=0; i<MAX_ROOMS; i++){
		log_room(rooms[i]);
	}
}

void send_char(char c) {
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TC) == RESET);	// wait finished
	USART_SendData(EVAL_COM1, (uint8_t) c);
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TC) == RESET);	// wait finished
}

void send_string(char* str) {
	uint8_t i = 0;
	#ifdef DEBUG_LOG
		LCD_UsrLog("\r\nSend: ");
		LCD_UsrLog(str);
	#endif
	while (str[i] != '\0') {
		send_char(str[i++]);
	}
}

void ESSTA_init(){
	send_string("ESSTA System running\n\0");
	init_rooms();
	graphic_init();
}
#ifndef ESSTA_LIB_H
#define ESSTA_LIB_H

#include "ee.h"
#include "ee_irq.h"

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "lcd_log.h"

#include "ESSTA_definitions.h"
#include "ESSTA_graphic.h"

//----------------------
void init_rooms();
void log_room(struct room_struct my_room);
void print_rooms();

void send_char(char c);
void send_string(char* str);

void ESSTA_init();
void ESSTA_send_node_request(uint8_t id);
void ESSTA_compute_house_status();

#endif //ESSTA_LIB_H

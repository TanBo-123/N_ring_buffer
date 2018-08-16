/**
 ****************************************************************************************
 *
 * @file ring_buffer.h
 *
 * @brief Ring buffer API.
 *
 * Copyright (C) 2012 Dialog Semiconductor.
 * This computer program includes Confidential, Proprietary Information
 * of Dialog Semiconductor. All Rights Reserved.
 *
 * <bluetooth.support@diasemi.com> and contributors.
 *
 ****************************************************************************************
 */
#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H


#include <stdint.h>
#include <stdbool.h>

#define   Uart1_RX_Index       1
#define   Uart2_RX_Index       0
#define   BUFFER_SIZE          500 //队列大小
#define   ring_buf_num         2  //循环队列数
//const uint16_t BUFFER_SIZE = 500;  
//const uint8_t ring_buf_num = 2;  
extern volatile uint16_t buffer_count[ring_buf_num];

bool buffer_is_empty(uint8_t num);

bool buffer_is_full(uint8_t num);

void buffer_put_byte(uint8_t byte,uint8_t num);

int buffer_get_byte(uint8_t *byte,uint8_t num);

void buffer_get_Nbyte(uint8_t *byte,uint8_t buff_num,uint8_t data_num);
#endif // _RING_BUFFER_H

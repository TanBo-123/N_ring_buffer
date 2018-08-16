#include <stdint.h>
#include <stdbool.h>
#include "ring_buffer.h"

uint8_t buffer[ring_buf_num][BUFFER_SIZE]={0};
volatile uint16_t buffer_count[ring_buf_num] = {0};
uint16_t buffer_head[ring_buf_num] = {0};
uint16_t buffer_tail[ring_buf_num] = {0};

bool buffer_is_empty(uint8_t num)
{
    return buffer_count[num] == 0;
}

bool buffer_is_full(uint8_t num)
{
    return buffer_count[num] == BUFFER_SIZE;
}

void buffer_put_byte(uint8_t byte,uint8_t num)
{
    if(!buffer_is_full(num))
    {
        buffer[num][buffer_head[num]] = byte;
        buffer_head[num] = (buffer_head[num] + 1) % BUFFER_SIZE;
        buffer_count[num] += 1;
    }
}

int buffer_get_byte(uint8_t *byte,uint8_t num)
{
    int status = -1; // failure
    
    if(!buffer_is_empty(num))
    {
        *byte = buffer[num][buffer_tail[num]];
				buffer[num][buffer_tail[num]] = 0;
        buffer_tail[num] = (buffer_tail[num] + 1) % BUFFER_SIZE;
        buffer_count[num] -= 1;
        
        status = 0; // success
    }
    return status;
}

void buffer_get_Nbyte(uint8_t *byte,uint8_t buff_num,uint8_t data_num)
{
			for(uint8_t i=0;i<data_num;i++)
				buffer_get_byte(&byte[i],buff_num);
}

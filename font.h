#ifndef _FONT_H_
#define _FONT_H_

#include <stdint.h>

extern code uint8_t font[][5];
uint8_t* font_base(uint8_t ch);

#endif // _FONT_H_
#ifndef _HCMS_200X_H_
#define _HCMS_200X_H_

#include <stc15.h>
#include <intrins.h>

#include <stdint.h>

sbit HCMS_COL1 = P1^0;
sbit HCMS_COL2 = P3^7;
sbit HCMS_COL3 = P3^6;
sbit HCMS_COL4 = P3^3;
sbit HCMS_COL5 = P3^2;
sbit HCMS_DATA = P1^1;
sbit HCMS_CLK  = P1^2;

void hcms_gpio_init();
void hcms_clear();
void hcms_display_string(uint8_t* str);
void hcms_display_string_scroll(uint8_t* str, uint8_t len);

#endif // _HCMS_200X_H_
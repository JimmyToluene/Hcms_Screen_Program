#include "hcms200x.h"
#include "font.h"

static void hcms_clk_delay();
static void hcms_push_7bit(uint8_t x);
static void hcms_col_delay();
static void hcms_scroll_delay();

void hcms_gpio_init()
{
	// P1.0 OD
	P1M0 |= (1 << 0); 
	P1M1 |= (1 << 0);
	
	// P3.7..4 OD
	P3M0 |= (1 << 7) | (1 << 6) | (1 << 3) | (1 << 2); 
	P3M1 |= (1 << 7) | (1 << 6) | (1 << 3) | (1 << 2);
	
	// P1.1..2 BIDIR
	P1M0 &= ~((1 << 1) | (1 << 2));
	P1M1 &= ~((1 << 1) | (1 << 2));
}

void hcms_clear()
{
	uint16_t i;
	
	HCMS_CLK = 1;
	HCMS_DATA = 0;
	
	for (i = 0; i < 28; ++i)
	{
		hcms_clk_delay();
		HCMS_CLK = 0;
		hcms_clk_delay();
		HCMS_CLK = 1;
	}
}

// Length of str is 4, no termination
void hcms_display_string(uint8_t* str)
{	
	hcms_push_7bit(font[str[3] - 32][0]);
	hcms_push_7bit(font[str[2] - 32][0]);
	hcms_push_7bit(font[str[1] - 32][0]);
	hcms_push_7bit(font[str[0] - 32][0]);
	HCMS_COL1 = 0;
	hcms_col_delay();
	HCMS_COL1 = 1;
	
	hcms_push_7bit(font[str[3] - 32][1]);
	hcms_push_7bit(font[str[2] - 32][1]);
	hcms_push_7bit(font[str[1] - 32][1]);
	hcms_push_7bit(font[str[0] - 32][1]);
	HCMS_COL2 = 0;
	hcms_col_delay();
	HCMS_COL2 = 1;
	
	hcms_push_7bit(font[str[3] - 32][2]);
	hcms_push_7bit(font[str[2] - 32][2]);
	hcms_push_7bit(font[str[1] - 32][2]);
	hcms_push_7bit(font[str[0] - 32][2]);
	HCMS_COL3 = 0;
	hcms_col_delay();
	HCMS_COL3 = 1;
	
	hcms_push_7bit(font[str[3] - 32][3]);
	hcms_push_7bit(font[str[2] - 32][3]);
	hcms_push_7bit(font[str[1] - 32][3]);
	hcms_push_7bit(font[str[0] - 32][3]);
	HCMS_COL4 = 0;
	hcms_col_delay();
	HCMS_COL4 = 1;
	
	hcms_push_7bit(font[str[3] - 32][4]);
	hcms_push_7bit(font[str[2] - 32][4]);
	hcms_push_7bit(font[str[1] - 32][4]);
	hcms_push_7bit(font[str[0] - 32][4]);
	HCMS_COL5 = 0;
	hcms_col_delay();
	HCMS_COL5 = 1;
}

void hcms_display_string_scroll(uint8_t* str, uint8_t len)
{
	uint8_t i;
	uint32_t j;
	
	for (i = 0; i < len - 4; ++i)
	{
		for (j = 0; j < 150; ++j)
			hcms_display_string(str);
		++str;
	}

}

// MSB is ignored
static void hcms_push_7bit(uint8_t x)
{
	uint8_t i;
	
	HCMS_CLK = 1;
	
	for (i = 0; i < 7; ++i)
	{
		HCMS_DATA = x & (1 << 6);
		hcms_clk_delay();
		HCMS_CLK = 0;
		hcms_clk_delay();
		HCMS_CLK = 1;
		x <<= 1;
	}
}

static void hcms_col_delay()
{
	unsigned char i, j;

	i = 18;
	j = 2;
	do
	{
		while (--j);
	} while (--i);
}

static void hcms_clk_delay()
{
	unsigned char i;

	_nop_();
	i = 6;
	while (--i);
}


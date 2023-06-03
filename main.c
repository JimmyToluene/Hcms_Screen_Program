#include "hcms200x.h"

#include <stc15.h>
#include <intrins.h>

#include <stdint.h>
#include <string.h>

void main()
{
	code uint8_t str[] = "    JimmyToluene is the father    ";
	hcms_gpio_init();
	hcms_clear();
	
	while (1)
	{
		hcms_display_string_scroll(str, strlen(str));
	}
}




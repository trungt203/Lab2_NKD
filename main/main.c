#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "ssd1306.h"
#include "font8x8_basic.h"

#define tag "SSD1306"

void app_main(void)
{
	SSD1306_t dev;
	int center, top, bottom;
	char lineChar[20];

    ESP_LOGI(tag, "INTERFACE is i2c");
	ESP_LOGI(tag, "CONFIG_SDA_GPIO=%d",CONFIG_SDA_GPIO);
	ESP_LOGI(tag, "CONFIG_SCL_GPIO=%d",CONFIG_SCL_GPIO);
	ESP_LOGI(tag, "CONFIG_RESET_GPIO=%d",CONFIG_RESET_GPIO);
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);

    ESP_LOGI(tag, "Panel is 128x64");
	ssd1306_init(&dev, 128, 64);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
    top = 2;
	center = 3;
	bottom = 8;
	ssd1306_display_text(&dev, 0, "21521860", 8, false);
	// ssd1306_display_text(&dev, 1, "--------------", 14, false);
	// ssd1306_display_text(&dev, 2, "--------------",14, false);
	ssd1306_display_text(&dev, 3, "21522727", 8, false);

    vTaskDelay(3000 / portTICK_PERIOD_MS);
	


}
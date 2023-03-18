#include "clima_tft.h"
#include "FT62XXTouchScreen.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"
#include <SPI.h>

#define DISPLAY_WIDTH  480
#define DISPLAY_HEIGHT 320
#define NUMBER_BACK  0x31EB

namespace esphome {
    namespace clima_tft: public Component {

        void clima_tft::setup() {
            ESP_LOGCONFIG(TAG, "Setting up Touchscreen...");
            _tft = TFT_eSPI();
            _background = TFT_eSprite(&_tft);
            _home_screen = TFT_eSprite(&_tft);
            _touchScreen = FT62XXTouchScreen(DISPLAY_HEIGHT, PIN_SDA, PIN_SCL);

            _tft.init();
            _tft.setRotation(3);
            _tft.fillScreen(TFT_BLACK);

            _background.createSprite(DISPLAY_WIDTH, DISPLAY_HEIGHT);
            _background.setSwapBytes(false);
            _home_screen->createSprite(DISPLAY_WIDTH, DISPLAY_HEIGHT);
            _home_screen->setSwapBytes(true);
            _home_screen->setTextColor(TFT_WHITE, NUMBER_BACK);

        }

        void clima_tft::update() {

        }
        
        void clima_tft::loop() {

        }

        void clima_tft::dump_config() {

        }

    }
}
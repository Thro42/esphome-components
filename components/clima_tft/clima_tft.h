#pragma once

#include "esphome/core/component.h"
#include "TFT_eSPI/TFT_eSPI.h"

namespace esphome {
    namespace clima_tft {
        class clima_tft
        {
        private:
            TFT_eSPI _tft;
            TFT_eSprite _background;
            TFT_eSprite _home_screen;
            FT62XXTouchScreen _touchScreen;
            /* data */
        public:
            void setup() override;
            void update() override;
            void loop() override;
            void dump_config() override;

        };
        
    }
}
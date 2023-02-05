//
// Created by lkapi on 05.02.2023.
//

#ifndef RAYGAME_RESIZEHELPER_H
#define RAYGAME_RESIZEHELPER_H

#include <raylib.h>
#include <string>

namespace UI {

    class ResizeHelper {
    public:
        /**
         * function that gets the screen resolution and returns it.
         *
         * @return screen resolution.
         */
        static Vector2 GetScreenResolution() {
            Vector2 screenResolution;
            screenResolution.x = GetScreenWidth();
            screenResolution.y = GetScreenHeight();
            return screenResolution;
        }

        /**
         * function that gets the center position for message.
         *
         * @return center position for message.
         */
        static Vector2 getCenterForMessage(int width, int height, std::string message) {
            return { static_cast<float>(width / 2 - MeasureText(message.c_str(), 20) / 2), static_cast<float>(height / 2 - 20 / 2) };
        }

        /**
         * function that gets the center position for image.
         *
         * @return center position for image.
         */
        static Vector2 getCenterForImage(int width, int height, Image image) {
            return { static_cast<float>(width/2 - image.width/2), static_cast<float>(height/2 - image.height/2) };
        }
    };

} // UI

#endif //RAYGAME_RESIZEHELPER_H

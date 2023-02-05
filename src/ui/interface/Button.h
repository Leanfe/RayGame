#pragma once
#include <map>
#include <string>
#include "raylib.h"


#ifndef RAYGAME_BUTTON_H
#define RAYGAME_BUTTON_H

namespace UI {

// Button.h

    /** Class for buttons with CSS styling support */
    class Button {
    public:
        /** Constructor that takes parameters to display the button and handle clicks */
        Button(const char *text, int fontSize, int x, int y, int width, int height);

        /** Method to apply CSS styles to the button */
        void applyStyles(const std::map<std::string, std::string>& styles);

        /** Method to handle clicks on the button */
        bool handleClick() const;

        /** Method to draw the button */
        void draw();

    private:
        const char *text;
        int fontSize;
        int x;
        int y;
        int width;
        int height;
        Color textColor;
        Color backgroundColor;
    };

} // UI

#endif //RAYGAME_BUTTON_H

//
// Created by lkapi on 05.02.2023.
//

#include <sstream>

#include "Button.h"

namespace UI {
    // StyledButton.cpp

    /**
     *  takes a string input as an argument and returns the corresponding hexadecimal value as an integer.
     * @param input string.
     * @return corresponding hexadecimal value as an integer
     */
    int strToHex(const std::string& input) {
        int result;
        std::stringstream ss;
        ss << std::hex << input;
        ss >> result;
        return result;
    }

    Button::Button(const char *text, int fontSize, int x, int y, int width, int height)
            : text(text), fontSize(fontSize), x(x), y(y), width(width), height(height), textColor(BLACK), backgroundColor(GRAY) {}

    void Button::applyStyles(const std::map<std::string, std::string>& styles)
    {
        for (const auto &style : styles) {
            if (style.first == "color") {
                textColor = GetColor(strToHex(style.second));
            }
            else if (style.first == "background-color") {
                backgroundColor = GetColor(strToHex(style.second));
            }
        }
    }

    bool Button::handleClick() const
    {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, { static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height) })) {
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                return true;
            }
        }
        return false;
    }

    void Button::draw()
    {
        DrawRectangle(x, y, width, height, backgroundColor);
        DrawText(text, x + width / 2 - MeasureText(text, fontSize) / 2, y + height / 2 - fontSize / 2, fontSize, textColor);
    }

} // UI
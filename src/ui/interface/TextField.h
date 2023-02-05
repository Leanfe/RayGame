//
// Created by lkapi on 05.02.2023.
//

#ifndef RAYGAME_TEXTFIELD_H
#define RAYGAME_TEXTFIELD_H

#include <iostream>
#include <raylib.h>
#include <string>

namespace UI {

    class TextInputField {
    private:
        Rectangle bounds;
        std::string text;
        Color color;
        bool active;

    public:
        TextInputField(Rectangle bounds, Color color)
                : bounds(bounds), color(color), active(false), text("") {}

        void Update() {
            if (CheckCollisionPointRec(GetMousePosition(), bounds)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    active = true;
                }
            } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                active = false;
            }

            if (active) {
                int key = GetKeyPressed();
                if (key >= 32) {
                    text += (char)key;
                }
                if (key == KEY_BACKSPACE && text.length() > 0) {
                    text.pop_back();
                }
            }
        }

        void Draw() {
            DrawRectangleRec(bounds, color);
            if (active) {
                DrawRectangleLines(bounds.x, bounds.y, bounds.width, bounds.height,
                                   RED);
            }
            DrawText(text.c_str(), bounds.x + 5, bounds.y + 5, 20, BLACK);
        }

        void AddChangeListener(void (*listener)(std::string)) {
            if (IsKeyPressed(KEY_ENTER)) {
                listener(text);
            }
        }
    };

    void OnTextChange(const std::string& text) {
        std::cout << "Text changed: " << text << std::endl;
    }

} // UI

#endif //RAYGAME_TEXTFIELD_H

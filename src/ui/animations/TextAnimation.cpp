//
// Created by lkapi on 05.02.2023.
//

#include "TextAnimation.h"

TextAnimation::TextAnimation(const char *text, int fontSize, int x, int y, Color color, int duration)
        : text(text), fontSize(fontSize), x(x), y(y), color(color), duration(duration) {}

void TextAnimation::play()
{
    int startTime = GetTime();
    int currentTime = 0;
    float transparency = 1.0f;
    while (currentTime < duration) {
        currentTime = GetTime() - startTime;
        transparency = 1.0f - (float)currentTime / (float)duration;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(text, x, y, fontSize, Fade(color, transparency));
        EndDrawing();
    }
}

void TextAnimation::stop()
{
    // NONE.
}
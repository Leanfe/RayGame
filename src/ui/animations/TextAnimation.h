//
// Created by lkapi on 05.02.2023.
//

#ifndef RAYGAME_TEXTANIMATION_H
#define RAYGAME_TEXTANIMATION_H

#pragma once
#include "Animation.h"
#include "raylib.h"

/**
 * Class for text animations.
 */
class TextAnimation : public Animation
{
public:
    /**
     *
     * @param text A string representing the text to be displayed.
     * @param fontSize The font size of the text.
     * @param x The x-coordinate of the text's position on the screen.
     * @param y The y-coordinate of the text's position on the screen.
     * @param color The color of the text.
     * @param duration The length of the animations in milliseconds.
     */
    TextAnimation(const char *text, int fontSize, int x, int y, Color color, int duration);

    /**
     *  Method to play the animation.
     */
    void play() override;
    /**
     * Method to stop the animation.
     */
    void stop() override;

private:
    const char *text;
    int fontSize;
    int x;
    int y;
    Color color;
    int duration;
};

#endif //RAYGAME_TEXTANIMATION_H

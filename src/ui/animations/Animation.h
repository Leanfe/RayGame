//
// Created by lkapi on 05.02.2023.
//

#ifndef RAYGAME_ANIMATION_H
#define RAYGAME_ANIMATION_H

#pragma once

// Base class for animations
class Animation
{
public:
    /**
     *  Pure virtual function to play the animation.
     */
    virtual void play() = 0;
    /**
     * Pure virtual function to stop the animation
     */
    virtual void stop() = 0;
};

#endif //RAYGAME_ANIMATION_H

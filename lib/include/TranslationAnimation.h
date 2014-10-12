/* 
 * File:   TranslationAnimation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:02
 */

#ifndef _TRANSLATIONANIMATION_H
#define	_TRANSLATIONANIMATION_H

#include "TransformationAnimation.h"


class TranslationAnimation : public TransformationAnimation{

public:

    TranslationAnimation(std::string title, float x, float y);
    TranslationAnimation(std::string title, float duration, float x, float y);
    virtual ~TranslationAnimation();

    void setDistance(float x, float y);
    void play();

private:

    float dX;
    float dY;
    float startX;
    float startY;

    virtual void doNextStep();
};

#endif	/* _TRANSLATIONANIMATION_H */


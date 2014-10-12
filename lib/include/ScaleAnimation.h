/* 
 * File:   ScaleAnimation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:01
 */

#ifndef _SCALEANIMATION_H
#define	_SCALEANIMATION_H

#include "TransformationAnimation.h"


class ScaleAnimation : public TransformationAnimation{

public:

    ScaleAnimation(std::string title, float x, float y);
    ScaleAnimation(std::string title, float duration, float x, float y);
    virtual ~ScaleAnimation();

    void setFinalScale(float x, float y);
    void play();

private:

    float scaleX;
    float scaleY;
    float startX;
    float startY;

    virtual void doNextStep();
};

#endif	/* _SCALEANIMATION_H */


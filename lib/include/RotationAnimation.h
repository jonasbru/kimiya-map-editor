/* 
 * File:   RotationAnimation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:01
 */

#ifndef _ROTATIONANIMATION_H
#define	_ROTATIONANIMATION_H

#include "TransformationAnimation.h"


class RotationAnimation : public TransformationAnimation {

public:

    RotationAnimation(std::string title);
    RotationAnimation(std::string title, float duration);
    RotationAnimation(std::string title, float duration, float angle);
    RotationAnimation(const RotationAnimation& orig);
    virtual ~RotationAnimation();

    void setAngle(float angle);
    void play();
    
private:

    float angle;
    float startAngle;

    void doNextStep();

};

#endif	/* _ROTATIONANIMATION_H */


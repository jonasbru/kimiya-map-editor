/* 
 * File:   OpacityAnimation.h
 * Author: arnaudboeglin
 *
 * Created on July 23, 2009, 11:03 PM
 */

#ifndef _OPACITYANIMATION_H
#define	_OPACITYANIMATION_H

#include "EffectAnimation.h"


class OpacityAnimation : public EffectAnimation {

public:

    OpacityAnimation(std::string title);
    OpacityAnimation(std::string title, float duration);
    OpacityAnimation(std::string title, float duration, float finalOpacity);
    OpacityAnimation(const OpacityAnimation& orig);
    virtual ~OpacityAnimation();

    void setFinalOpacity(float finalOpacity);

    void play();
    
private:

    float finalOpacity;
    float startOpacity;

    void doNextStep();

};

#endif	/* _OPACITYANIMATION_H */


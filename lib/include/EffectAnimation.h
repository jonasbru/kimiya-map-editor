/* 
 * File:   EffectAnimation.h
 * Author: arnaudboeglin
 *
 * Created on July 23, 2009, 11:03 PM
 */

#ifndef _EFFECTANIMATION_H
#define	_EFFECTANIMATION_H

#include "Animation.h"


class EffectAnimation : public Animation {
    
public:

    EffectAnimation(std::string title);
    EffectAnimation(std::string title, float duration);
    EffectAnimation(const EffectAnimation& orig);
    virtual ~EffectAnimation();

private:

};

#endif	/* _EFFECTANIMATION_H */


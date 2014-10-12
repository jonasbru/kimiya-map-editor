/* 
 * File:   TransformationAnimation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:00
 */

#ifndef _TRANSFORMATIONANIMATION_H
#define	_TRANSFORMATIONANIMATION_H

#include "Animation.h"


class TransformationAnimation : public Animation {

public:

    TransformationAnimation(std::string title);
    TransformationAnimation(std::string title, float duration);
    TransformationAnimation(const TransformationAnimation& orig);
    virtual ~TransformationAnimation() = 0;
    
private:

};

#endif	/* _TRANSFORMATIONANIMATION_H */


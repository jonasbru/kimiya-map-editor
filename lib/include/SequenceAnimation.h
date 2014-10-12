/* 
 * File:   SequenceAnimation.h
 * Author: arnaudboeglin
 *
 * Created on July 20, 2009, 1:01 AM
 */

#ifndef _SEQUENCEANIMATION_H
#define	_SEQUENCEANIMATION_H

#include "Animation.h"
#include "Sprite.h"

#include <vector>

class SequenceAnimation : public Animation {
public:

    SequenceAnimation(std::string title);
    SequenceAnimation(std::string title, float duration);
    SequenceAnimation(const SequenceAnimation& orig);
    virtual ~SequenceAnimation();
    
    void addTexture(Texture2D *tex);
    void insertTexture(Texture2D *tex, int pos);
    void removeTexture(Texture2D *tex);
    void removeTexture(int pos);

private:

    std::vector<Texture2D*> textures;

    virtual void doNextStep();

};

#endif	/* _SEQUENCEANIMATION_H */


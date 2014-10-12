/* 
 * File:   RelativeNode.h
 * Author: jonas
 *
 * Created on 21 juillet 2009, 15:45
 */

#ifndef _RELATIVENODE_H
#define	_RELATIVENODE_H

#include "DrawableNode.h"


class RelativeNode : DrawableNode{

public:
    
    RelativeNode();
    RelativeNode(const RelativeNode& orig);
    virtual ~RelativeNode() = 0;

private:

};

#endif	/* _RELATIVENODE_H */


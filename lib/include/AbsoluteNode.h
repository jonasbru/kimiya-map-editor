/* 
 * File:   AbsoluteNode.h
 * Author: jonas
 *
 * Created on 21 juillet 2009, 15:45
 */

#ifndef _ABSOLUTENODE_H
#define	_ABSOLUTENODE_H

#include "DrawableNode.h"


class AbsoluteNode : public DrawableNode {

public:

    AbsoluteNode();
    AbsoluteNode(const AbsoluteNode& orig);
    virtual ~AbsoluteNode() = 0;

private:


};

#endif	/* _ABSOLUTENODE_H */


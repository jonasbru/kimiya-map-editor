/*
 * File:   Layer.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:03
 */

#ifndef _PLAN_H
#define	_PLAN_H

#include <vector>

#include "Tile.h"

namespace ml {

    class Plan {
    public:

        Plan();
        Plan(const ml::Plan& orig);
        virtual ~Plan();

        int getStartZ();
        void setStartZ(int startZ);

        ml::Tile* getTile(int i);
        void addTile(ml::Tile *tile);
        ml::Tile* removeTile(ml::Tile *tile);
        int getTilesNumber();

    private:

        int startZ;

        std::vector<ml::Tile*> tiles;

    };

}

#endif	/* _LAYER_H */


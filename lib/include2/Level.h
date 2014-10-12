/*
 * File:   Level.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#ifndef _LEVEL_H
#define	_LEVEL_H

#include <vector>

#include "Plan.h"

namespace ml {

    class Level {
    public:

        Level();
        Level(const ml::Level& orig);
        virtual ~Level();

        int getStartZ();
        void setStartZ(int startZ);

        ml::Plan* getLayer(int i);
        void addLayer(ml::Plan *layer);
        ml::Plan* removeLayer(ml::Plan *layer);
        int getLayersNumber();

    private:

        int startZ;

        std::vector<ml::Plan*> layers;

    };

}
#endif	/* _LEVEL_H */


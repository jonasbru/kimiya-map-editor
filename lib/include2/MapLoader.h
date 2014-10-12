/*
 * File:   MapLoader.h
 * Author: arnaudboeglin
 *
 * Created on August 5, 2009, 8:22 PM
 */

#ifndef _MAPLOADER_H
#define	_MAPLOADER_H

#include <string>
#include <tinyxml.h>

#include "Map.h"

namespace ml {

    class MapLoader {
    public:

        MapLoader();
        MapLoader(std::string mapFile);
        MapLoader(const MapLoader& orig);
        virtual ~MapLoader();

        TiXmlDocument getDocument();
        void setDocument(TiXmlDocument t);

        ml::Map* load(float x, float y, float w, float h);
        ml::Map* loadPartAt(float x, float y);
        ml::Map* loadAll();

    private:

        std::string mapFile;

        float partWidth;
        float partHeight;
        float mapWidth;
        float mapHeight;

        inline void loadHeader();

        TiXmlDocument document;

    };

}

#endif	/* _MAPLOADER_H */


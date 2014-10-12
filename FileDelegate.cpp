/* 
 * File:   FileDelegate.cpp
 * Author: jonas
 * 
 * Created on 13 novembre 2009, 19:10
 */
#include <iostream>
#include <sstream>

#include "lib/include/Layer.h"
#include "lib/include/Sprite.h"

#include "lib/include2/Map.h"
#include "lib/include2/MapLoader.h"

#include "FileDelegate.h"
#include "Director.h"



FileDelegate::FileDelegate() {
}

FileDelegate::FileDelegate(const FileDelegate& orig) {
}

FileDelegate::~FileDelegate() {
}

void FileDelegate::loadAll(std::string filePath) {
//"/home/jonas/Bureau/testMap2.xml"
    ml::MapLoader *ml = new ml::MapLoader(filePath);
    ml::Map *map = ml->loadAll();

    ke::Layer *res = new ke::Layer();
    ke::Layer *row;
    ke::Layer *level;
    ke::Layer *layer;
    ke::Sprite *sprite;

    res->setZIndex(0);

    for (int i = 0; i < map->getRowsNumber(); i++) {

        row = new ke::Layer();

        std::stringstream ss(map->getProperty("row_height"));
        float w;
        ss >> w;

        row->setZIndex((map->getRowsNumber() - map->getRow(i)->getNumber()) * w);

        res->add(row);

        for (int j = 0; j < map->getRow(i)->getPartsNumber(); j++) {

            for (int k = 0; k < map->getRow(i)->getPart(j)->getLevelsNumber(); k++) {

                level = new ke::Layer();

                level->setZIndex(map->getRow(i)->getPart(j)->getLevel(k)->getStartZ());

                row->add(level);

                for (int l = 0; l < map->getRow(i)->getPart(j)->getLevel(k)->getLayersNumber(); l++) {

                    layer = new ke::Layer();

                    layer->setZIndex(map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getStartZ());

                    level->add(layer);

                    for (int m = 0; m < map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTilesNumber(); m++) {
                        sprite = new ke::Sprite(map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getPath());

                        sprite->setPosition(map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getX(), map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getY());
                        sprite->setZIndex(map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getZ());
                        sprite->setHeight(map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getH());
                        sprite->setWidth(map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getW());

                        layer->add(sprite);
                    }
                }
            }
        }
    }

    ke::Director::getDirector()->getScene()->add(res);
    delete map;
    delete ml;
}
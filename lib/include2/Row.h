/*
 * File:   Row.h
 * Author: jonas
 *
 * Created on 13 novembre 2009, 23:17
 */

#ifndef _ROW_H
#define	_ROW_H

#include <string>

#include "Part.h"
#include "Map.h"

namespace ml {

    class Map;

    class Row {
    public:
        Row();
        Row(const ml::Row& orig);
        virtual ~Row();

        int getNumber();
        void setNumber(int number);

        ml::Map* getParent();
        void setParent(ml::Map *parent);

        ml::Part* getPart(int i);
        ml::Part* getPartByX(float X);
        ml::Part* getPartByNumber(int number);
        void addPart(ml::Part *part);
        ml::Part* removePart(ml::Part *part);
        int getPartsNumber();

    private:

        std::vector<ml::Part*> parts;

        ml::Map* parent;

        int number;

    };

}

#endif	/* _ROW_H */


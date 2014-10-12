/*
 * File:   Map.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#ifndef _MAP_H
#define	_MAP_H

#include <string>
#include <map>

#include "Row.h"

namespace ml {

    class Row;

    class Map {
    public:

        Map();
        Map(const Map& orig);
        virtual ~Map();

        void setProperty(std::string key, std::string value);
        std::string getProperty(std::string key);

        ml::Row* getRow(int i);
        ml::Row* getRowByY(float Y);
        ml::Row* getRowByNumber(int number);
        void addRow(ml::Row *row);
        ml::Row* removeRow(ml::Row *row);
        int getRowsNumber();

    private:

        std::map<std::string, std::string> properties;
        std::vector<ml::Row*> rows;

    };

}

#endif	/* _MAP_H */


/*
 * File:   Part.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#ifndef _PART_H
#define	_PART_H

#include "Level.h"

namespace ml {

    class Part {
    public:

        Part();
        Part(const ml::Part& orig);
        virtual ~Part();

        int getNumber();
        void setNumber(int number);

        ml::Level* getLevel(int i);
        void addLevel(ml::Level *level);
        ml::Level* removeLevel(ml::Level *level);
        int getLevelsNumber();

    private:

        float number;

        std::vector<ml::Level*> levels;

    };

}

#endif	/* _PART_H */


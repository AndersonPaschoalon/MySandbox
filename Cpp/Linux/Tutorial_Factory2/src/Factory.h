/*
 * Factory.h
 *
 *  Created on: 14 de set de 2017
 *      Author: anderson
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
#include "Shape.h"
using namespace std;


class Factory {
  public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};

#endif /* FACTORY_H_ */
